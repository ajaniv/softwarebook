#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/schema/api.py - busxml schema api  module
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
.. module:: busxml.schema.api
   :synopsis: XML schema features access module


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'
"""
Synopsis:
    Parse xml schema files, return tree structure
    Input is read from in_xsd_file or, if "-" (dash) arg, from stdin.
    
Usage:
    python schema.py [ options ] <xsd_file>
     
Options:
    -h, --help               Display this help information.
    -l                       Logging level
 
    -a <namespaceabbrev>     Namespace abbreviation, e.g. "xsd:".
                             Default = 'xs:'.
     
    --no-process-includes    Do not process included XML Schema files.  By
                             default, generateDS.py will insert content
                             from files referenced by <include ... />
                             elements into the XML Schema to be processed.
"""


#
# Provide documentation, review code
#


import sys
import StringIO
import getopt
import logging
from xml.sax import make_parser

import busxml.schema.parser
from busxml.schema.parser import XschemaHandler



def _parse_file(file_name, parse_options):
     
    parser = make_parser()
 
    dh = XschemaHandler()

    parser.setContentHandler(dh)
    if file_name == '-':
        infile = sys.stdin
    else:
        infile = open(file_name, 'r')
    if parse_options.get('process_includes') is True:
        import process_includes
        outfile = StringIO.StringIO()
        process_includes.process_include_files(infile, outfile)
        outfile.seek(0)
        infile = outfile
    
    parser.parse(infile)
    root = dh.getRoot()
    root.annotate()
    return root

def _configure_parsing(options):
    global XsdNameSpace
    if options.get('logging_level') is not None:
        logging.basicConfig(level=logging.DEBUG, format='%(asctime)s %(levelname)s %(message)s')
        
    XsdNameSpace = options.get('name_space')
    busxml.schema.parser.set_type_constants(XsdNameSpace)

USAGE_TEXT = __doc__
def _usage():
    print USAGE_TEXT
    sys.exit(-1)

def _default_parse_options():
    defaults =  {
        'process_includes' : False,
        'name_space' : 'xsd:',
        }
    return defaults

def _process_cmd_line_options():
    options_dict = _default_parse_options()
    args = sys.argv[1:]
    try:
        options, args = getopt.getopt(args, 'ha:l:', 
                                      ['help', 'no-process-includes'])
                                       
    except getopt.GetoptError, exp: #@UnusedVariable
        _usage()
    for option in options:
        if option[0] == '-h' or option[0] == '--help':
            _usage()
        elif option[0] == '-a':
            options_dict['name_space'] = option[1]
        elif option[0] == '-l':
            options_dict['logging_level'] = option[1]
        
        elif option[0] == '--no-process-includes':
            options_dict['process_includes'] = False
            
     
    
    return (args[0], options_dict)

def parse(schema_file, parsing_options=_default_parse_options()):
    _configure_parsing(parsing_options)
    root_obj = _parse_file(schema_file, parsing_options)
    return root_obj
    
    
def parse_using_cmd_line():
    schema_file, options = _process_cmd_line_options()
    _configure_parsing(options)
    root_obj = _parse_file(schema_file, options)
    if root_obj is not None:
        pass
        
     
 



if __name__ == '__main__':
    parse_using_cmd_line()