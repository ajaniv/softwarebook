#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/core/core.py - busxml core  module
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
.. module:: core

The  busxml.core.core  module defines xml core classes and operations
required for import/export and related event handling

Sample usage :
  >>> from busxml.core.core import AbstractParserHelper
  >>> from busxml.core.classes import SaxStackElement
  >>> from busxml.core.classes import AbstractSaxObjectHandler
  >>> from busxml.core.classes import SaxSelectorHandler


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'



 
import sys
import StringIO
 
 
from xml.dom import minidom
from xml.sax import handler, make_parser
 
from busxml.core import xmlutil

 



class AbstractParserHelper(object):
    def __init__(self, out_stream=None, namespace=None, name=None,  target=None):
        self.out_stream = out_stream
        self.namespace = namespace
       
        self.name = name
        self.target = target
        
    def get_output_stream(self): return self.out_stream
    def set_output_stream(self, out_stream): self.out_stream = out_stream
    
    def get_namespace(self): return self.namespace
    def set_namespace(self, namespace): self.namespace = namespace
    
    def get_name(self): return self.name
    def set_name(self, name): self.name = name
    
    def get_target(self): return self.target
    def set_target(self, target): self.target = target
    
    
    def export(self,  level=1):
        if self.get_target() is None:
            raise AttributeError, 'target is not set'
        xmlutil.indent(self.out_stream, level)
        self.out_stream.write('<%s%s ' % (self.namespace, self.name))
        #
        # TODO: need to better understand what is required for valid xml, define the approach
        if level == 1:
            self.out_stream.write('xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" ')
            pkg = self.get_target().get_eClass().get_ePackage()
            self.out_stream.write('xmlns:%s="%s"'  % (pkg.get_nsPrefix(), pkg.get_nsURI()) )
        self.export_attributes(level)
        self.out_stream.write('>\n')
        self.exportChildren(level + 1)
        self.out_stream.write('</%s%s>\n' % (self.namespace , self.name))
    def export_attributes(self, level):
        pass
       
    def _export_attributes(self, out_stream, target, attr_meta):
        for attr_name, attr_format, mapped_str in attr_meta:
            f =  getattr(target, "get_%s"%attr_name)
            attr = f()
            if (attr is not None):
                if mapped_str is not None: 
                    out_name = mapped_str
                else:
                    out_name = attr_name
                if attr_format.find('%s') > 0:
                    buf = attr_format % attr.__str__()
                elif attr_format.find('%d') > 0:
                    buf = attr_format % attr 
                out_stream.write (' %s=%s'  %  (out_name, buf))   
                    
    def exportChildren(self, level):
        pass
    
    def build(self, node):
        if self.get_target() is None:
            self.set_target(self.new_instance())
             
        attrs = node.attributes
        self.build_attributes(attrs)
        for child in node.childNodes:
            nodeName = child.nodeName.split(':')[-1]
            self.build_children(child, nodeName)
        return self.get_target()
    def build_attributes(self, attrs):
        pass
    def build_children(self, child_, nodeName_):
        pass
    def new_instance(self):
        pass

  

         
         
    
class SaxStackElement:
    def __init__(self, name='', obj=None):
        self.name = name
        self.obj = obj
        self.content = ''

 
class AbstractSaxObjectHandler(handler.ContentHandler):
    def __init__(self, helper=None):
        self.stack = []
        self.root = None
        self.helper = helper

    def getRoot(self):
        return self.root

    def setDocumentLocator(self, locator):
        self.locator = locator
    
    def get_helper(self):
        return self.helper
    def set_helper(self, new_helper):
        self.helper = new_helper
        
    def showError(self, msg):
        print '*** (showError):', msg
        sys.exit(-1)

    def startElement(self, name, attrs):
        pass

    def endElement(self, name):
        pass
        

    def characters(self, chrs, start, end):
        if len(self.stack) > 0:
            self.stack[-1].content += chrs[start:end]

    def reportError(self, mesg):
        locator = self.locator
        sys.stderr.write('Doc: %s  Line: %d  Column: %d\n' % \
            (locator.getSystemId(), locator.getLineNumber(), 
            locator.getColumnNumber() + 1))
        sys.stderr.write(mesg)
        sys.stderr.write('\n')
        sys.exit(-1)
        #raise RuntimeError

 


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


def parseSelect(inFileName):
    infile = file(inFileName, 'r')
    topElementName = None
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
        topElementName = topElementName.replace('-', '_').replace(':', '_')
        if topElementName not in globals():
            raise RuntimeError, 'no class for top element: %s' % topElementName
        topElement = globals()[topElementName]
        infile.seek(0)
        doc = minidom.parse(infile)
    finally:
        infile.close()
    rootNode = doc.childNodes[0]
    rootObj = topElement.factory()
    rootObj.build(rootNode)
    # Enable Python to collect the space used by the DOM.
    doc = None
    sys.stdout.write('<?xml version="1.0" ?>\n')
    rootObj.export(sys.stdout, 0)
    return rootObj


def saxParse(inFileName, document_handler):
    parser = make_parser()
    
    parser.setDocumentHandler(document_handler)
    parser.parse('file:%s' % inFileName)
    root = document_handler.getRoot()
    sys.stdout.write('<?xml version="1.0" ?>\n')
    root.export(sys.stdout, 0)
    return root


def saxParseString(inString, document_handler):
    parser = make_parser()
     
    parser.setDocumentHandler(document_handler)
    parser.feed(inString)
    parser.close()
    rootObj = document_handler.getRoot()
    #sys.stdout.write('<?xml version="1.0" ?>\n')
    #rootObj.export(sys.stdout, 0)
    return rootObj


def dom_parse_file(inFileName, helper):
    doc = minidom.parse(inFileName)
    rootNode = doc.documentElement
    rootObj = helper.build(rootNode)
    
    doc = None
    
    return rootObj


def dom_parse_string(inString, helper):
    doc = minidom.parseString(inString)
    rootNode = doc.documentElement
    rootObj = helper.build(rootNode)
    
    doc = None
    
    return rootObj


def parseLiteral(inFileName, helper):
    doc = minidom.parse(inFileName)
    rootNode = doc.documentElement
    rootObj = helper.factory()
    rootObj.build(rootNode)
    # Enable Python to collect the space used by the DOM.
    doc = None
    sys.stdout.write('from managed_object import *\n\n')
    sys.stdout.write('rootObj = ManagedObject(\n')
    rootObj.exportLiteral(sys.stdout, 0, name_="ManagedObject")
    sys.stdout.write(')\n')
    return rootObj

def export_to_string(exported_object, export_helper):
    output_stream = StringIO.StringIO()
    output_stream.write('<?xml version="1.0" encoding="UTF-8"?>\n')
    export_helper.set_target(exported_object)
    export_helper.set_output_stream(output_stream)
    export_helper.export()
    return output_stream.getvalue()


def export_to_file(fname, exported_object, export_helper):
    output_file = file(fname, 'w')
    output_file.write('<?xml version="1.0" encoding="UTF-8"?>\n')
    export_helper.set_target(exported_object)
    export_helper.set_output_stream(output_file)
    export_helper.export()
    output_file.close()
