#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# emf/core/handlers.py - emf core handlers module
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
.. module:: emf.core.handlers
   :synopsis: Eclipse Modeling Framework core handlers module

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

import StringIO
from xml.dom import Node

from busxml.core import xmlutil

from busxml.core.handlers  import XMLObjectBuilder
from busxml.core.handlers  import XMLObjectExporter

_attr_name_mapping_table = {}

_type_name_mapping_table = {}

def _map_type_name(type_name):
    mapped = _type_name_mapping_table.get(type_name)
    if mapped is None:
            return type_name
    return mapped
    
def _map_attr_name( attr_name):
        
        mapped = _attr_name_mapping_table.get(attr_name)
        if mapped is None:
            return attr_name
        return mapped
    

class EMFObjectBuilder(XMLObjectBuilder):
    _instance = None
    def __init__(self):
        super(EMFObjectBuilder, self).__init__()
    
    @staticmethod
    def get_instance( ):
        if EMFObjectBuilder._instance is None:
            EMFObjectBuilder._instance = EMFObjectBuilder()
        return EMFObjectBuilder._instance
            
        
    def _create_and_inject_nested(self,  node, type_name, target_meta, build_spec):
        mapped_meta = target_meta
        mapped_type_name = _map_type_name(type_name)
        if mapped_type_name != type_name :
            mapped_meta = build_spec.element_lookup_function(mapped_type_name)
        target   = build_spec.create_instance_function(mapped_type_name)
        if object is None:
            raise ValueError,  "Unrecognized type: %s"  % type_name
        self._inject(target, node, mapped_meta, build_spec)
        return target
         
          
    def _inject(self, target, node, target_meta, build_spec):
       
       
        self._inject_attributes(target, node.attributes, target_meta,  build_spec)
        self._inject_children(target, node.childNodes, target_meta, build_spec)
         
    
    def _inject_attributes(self, target, node_attributes, target_meta, build_spec):
        
        self._inject_attributes_nested(target, node_attributes, 
                                       target_meta, build_spec)
    
   
   
    
        
    def _inject_attributes_nested(self, target, node_attributes, target_meta, build_spec):
        for attr_meta_item in target_meta.attributeDefs.items():
            attr_name = attr_meta_item[0]
            attr_desc = attr_meta_item[1]
            node_attr = node_attributes.get(_map_attr_name(attr_name))
            if node_attr is not None:
                converted_value = build_spec.create_from_string_function(attr_name, node_attr.value, 
                                                              attr_desc.data_type.split(':')[-1])
                target.set_feature(attr_name, converted_value) 
        if  target_meta.base is not None:
            super_meta = build_spec.element_lookup_function(target_meta.base)
            if super_meta is not None:
                self._inject_attributes_nested(target, node_attributes,  super_meta, build_spec)
                
    def find_meta(self, child_node, meta_classes):
        for child_meta in meta_classes:
            node_name = child_node.nodeName.split(':')[-1]
            if node_name == child_meta.name:
                return child_meta
        return None 
        
    def find_node(self, meta_node_name,  node_list):
        for node in node_list:
            node_name = node.nodeName.split(':')[-1]
            if node_name == meta_node_name:
                return node 
        return None
        
   
    
    #
    # TODO: can add validation for optional vs mandatory
    #
        
    def _inject_children(self, target, child_nodes, target_meta, build_spec):
                                                       
        self._inject_nested(target, child_nodes, target_meta, build_spec)
        
    def _inject_nested(self, target, child_nodes, target_meta, build_spec):
        
        for child_node in child_nodes:
            if child_node.nodeType == Node.ELEMENT_NODE:
                child_meta = self.find_meta(child_node, target_meta.children)
                if child_meta is not None:
                    self._inject_child(target, child_node,  child_meta, build_spec)
                
        
        #Handle base class for target
        #TODO: can be made more efficient if keeping track of date nodes not traversed
        if  target_meta.base is not None:
                super_meta = build_spec.element_lookup_function(target_meta.base)
                if super_meta is not None:
                        self._inject_nested(target, child_nodes, super_meta, 
                                              build_spec)      
               
 
        
        
    
    def _inject_child(self, target, child_node, child_meta, build_spec):
        
        metadata = child_meta
        #
        # TODO: better error checking
        #
        node_type = child_node.attributes.get('xsi:type')
        if node_type is not None:
            child_type_name = node_type.value.split(':')[-1]
            metadata = build_spec.element_lookup_function(child_type_name)
        else:
            child_type_name = child_meta.name
        child   = self._create_and_inject_nested(child_node, child_type_name, metadata, build_spec)
        
        
        target.add_feature(child_meta.name, child)
        
    

class EMFObjectExporter(XMLObjectExporter):
    _instance = None
    def __init__(self):
        super(XMLObjectExporter, self).__init__()
    
    @staticmethod
    def get_instance( ):
        if XMLObjectExporter._instance is None:
            XMLObjectExporter._instance = XMLObjectExporter()
        return XMLObjectExporter._instance
    
     
        
  
    def export_root(self, target,  out_stream, name, namespace, export_spec,  level=-1 ):
        self.write_doc_header(out_stream)
        
        
        #TODO = get the name space from metadata
        self.export_object(target, out_stream, name,
                          namespace, export_spec.instance_meta_class, export_spec, level, self._default_namesspaces())
        
    #
    #TODO: explore getting rid of all formatting, to be done externallly, organize the methods, classes accordingly
    # 
        
    def export_object(self, target, out_stream, namespace, name, target_meta, descriptor, level, namespaces=None):
        
        self.write_object_header(out_stream, namespace, name, level)
        
         
        if namespaces is not None:
             
            self.write_namespaces(out_stream, namespaces, level+1)
            xmlutil.indent(out_stream, level+1)
            
        
        self.export_attributes(target, out_stream, target_meta, descriptor, level)
        
        
        children_output_stream = StringIO.StringIO()
        
        self.export_object_body(target, children_output_stream, 
                               target_meta,
                               descriptor, level)
    
        self.write_object_trailer(out_stream, namespace, name, children_output_stream.getvalue(), level)
        
    def export_attributes(self, target, out_stream,  target_meta, descriptor,  level):
        #xmlutil.indent(out_stream, level)
        self.export_attributes_nested(target, out_stream,  target_meta, descriptor) 
     
    
    def export_attributes_nested(self, target, out_stream,  target_meta, descriptor):
        #first export the base classes attributes
        if  target_meta.base is not None:
            super_meta = descriptor.element_lookup_function(target_meta.base)
            if super_meta is not None:
                self.export_attributes_nested(target, out_stream,  super_meta, descriptor)
        
        for item in target_meta.attributeDefs.items():
            attr_name = item[0]
            attr_meta = item[1]
            attr_value = target.get_feature(attr_name)
            if attr_value is not None:
                converted_value = descriptor.convert_to_string_function(attr_name, attr_value, attr_meta.data_type)
                out_stream.write('%s="%s" ' % (_map_attr_name(attr_name), xmlutil.quote_attrib(converted_value)))
                
    def export_object_body(self, target, out_stream, target_meta, descriptor, level):
        if level >= 0:
            self.export_children(target, out_stream, target_meta, descriptor , level + 1)
        else:
            self.export_children(target, out_stream, target_meta, descriptor, level)
             
    def export_children(self,target, out_stream,  target_meta, descriptor,  level):
        #first export the base classes childre
        if  target_meta.base is not None:
            super_meta = descriptor.element_lookup_function(target_meta.base)
            if super_meta is not None:
                self.export_children(target, out_stream,  super_meta, descriptor, level)
        
        for child_meta in target_meta.children:
            attr_name = child_meta.name
            child_list = target.get_feature(attr_name)
            if child_list is not None:
                for child in child_list:
                    child_instance_meta = descriptor.element_lookup_function(child.class_name())
                    self.export_object(child, out_stream, None, attr_name, child_instance_meta, descriptor, level)
                
    def write_doc_header(self, out_stream):
        out_stream.write('<?xml version="1.0" encoding="UTF-8"?>\n')
        
    def write_namespaces(self, out_stream, name_spaces, level):
        
        for name in name_spaces:
            xmlutil.indent(out_stream, level)
            out_stream.write(name)
            
    def _default_namesspaces(self):
        
        #
        # TODO: figure out how to get this from the meta data, rather than hard coding it
        #
        return [ 
                'xmlns:xmi="http://www.omg.org/XMI"\n',
                'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"\n',
                'xmlns:ecore="http://www.eclipse.org/emf/2002/Ecore"\n'
                ]
        
    def write_object_header(self, out_stream, namespace, name, level):
       
        xmlutil.indent(out_stream, level)
        #
        # Figure out a way to have the xmi:version obtained from meta data
        #
        if namespace is not None:
            out_stream.write('<%s:%s xmi:version="2.0"\n' % (namespace,  name))
        else:
            out_stream.write('<%s ' %    name)
            
    def write_object_trailer(self, out_stream, namespace, name, children_xml, level):
        if len(children_xml) > 0:
            out_stream.write('>\n')
            out_stream.write(children_xml)
            xmlutil.indent(out_stream, level)
            if namespace is not None:
                out_stream.write('</%s:%s>\n' %  (namespace,  name))
            else:
                out_stream.write('</%s>\n'  %  name)
        else:
            out_stream.write('/>\n' )