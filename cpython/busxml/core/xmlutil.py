#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/core/xmlutil.py - busxml util  module
#
# This file is part of OndALear  collection of open source components
#
# This software is provided 'as-is', without any express or implied
# warranty.  In no event will the authors be held liable for any damages
# arising from the use of this software.
#
# Copyright (C) 2008 Amnon Janiv <amnon.janiv@ondalear.com>
#

# Initial version: 2008-02-01
# Author: Amnon Janiv <amnon.janiv@ondalear.com>

"""
..  module:: busxml.core.xmlutil
    :synopsis: Miscellaneous xml untilities module



.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'


from xml.dom.minidom import parseString
import re

triggerLineLength = 60 # Try to reformat lines longer than this

# Amount of indentation to use when reformatting:
indentStep = "  "

def makeXMLReadable(xml):
    xml = xml.toprettyxml("", "\n")
    # Remove trailing whitespace from each line:
    xml = "\n".join(
        [line.rstrip() for line in xml.split("\n")])
    # Remove all empty lines before opening '<':
    while xml.find("\n\n<") != -1:
        xml = xml.replace("\n\n<", "\n<")
    xml = parseString(xml).toprettyxml(indentStep, "")
    # Now all the xml lines are tight,
    # and we can insert spaces and line breaks:
    xml = addBreaks(xml)
    xml = reformatTooLongLines(xml)
    return xml

############# Support functions #############

addBreak = re.compile("\s{0,%d}<[a-zA-Z]" % len(indentStep))
def addBreaks(xml):
    '''Add line breaks to elements with
    zero or one indent level'''
    result = ""
    for line in xml.split("\n"):
        if addBreak.match(line):
            result += "\n"
        result += line + "\n"
    return result

def reformatTooLongLines(xml):
    result = ""
    for line in [line.rstrip() for line in xml.split("\n")]:
        if len(line) < triggerLineLength or not line.lstrip().startswith("<"):
            result += line + "\n"
        else:
            result += reformatLongLine(line) + "\n"
    return result

oneLiner = re.compile("([ ]*)(<\w+)(.*)>")
keyValuePair = re.compile('\w+="[^"]*?"')
def reformatLongLine(line):
    '''Reformat an xml tag to put each key-value
    element on a single indented line, for readability'''
    matchobj = oneLiner.match(line.rstrip())
    baseIndent = matchobj.group(1)
    result = baseIndent + matchobj.group(2) + "\n"
    indent = baseIndent + " " # Match indent level of tag
    for pair in keyValuePair.findall(matchobj.group(3)):
        result += indent + pair + "\n"
    result = result.rstrip() + " />"
    return result

DEFAULT_INDENT_AMOUNT=2
def indent(outfile, level, spaces=DEFAULT_INDENT_AMOUNT):
    buf = ' ' * spaces * level 
    outfile.write(buf)
     

def quote_xml(inStr):
    s1 = (isinstance(inStr, basestring) and inStr or
          '%s' % inStr)
    s1 = s1.replace('&', '&amp;')
    s1 = s1.replace('<', '&lt;')
    s1 = s1.replace('>', '&gt;')
    return s1

def quote_attrib(inStr):
    s1 = (isinstance(inStr, basestring) and inStr or
          '%s' % inStr)
    s1 = s1.replace('&', '&amp;')
    s1 = s1.replace('"', '&quot;')
    s1 = s1.replace('<', '&lt;')
    s1 = s1.replace('>', '&gt;')
    return s1

def quote_python(inStr):
    s1 = inStr
    if s1.find("'") == -1:
        if s1.find('\n') == -1:
            return "'%s'" % s1
        else:
            return "'''%s'''" % s1
    else:
        if s1.find('"') != -1:
            s1 = s1.replace('"', '\\"')
        if s1.find('\n') == -1:
            return '"%s"' % s1
        else:
            return '"""%s"""' % s1
