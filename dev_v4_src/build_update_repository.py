"""
Script to build updated repository.

This script uses svn status for recognizing which package is updated.
So, user should not commit changes to packages before executing 
this script.
"""

import subprocess
import re
from qt_ifw_path import QT_IFW_PATH

# Qt installer framework path

def updated_package_list():
    """Return the list of updated packages"""

    cmd = 'git status -s'
    out = subprocess.check_output(cmd, shell=True)
    outstr = out.decode("utf-8")
    lines = outstr.split("\n")
    p = re.compile(r"(A |M|D) packages/(.+?)/.+")

    ret = set()

    for line in lines:
        ex = p.search(line)
        if ex is None: continue

        pname = ex.group(2)
        ret.add(pname)

    return list(ret)

updated_packages = updated_package_list()
print('Following packages are updated:')
print("\r\n".join(updated_packages))

repogen = QT_IFW_PATH + '\\bin\\repogen.exe'
cmd = repogen + ' -p packages --update --include ' + ','.join(updated_packages)+ ' ..\dev_v4'
subprocess.check_output(cmd)
