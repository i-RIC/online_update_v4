"""
Script to normalize Update.xml
"""

import xml.etree.ElementTree as ET

def normalize_xml(filename):
    dom = ET.parse(filename)
    dom.write(filename)

normalize_xml('dev_v4/Updates.xml')
normalize_xml('prod_v4/Updates.xml')
