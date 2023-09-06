import xml.etree.ElementTree as ET
import pathlib
import os
import re
import sys
import subprocess

# Edit the values here.
IRIC_PATH = os.environ["IRICMI_ROOT_PATH"]
MPI_BIN_PATH = "C:/Program Files/Microsoft MPI/Bin"
IRICMI_SERVER_PATH = IRIC_PATH + "/bin/iricmi_server.exe"

def get_solver_info(fname):
    tree = ET.parse(fname)
    root = tree.getroot()
    atts = root.attrib
    if not 'solverName' in atts:
        exit("Error: " + fname + " does not have solverName attribute.")
    if not 'solverVersion' in atts:
        exit("Error: " + fname + " does not have solverVersion attribute.")

    n = atts['solverName']
    v = atts['solverVersion']
    return (n, v)

def get_executable_args(fname):
    name, version = get_solver_info(fname)

    solver_path = IRIC_PATH + "/solvers"
    p = pathlib.Path(solver_path)
    for subp in p.iterdir():
        def_name = str(subp) + "\\definition.xml"
        if not os.path.exists(def_name):
            continue
        
        t = ET.parse(def_name)
        root = t.getroot()
        atts = root.attrib
        n = atts['name']
        v = atts['version']

        if not (name == n and version == v):
            continue

        exe = atts["executable"]
        full_exe = str(subp) + "\\" + exe
        if ".py" in full_exe:
            return ['python', '-u', full_exe]
        else:
            return [full_exe]
    
    exit("Error: solver with name " + name + " not found.")

class Model:
    def __init__(self, node):
        atts = node.attrib
        if not 'name' in atts:
            exit("Error: Model without name attribute exists.")
        if not 'nodes' in atts:
            exit("Error: Model '" + atts['name'] + "' do not have nodes attribute.")
        
        self.name = atts['name']
        self.nodes = int(atts['nodes'])

        self.exec_args = get_executable_args(self.name + "/project.xml")

        self.log = open(self.name + '/consoleLog.txt', 'w', encoding='utf-8')

def run_mi_project():
    tree = ET.parse("iricmi_project.xml")
    root = tree.getroot()

    models = list()
    rankmap = dict()

    min_rank = 1
    for model in root.iter("Model"):
        m = Model(model)
        models.append(m)

        for i in range(m.nodes):
            rankmap[min_rank + i] = m

        min_rank += m.nodes

    args = list()
    args.append(MPI_BIN_PATH + "\\mpiexec.exe")
    args.append('-l')

    # add iricmi_server
    args += ['-n', '1', IRICMI_SERVER_PATH]

    # add models
    for m in models:
        args += [':', '-n', str(m.nodes)] + m.exec_args
    
    proc = subprocess.Popen(args, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    p = re.compile(r"^\[([0-9]+)\](.*)$")

    server_log = open('server_consoleLog.txt', 'w', encoding='utf-8')

    while True:
        line = proc.stdout.readline()
        if line:
            try:
                l = line.decode('utf-8')

                print(l.strip())

                m = p.search(l)
                if m is None: continue

                groups = m.groups()
                rank = int(groups[0])
                msg = groups[1]
                if not rank == 0:
                    m = rankmap[rank]
                    m.log.write(msg)
                else:
                    server_log.write(msg)
            except:
                continue

        if not line and proc.poll() is not None:
            break

def run_iric_project():
    args = get_executable_args("project.xml")

    proc = subprocess.Popen(args, shell=True, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
    p = re.compile(r"^\[([0-9]+)\](.*)$")
    log = open('consoleLog.txt', 'w', encoding='utf-8')

    while True:
        line = proc.stdout.readline()
        if line:
            try:
                l = line.decode('utf-8')
                log.write(l)

                print(l.strip())
            except:
                continue

        if not line and proc.poll() is not None:
            break

if os.path.exists("iricmi_project.xml"):
    run_mi_project()

elif os.path.exists("project.xml"):
    run_iric_project()

else:
    print("iricmi_project.xml nor project.xml does not exists. Please execute iricmi_run in iricmi project folder or iRIC project folder.")
    exit()
