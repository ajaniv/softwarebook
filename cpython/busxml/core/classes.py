#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/core/classes.py - busxml classes  module
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
..  module:: busxml.core.classes
    :synopsis: XML import/export class definitions module

The  busxml.core.classes  module defines classes supporting xml import, export, and parsing
operations.

Sample usage :
  >>> from busxml.core.classes import XMLProcessingRegistry
  >>> from busxml.core.classes import XMLTokenDescriptor
  >>> from busxml.core.classes import XMLProcessingRegistryEntry
  >>> from busxml.core.classes import SaxSelectorHandler


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'


from xml.sax import handler


class XMLProcessingRegistry(object):
    _build_registry = dict()
    _export_registry = dict()
    
    @staticmethod
    def add_build_entry(key, value):
        XMLProcessingRegistry._build_registry[key] = value
    @staticmethod
    def get_build_entry(key):
        return XMLProcessingRegistry._build_registry.get(key)
    @staticmethod
    def add_export_entry(key, value):
        XMLProcessingRegistry._export_registry[key] = value
    @staticmethod
    def get_export_entry(key):
        return XMLProcessingRegistry._export_registry.get(key)

class XMLTokenDescriptor:
    _instance = None
    def __init__(self):
        self.name = None
        self.namespace = None
        self.attributes = None
        self.children = None
        self.root_meta_class = None
        self.instance_meta_class = None
        self.create_instance_function = None
        self.create_from_string_function = None
        self.convert_to_string_function = None
        self.element_lookup_function = None
        self.package_desc = None
        #TODO: refactor the contribution of the base name spaces to make it more generic
        self.xmlns=['xmi="http://www.omg.org/XMI"', 
                    'xsi="http://www.w3.org/2001/XMLSchema-instance"',
  
                    ]
    
    @staticmethod
    def get_instance():
        if XMLTokenDescriptor._instance is None:
            XMLTokenDescriptor._instance = XMLTokenDescriptor()
        return XMLTokenDescriptor._instance
            
        
class XMLProcessingRegistryEntry(object):
    _instance = None
    def __init__(self, handler=None, descriptor=None):
        self.handler = handler
        self.descriptor = descriptor
        
    @staticmethod
    def get_instance():
        if XMLProcessingRegistryEntry._instance is None:
            XMLProcessingRegistryEntry._instance = XMLProcessingRegistryEntry()
        return XMLProcessingRegistryEntry._instance
    
    
#
# SAX handler used to determine the top level element.
#

class SaxSelectorHandler(handler.ContentHandler):
    def __init__(self):
        self.topElementName = None
    def getTopElementName(self):
        return self.topElementName
    def startElement(self, name, attrs):
        self.topElementName = name
        raise StopIteration
        
