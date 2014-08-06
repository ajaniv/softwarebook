#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/core/handlers.py - busxml schema  process_includes
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
.. module:: busxml.schema.process_includes
   :synopsis: XML schema include feature  module

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

"""
Synopsis:
    Recusively process the include elements in an XML Schema file.
    Produce a single file that contains all included content.
    Input is read either from a file or from stdin.
    Output is written either to a file or to stdout.
Usage:
    python process_includes.py [options] [ infile [ outfile ] ]
Options:
    -h, --help      Display this help message.
    -f, --force     Force.  If outfile exists, overwrite without asking.
Examples:
    python process_includes.py infile.xsd
    python process_includes.py infile.xsd outfile.xsd
    python process_includes.py infile.xsd > outfile.xsd
    cat infile.xsd | python process_includes.py > outfile.xsd
"""

#
# Imports

import sys
import os
import getopt
import re

#
# Try to import lxml first, and if that fails try ElementTree.
# lxml preserves namespace prefixes, but ElemenTree does not.
#
WhichElementTree = ''
try:
    from lxml import etree
    WhichElementTree = 'lxml'
except ImportError, e:
    pass
if WhichElementTree != 'lxml' or etree.LXML_VERSION[0] < 2:
    print '***'
    print '*** Error: Must install lxml (v. >= 2.0) or use "--no-process-includes".'
    print '***'
    raise RuntimeError, 'Must install lxml (v. >= 2.0) or use "--no-process-includes".'
#print WhichElementTree, etree


#
# Globals and constants

FORCE = False
NAMESPACE_PAT = re.compile(r'\{.*\}')


#
# Classes



#
# Functions


def process_includes(inpath, outpath):
    if inpath:
        infile = open(inpath, 'r')
    else:
        infile = sys.stdin
    if outpath:
        outfile = make_file(outpath)
    else:
        outfile = sys.stdout
    process_include_files(infile, outfile)
    if inpath:
        infile.close()
    if outpath:
        outfile.close()


def process_include_files(infile, outfile):
    doc = etree.parse(infile)
    root = doc.getroot()
    process_include_tree(root)
    doc.write(outfile)


def process_include_tree(root):
    idx = 0
    children = root.getchildren()
    while idx < len(children):
        child = children[idx]
        tag = child.tag
        if type(tag) == type(""):
            tag = NAMESPACE_PAT.sub("", tag)
        else:
            tag = None
        if tag == 'include' and 'schemaLocation' in child.attrib:
            root.remove(child)
            path = child.attrib['schemaLocation']
            if os.path.exists(path):
                doc = etree.parse(path)
                node = doc.getroot()
                process_include_tree(node)
                children1 = node.getchildren()
                for child1 in children1:
                    root.insert(idx, child1)
                    idx += 1
            else:
                msg = "Can't find include file %s.  Aborting." % (path, )
                raise IOError(msg)
        else:
            process_include_tree(child)
            idx += 1
        children = root.getchildren()


def make_file(outFileName):
    global FORCE
    outFile = None
    if (not FORCE) and os.path.exists(outFileName):
        reply = raw_input('File %s exists.  Overwrite? (y/n): ' % outFileName)
        if reply == 'y':
            outFile = open(outFileName, 'w')
    else:
        outFile = open(outFileName, 'w')
    return outFile


USAGE_TEXT = __doc__

def usage():
    print USAGE_TEXT
    sys.exit(1)


def main():
    global FORCE
    args = sys.argv[1:]
    try:
        opts, args = getopt.getopt(args, 'hf', ['help', 'force', ])
    except:
        usage()
    name = 'nobody' #@UnusedVariable
    for opt, val in opts: #@UnusedVariable
        if opt in ('-h', '--help'):
            usage()
        elif opt in ('-f', '--force'):
            FORCE = True
    if len(args) == 2:
        inpath = args[0]
        outpath = args[1]
    elif len(args) == 1:
        inpath = args[0]
        outpath = None
    elif len(args) == 0:
        inpath = None
        outpath = None
    else:
        usage()
    process_includes(inpath, outpath)


if __name__ == '__main__':
    #import pdb; pdb.set_trace()
    main()

