"""
Script to copy release date and version from data/definition.xml to
meta/package.xml.
"""

import os
import re
import xml.etree.ElementTree as ET
from datetime import datetime

def copy_release_and_version(path):
    """
    Copy release date and version from data/definition.xml to
    meta/package.xml.
    """

    def_fname = path + '/data/definition.xml'
    print(def_fname)

    if not os.path.exists(def_fname):
        return

    tree = ET.parse(def_fname)
    atts = tree.getroot().attrib

    if 'release' in atts:
        release = atts['release']
    else:
        release = ''

    if 'version' in atts:
        version = atts['version']
    else:
        version = ''

    print('path:    ' + path)
    print('version: ' + version)
    print('release: ' + release)
    print('')

    package_fname = path + '/meta/package.xml'
    f = open(package_fname, 'r')
    package_c = f.read()
    f.close()

    if not version == '':
        var_frags = version.split(".")
        while (len(var_frags) < 3):
            var_frags.append('0')

        version = ".".join(var_frags)

        package_c = re.sub(
            r'<Version>.+</Version>',
            '<Version>' + version + '</Version>',
            package_c)
    if not release == '':
        p = re.compile(r"([0-9]+)\.([0-9]+)\.([0-9]+)")
        ex = p.fullmatch(release)
        if not ex is None:
            year  = int(ex.group(1))
            month = int(ex.group(2))
            day   = int(ex.group(3))
            rdate = datetime(year, month, day)
            release_str = rdate.strftime("%Y-%m-%d")
            package_c = re.sub(
                r'<ReleaseDate>.+</ReleaseDate>',
                '<ReleaseDate>' + release_str + '</ReleaseDate>',
                package_c)

    f = open(package_fname, 'w')
    f.write(package_c)
    f.close()

items = os.listdir('packages')
for item in items:
    copy_release_and_version('packages/' + item)
