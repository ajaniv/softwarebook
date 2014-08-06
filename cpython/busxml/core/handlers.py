#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/core/handlers.py - busxml handlers  module
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
..  module:: busxml.core.handlers
    :synopsis: Business XML parsing event handling module


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'


import StringIO
from xml.dom import Node
from busxml.core.classes import XMLProcessingRegistry
from busxml.core import xmlutil

DEFAULT_XML_PARSING_CONFIG =   { }

_object_2_xml_attr_mapping_table = {'type' : 'xsi:type',
                            'eSuperTypes_attr' : 'eSuperTypes',
                            'guid': 'gUID'
                             
                            }

_otype_name_mapping_table = { 'eTypeParameters' : 'ETypeParameter',
                            'eGenericType' : 'ETypeParameter',
                            'eLiterals' : 'EEnumLiteral',
                            'eBounds' : 'EBoundType',
                            'eGenericSuperTypes' : 'EGenericClass',
                            'eTypeArguments' : 'ETypeArgument',
                            'contracts' : 'BusinessContract',
                            'clauses' : 'BusinessContractClause',
                            'attributes' : 'EStringToEJavaObjectMapEntry',
                            'contractSpec' : 'ContractSpec',
                            }

_type_name_mapping_table = {  
                            }



_schema_2_object_attr_mapping_table = \
    {
            'ManagedObject' : { 
                'gUID' : 'guid',
            },
            'BusinessContract' : {
                'lists' : 'busObjectLists'
            },
            'ContractSpec' : {
                'list' : 'parties'
            },
        }
_object_attr_2_schema_mapping_table = {
                                            'guid' : 'gUID'
                                            }

def _context_2_map(type_name, container_meta, meta_lookup_function):
    result = None
    
    current_meta = container_meta
    while current_meta is not None:
        mapping_dict = _type_name_mapping_table.get(current_meta.name)
        if mapping_dict is not None:
            result = mapping_dict.get(type_name)
            if result is not None:
                break
        if current_meta.base is not None:
            current_meta = meta_lookup_function(current_meta.base)
        else:
            break
    return result
         
        

def _map_type_name(type_name,  container_meta, meta_lookup_function):
    mapped = _context_2_map(type_name,  container_meta, meta_lookup_function )
    
    if mapped is None:
        if (type_name[0:1].islower()):
            mapped = type_name.capitalize()
        else:
            mapped =  type_name
    return mapped
    
def _object_attr_2_xml( attr_name):
        
        mapped = _object_2_xml_attr_mapping_table.get(attr_name)
        if mapped is None:
            return attr_name
        return mapped

def _schema_2_object_attr (type_name, meta_name):
    mapped = None
    class_map = _schema_2_object_attr_mapping_table.get(meta_name)
    if class_map is not None:
        mapped = class_map.get(type_name)
    if  mapped is  None:
        return type_name
    return mapped

def _object_attr_2_schema(type_name):
    mapped = _object_attr_2_schema_mapping_table.get(type_name)
    if mapped is None:
        return type_name
    return mapped

class AbstractXMLHelper(object):
    def __init__(self):
        self.config = None
        
    def set_config(self, config):
        self.config = config

class XMLObjectBuilder(AbstractXMLHelper):
    _instance = None
    def __init__(self):
        super(XMLObjectBuilder, self).__init__()
    
    @staticmethod
    def get_instance( ):
        if XMLObjectBuilder._instance is None:
            XMLObjectBuilder._instance = XMLObjectBuilder()
        return XMLObjectBuilder._instance
            
        
    @staticmethod
    def get_process_instructions(token_name):
        entry = XMLProcessingRegistry.get_build_entry(token_name)
        if entry is None:
            raise KeyError, 'Entry not found for token % ' % token_name 
        return entry.handler, entry.descriptor
    
    def create(self,  root_node, build_spec ):
         
        node_name = root_node.nodeName.split(':')[-1]
        context = []
        return self._create_and_inject_nested( root_node, node_name, 
                                               build_spec.instance_meta_class, build_spec, context)
        
    
    def _create_and_inject_nested(self,  node, type_name, target_meta, build_spec, context):
        mapped_meta = target_meta
        
       
        current_class_meta = None
        if len(context) > 0:
            current_class_name = context[-1]
            current_class_meta = build_spec.element_lookup_function(current_class_name)
        
        mapped_type_name = _map_type_name(type_name,  current_class_meta, build_spec.element_lookup_function)
        if mapped_type_name != type_name :
            mapped_meta = build_spec.element_lookup_function(mapped_type_name)
        target   = build_spec.create_instance_function(mapped_type_name)
        if object is None:
            raise ValueError,  "Unrecognized type: %s"  % type_name
        context.append(mapped_type_name)
        self._inject(target, node, mapped_meta, build_spec, context)
        context.pop()
        return target
         
          
    def _inject(self, target, node, target_meta, build_spec, context):
       
       
        self._inject_attributes(target, node.attributes, target_meta,  build_spec)
        self._inject_children(target, node.childNodes, target_meta, build_spec, context)
         
    
    def _inject_attributes(self, target, node_attributes, target_meta, build_spec):
        
        self._inject_attributes_nested(target, node_attributes, 
                                       target_meta, build_spec)
    
   
   
    
        
    def _inject_attributes_nested(self, target, node_attributes, target_meta, build_spec):
        for attr_meta_item in target_meta.attributeDefs.items():
            schema_attr_name = attr_meta_item[0]
            if '_attr' in schema_attr_name:
                #
                # TODO: patch to handle case were duplciate schema elements are introduced, one for
                # attribute, another for element
                schema_attr_name = schema_attr_name.split('_attr')[0]
            attr_desc = attr_meta_item[1]
            
            
            node_attr = node_attributes.get(schema_attr_name)
           
            if node_attr is not None:
                obj_attr_name = _schema_2_object_attr(schema_attr_name, target_meta.name)
                converted_value = build_spec.create_from_string_function(obj_attr_name, node_attr.value, 
                                                              attr_desc.data_type.split(':')[-1])
                target.set_feature(obj_attr_name , converted_value) 
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
        
    def get_node_map(self, child_nodes):
        child_map = dict()
        for child_node in child_nodes:
            if child_node.nodeType == Node.ELEMENT_NODE:
                name = child_node.nodeName.split(':')[-1]
                child_map[name] = child_node
        return child_map
    
    #
    # TODO: can add validation for optional vs mandatory
    #
        
    def _inject_children(self, target, child_nodes, target_meta, build_spec, context):
                                                       
        self._inject_nested(target, child_nodes, target_meta, build_spec, context)
        
    def _inject_nested(self, target, child_nodes, target_meta, build_spec, context):
        
        for child_node in child_nodes:
            if child_node.nodeType == Node.ELEMENT_NODE:
                child_meta = self.find_meta(child_node, target_meta.children)
                if child_meta is not None:
                    self._inject_child(target, child_node,  child_meta, build_spec, context)
                
        
        #Handle base class for target
        #TODO: can be made more efficient if keeping track of date nodes not traversed
        if  target_meta.base is not None:
                super_meta = build_spec.element_lookup_function(target_meta.base)
                if super_meta is not None:
                        self._inject_nested(target, child_nodes, super_meta, 
                                              build_spec, context)      
               
 
        
        
    
    def _inject_child(self, target, child_node, child_meta, build_spec, context):
        
        metadata = child_meta #@UnusedVariable
        #
        # TODO: better error checking
        #
        node_type = child_node.attributes.get('xsi:type')
        if node_type is not None:
            child_type_name = node_type.value.split(':')[-1]
            
        else:
            child_type_name = child_meta.type
        metadata = build_spec.element_lookup_function(child_type_name)
        child   = self._create_and_inject_nested(child_node, child_type_name, metadata, build_spec, context)
        
        
        if (child_meta.maxOccurs == 1):
            target.set_feature(_schema_2_object_attr(child_meta.name, target.class_name()), child)
        else:
            target.add_feature(_schema_2_object_attr(child_meta.name, target.class_name()), child)
        
    

class XMLObjectExporter(AbstractXMLHelper):
    _instance = None
    def __init__(self):
        super(XMLObjectExporter, self).__init__()
    
    @staticmethod
    def get_instance( ):
        if XMLObjectExporter._instance is None:
            XMLObjectExporter._instance = XMLObjectExporter()
        return XMLObjectExporter._instance
    
    @staticmethod
    def get_process_instructions(class_name):
        entry = XMLProcessingRegistry.get_export_entry(class_name)
        if entry is None:
            raise KeyError, 'Entry not found for class % ' % class_name 
        return entry.handler, entry.descriptor
        
  
    def export_root(self, target,  out_stream, name, namespace, export_spec,  level=-1 ):
        self.write_doc_header(out_stream)
        
        
        #TODO = get the name space from metadata
        self.export_object(target, out_stream, name,
                          namespace, export_spec.instance_meta_class, export_spec, level, False, export_spec.xmlns)
        
    #
    #TODO: explore getting rid of all formatting, to be done externallly, organize the methods, classes accordingly
    # 
        
    def export_object(self, target, out_stream, namespace, name, target_meta, descriptor, level, doType=True, namespaces=None):
        object_type= None
        if doType:
            object_type = target.eClass.ePackage.nsPrefix + ':' + target.class_name()
        
        self.write_object_header(out_stream, namespace, name, level, object_type)
        
         
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
        self.export_attributes_nested(target, out_stream,  target_meta, descriptor, dict()) 
     
    
    def export_attributes_nested(self, target, out_stream,  target_meta, descriptor, exported_attr):
        #first export the base classes attributes
        if  target_meta.base is not None:
            super_meta = descriptor.element_lookup_function(target_meta.base)
            if super_meta is not None:
                self.export_attributes_nested(target, out_stream,  super_meta, descriptor, exported_attr)
        
        for item in target_meta.attributeDefs.items():
            schema_attr_name = item[0]
            if '_attr' in schema_attr_name:
                #
                # TODO: patch to handle case were duplciate schema elements are introduced, one for
                # attribute, another for element
                schema_attr_name = schema_attr_name.split('_attr')[0]
            attr_meta = item[1]
            obj_attr_name = _schema_2_object_attr(schema_attr_name, target_meta.name)
            attr_value = target.get_feature(obj_attr_name)
            if attr_value is not None and not exported_attr.has_key(obj_attr_name):
                converted_value = descriptor.convert_to_string_function(obj_attr_name, attr_value, attr_meta.data_type)
                out_stream.write('%s="%s" ' % (_object_attr_2_xml(obj_attr_name), xmlutil.quote_attrib(converted_value)))
                exported_attr[obj_attr_name] = True
                
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
            #
            # TODO: this klude deals with duplicate attributes, elements.  This needs to be cleaned up
            if target_meta.attributeDefs.has_key(attr_name + '_attr'):
                continue
            child_list = target.get_feature_items(_schema_2_object_attr(attr_name, target_meta.name))
            if child_list is not None:
                for child in child_list:
                    child_instance_meta = descriptor.element_lookup_function(child.class_name())
                    self.export_object(child, out_stream, None, attr_name, child_instance_meta, descriptor, level)
                
    def write_doc_header(self, out_stream):
        out_stream.write('<?xml version="1.0" encoding="UTF-8"?>\n')
        
    def write_namespaces(self, out_stream, name_spaces, level):
        
        for name in name_spaces:
            xmlutil.indent(out_stream, level)
            out_stream.write('xmlns:%s\n' %name)
            
    def _default_namesspaces(self):
        
        #
        # TODO: figure out how to get this from the meta data, rather than hard coding it
        #
        return [ 
                'xmlns:xmi="http://www.omg.org/XMI"\n',
                'xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"\n',
                'xmlns:ecore="http://www.eclipse.org/emf/2002/Ecore"\n'
                ]
        
    def write_object_header(self, out_stream, namespace, name, level, object_type):
       
        xmlutil.indent(out_stream, level)
        #
        # Figure out a way to have the xmi:version obtained from meta data
        #
        if namespace is not None:
            out_stream.write('<%s:%s xmi:version="2.0"\n' % (namespace,  name))
        else:
            out_stream.write('<%s ' %    name)
        if object_type is not None:
            out_stream.write('xsi:type="%s" ' % object_type)
            
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

class ParsingHelperRegistry(object):
    _registry = dict()
    
    @staticmethod
    def put(key, value):
        ParsingHelperRegistry._registry[key] = value
    @staticmethod
    def get(key):
        return ParsingHelperRegistry._registry.get(key)
    
    @staticmethod
    def get_parsing_helper(key):
        fn = ParsingHelperRegistry.get(key)
        if fn is not None:
            return fn()
        return None
