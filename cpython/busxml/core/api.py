#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/core/api.py - business xml api module
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

.. module:: busxml.core.api
   :synopsis: Business XML core 'easy' feature access module


busxml.core.api module provides simplified access to features supported by the busxml.core package.
Key functions include to/from business object tree export/import
 

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

import StringIO

from xml.sax import  make_parser
from xml.dom import minidom

from busxml.core.classes import SaxSelectorHandler




#
# TODO: documentation review parameters
#


def create_object(root_node, parsing_instructions, ):
    return parsing_instructions.handler.create(root_node,
                                        parsing_instructions.descriptor)
    

def export_object(object, output_stream, export_instructions ):
    """Export a business object tree to an output stream
    with a given set of instructions
  
    :param object: Object graph root.
    :type object: BusinessContractWorkspace.
    :param output_stream: stream to which object graph will be exported
    :type output_stream: StringIO.StringIO
    :param parsing_instructions: details instruction for the export operation
    :type parsing_instructions: busxml.core.classes.XMLProcessingRegistryEntry
    

    """
    export_instructions.handler.export_root(object, output_stream, 
                                            export_instructions.namespace,
                                            export_instructions.name,
                                            export_instructions.descriptor,   level=0)
    
    
def get_root_node_name(inFileName):
    infile = file(inFileName, 'r')
    topElementName = None
    normalized_name = None 
    parser = make_parser()
    documentHandler = SaxSelectorHandler()
    parser.setContentHandler(documentHandler)
    try:
        try:
            parser.parse(infile)
        except StopIteration:
            topElementName = documentHandler.getTopElementName()
        if topElementName is None:
            raise RuntimeError, 'no top level element'
        normalized_name = topElementName.split(':')[-1]
        
    finally:
        infile.close()
    return normalized_name
    
   
def export_to_string(root, package_descriptor):
    
    """Export a business object tree to an XML stream
  
    :param root: Object graph root.
    :type root: BusinessContractWorkspace.
    :returns:  unicode -- xml representation of object tree.

    """
    
    #
    # TODO: improve error handling througout
    output_stream = StringIO.StringIO()
     
    instructions = package_descriptor.get_export_instructions(root.class_name())
        
    
    export_object(root, output_stream, instructions)
    return output_stream.getvalue()

def parse_file(file_name, package_descriptor, parser_type='minidom'):
    if parser_type == 'minidom':
        return parse_file_using_minidom(file_name, package_descriptor)

def parse_file_using_minidom(file_name, package_descriptor):
    
    root_node_name = get_root_node_name(file_name)
    instructions =  package_descriptor.get_parsing_instructions(root_node_name)
    
        
    doc = minidom.parse(file_name)
    
    root_obj =  create_object(doc.documentElement, instructions)
   
    
    doc = None
    
    return root_obj