#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# emf/core/package.py - emf core package module
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
.. module:: emf.core.package
   :synopsis: Eclipse Modeling Framework core package module

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

import os

from busxml.core.classes import XMLProcessingRegistry
from busxml.core.classes import XMLTokenDescriptor
from busxml.core.classes import XMLProcessingRegistryEntry
import busxml.schema.api

from busxml.core.handlers import XMLObjectBuilder
from busxml.core.handlers import XMLObjectExporter
from emf.core.handlers import EMFObjectBuilder
from emf.core.handlers import EMFObjectExporter

from techutil.classes import GUID #@UnusedImport
from emf.core.classes import * #@UnusedWildImport



def create_instance(class_name):
    return EMFFactory.get_instance().create(class_name)
    
def create_from_string(feature_name, str_value, target_type):
    
    return EMFFactory.get_instance().create_from_string(feature_name, str_value, target_type)

    
def convert_to_string(feature_name, value, target_type):
    
    return EMFFactory.get_instance().convert_to_string(feature_name, value, target_type)

class AbstractPackageDescriptor(object):
     
    def __init__(self):
        self._factory = None
        self._package = None
        self._package_meta = None
        self._dependents = []
    
    def get_factory(self):
        return self._factory
    factory=property(get_factory)
    def get_package(self):
        return self._package
    package=property(get_package)
    def get_package_meta(self):
        return self._package_meta
    package_meta=property(get_package_meta)
    def get_dependents(self):
        return self._dependents
    dependents=property(get_dependents)
    def get_export_instructions(self, class_name):
        export_instructions = XMLProcessingRegistry.get_export_entry(class_name)
        if export_instructions is None:
            export_instructions = self.default_export_instructions(class_name)
        return export_instructions
   
    def get_parsing_instructions(self, token_name):
        parsing_instructions = XMLProcessingRegistry.get_build_entry(token_name)
        if parsing_instructions is None:
            parsing_instructions = self.default_parsing_instructions(token_name)
        return parsing_instructions       
    
    def default_export_instructions(self, class_name):
        if self.package_meta is None:
            raise ValueError, 'Class instance not properly initialized: %s' % self.__class__.__name__
        
        
        return  self.build_export_instructions(class_name)
    
    def default_parsing_instructions(self, token_name):
        if self.package_meta is None:
            raise ValueError, 'Class instance not properly initialized: %s' % self.__class__.__name__
        
        
        return  self.build_parsing_instructions(token_name)
         
    
    def build_export_instructions(self, class_name):
        
        export_instructions =  XMLProcessingRegistryEntry()
        export_instructions.handler =  self.get_object_exporter_desc(class_name)
        export_instructions.descriptor = self.get_token_desc(class_name)
        export_instructions.namespace = self.get_namespace()
        export_instructions.name = class_name
        return export_instructions
    
    def build_parsing_instructions(self, token_name):
        
        parsing_instructions =  XMLProcessingRegistryEntry()
        parsing_instructions.handler =  self.get_object_builder_desc(token_name)
        parsing_instructions.descriptor = self.get_token_desc(token_name)
        return parsing_instructions
    
    def get_namespace(self):
        pass
    
    def get_namespace_spec(self):
        pass
    def get_object_builder_desc(self, token_name):
        pass
    
    def get_object_exporter_desc(self, token_name):
        pass
    
    def get_token_desc(self, token_name):
         
        
        token_desc = XMLTokenDescriptor()
        token_desc.instance_meta_class = self.package_meta.get_element(token_name)
        if token_desc.instance_meta_class is None:
            raise KeyError, 'Descriptor not found for : %s' % token_name
        token_desc.root_meta_class = self.package_meta
        
        token_desc.create_from_string_function = self.create_from_string
        token_desc.create_instance_function = self.create_instance
        token_desc.convert_to_string_function = self.convert_to_string
        token_desc.element_lookup_function = self.element_lookup
        token_desc.package_desc = self
        token_desc.xmlns  = token_desc.xmlns  +  self._build_name_spaces() 
        return token_desc
        
    def _build_name_spaces(self):
        #TODO: revisit the approach, may need to go into dependents of dependents, etc
        filtered = dict()
        for ns in self.get_namespace_spec():
            filtered[ns] = True
        self._build_name_spaces_nested(self.dependents, filtered)
        filtered_keys = filtered.keys()
        filtered_keys.sort()
        return filtered_keys  
        
    def _build_name_spaces_nested(self, dependents, filtered):
         
        for dependent in dependents:
            depend_list = dependent.get_namespace_spec()
            for namespace in depend_list:
                filtered[namespace] = True
            self._build_name_spaces_nested(dependent.dependents, filtered)
        
        
        
    def _initialize(self):
        pass
    
    
    def create_instance(self, class_name):
        try:
            instance = self.get_factory().create(class_name)
        except  AttributeError :
            visited = {self.package.nsURI : True}
            instance = self._create_instance_from_dependents(self.dependents, class_name, visited )
        if instance is None:
            raise AttributeError, 'Invalid class name: %s' % class_name
        return instance
    
    def _create_instance_from_dependents(self, dependents, class_name, visited):
        instance = None
        for desc in  dependents:
            try:
                if not visited.has_key(desc.package.nsURI):
                    visited[desc.package.nsURI] = True 
                    instance = desc.factory.create(class_name)
                    if instance is not None:
                        break
            except AttributeError:
                instance = self._create_instance_from_dependents(desc.dependents, class_name, visited)
                if instance is not None:
                    break
            
        return instance
    def create_from_string(self, feature_name, str_value, target_type):
        return self.get_factory().create_from_string(feature_name, str_value, target_type)
    def convert_to_string(self, feature_name, value, target_type):
        return self.get_factory().convert_to_string(feature_name, value, target_type)
    
    #
    # TODO: review algorithm, make it more efficient (breadth first vs depth first)
    def dependents_lookup(self, element_name, descriptors):
        meta_item = None
        for package_desc in descriptors:
            meta_item = package_desc.element_lookup(element_name)
            if meta_item is   None:
                meta_item = self.dependents_lookup(element_name, package_desc.dependents)
            if meta_item is not None:
                break
        return meta_item
    def element_lookup(self, element_name):
        meta_item = self._package_meta.get_element(element_name)
        if (meta_item is None):
            meta_item = self.dependents_lookup(element_name, self.dependents)
        
        return meta_item
        
    def get_class_descriptor(self, class_name):
        pass
    def get_feature_descriptor(self, class_name, feature_name):
        pass

class EMFMetackageDescriptor(AbstractPackageDescriptor):
    def __init__(self):
        super(EMFMetackageDescriptor, self).__init__()
    def _initialize(self):
        super(EMFMetackageDescriptor, self)._initialize()
    def get_object_builder_desc(self, token_name):
        return EMFObjectBuilder.get_instance()
    
    def get_object_exporter_desc(self, token_name):
        return EMFObjectExporter.get_instance()

class SchemaMetaPackageDescriptor(AbstractPackageDescriptor):
    def __init__(self):
        super(SchemaMetaPackageDescriptor, self).__init__()
    def _initialize(self):
        super(SchemaMetaPackageDescriptor, self)._initialize()
    def get_object_builder_desc(self, token_name):
        return XMLObjectBuilder.get_instance()
    
    def get_object_exporter_desc(self, token_name):
        return XMLObjectExporter.get_instance()
    
    def get_namespace(self):
        return self._package.get_nsPrefix()
    def get_namespace_spec(self):
        return  ['%s="%s"' % (self._package.get_nsPrefix() , self._package.get_nsURI())]



class EMFFactory(EFactory):
    _instance = None
    def __init__(self):
        super(EMFFactory, self).__init__()
    def _initialize(self):
        pass
    @staticmethod
    def get_instance(): 
        if EMFFactory._instance == None:
            EMFFactory._instance = EMFFactory()
            EMFFactory._instance._initialize()
            
        return EMFFactory._instance
    
    
        
    
    def _post_object_creation(self, obj, pkg, do_initialize=False):
        obj.eClass = EClass.get_class_and_set_package(obj.class_name(), pkg)
        if do_initialize:
            obj.initialize()
    
    #
    # TODO: convert to fast lookup table, Review error handling logic
    #
    def create_from_string(self, feature_name, str_value, target_type):
        #TODO: convert to table driven
        result = None
        if 'string' in target_type:
            result = str_value
        elif 'int' in target_type:
            result = int(str_value)
        elif 'boolean' in target_type:
            value = str_value.upper()
            if value in 'TRUE':
                result = True
            elif value in 'FALSE':
                result = False
        elif 'float' in target_type:
            result = float(str_value)
        elif 'QName' in target_type:
            result = str_value
        elif 'EClassifier' in target_type:
            result = str_value
        else:
            result = self._dependents_create_from_string(self.dependents, feature_name, str_value, target_type)
        if result is None:
            raise ValueError, 'Cannot convert, feature_name: %s value: %s, type: %s' \
                 %(feature_name, str_value, target_type)
        return result
    
    def _create_from_string(self, feature_name, str_value, target_type):
        pass
    
    def  _dependents_create_from_string(self, dependents, feature_name, str_value, target_type):
        visited={ EMFPackage.get_instance.name : True }
        return self._create_from_string_nested(dependents, visited, feature_name, str_value, target_type)
        
    def _create_from_string_nested(self, dependents, visited, feature_name, str_value, target_type ):
        result = None
        for   dependent in dependents:
            if not visited.has_key(dependent.package.name):
                visited[dependent.package.name] = True
                result = dependent.factory._create_from_string(feature_name, str_value, target_type)
                if result is  None:
                    result =  self._create_from_string_nested(dependent.dependents, visited, feature_name, str_value, target_type)
                if result is not None:
                    break
                
        return result
                
        
    def convert_to_string(self, feature_name, value, target_type):
        
        result =  str(value)
        if  'boolean' in target_type:
            result = result.lower()
        return result
    
    
    def create_EObject(self, do_init=True):
        obj = EObject()
        self._post_object_creation(obj, do_init)
        return obj

    def create_EStringToStringMapEntry(self, do_init=True):
        obj = EStringToStringMapEntry()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EModelElement(self, do_init=True):
        obj = EModelElement()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EAnnotation(self, do_init=True):
        obj = EAnnotation()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_ENamedElement(self, do_init=True):
        obj = ENamedElement()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EEnumLiteral(self, do_init=True):
        obj = EEnumLiteral()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EClassifier(self, do_init=True):
        obj = EClassifier()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EClass(self, do_init=True):
        obj = EClass()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EGenericClass(self, do_init=True):
        obj = EGenericClass()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_ETypedElement(self, do_init=True):
        obj = ETypedElement()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EStructuralFeature(self, do_init=True):
        obj = EStructuralFeature()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EReference(self, do_init=True):
        obj = EReference()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EParameter(self, do_init=True):
        obj = EParameter()
        self._post_object_creation(obj, do_init)
        return obj
    
    
    def create_ETypeParameter(self, do_init=True):
        obj = ETypeParameter()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_ETypeArgument(self, do_init=True):
        obj = ETypeArgument()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EBoundType(self, do_init=True):
        obj = EBoundType()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EPackage(self, do_init=True):
        obj = EPackage()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EOperation(self, do_init=True):
        obj = EOperation()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EDataType(self, do_init=True):
        obj = EDataType()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EAttribute(self, do_init=True):
        obj = EAttribute()
        self._post_object_creation(obj, do_init)
        return obj
    
    def create_EEnum(self, do_init=True):
        obj = EEnum()
        self._post_object_creation(obj, do_init)
        return obj

#End Class EMFFactory Definition
class EMFPackage(EPackage):
    _instance = None
    ENAME = 'ecore'
    ENS_URI = 'http://www.eclipse.org/emf/2002/Ecore'
    ENS_PREFIX = 'ecore'
    def __init__(self):
        super(EMFPackage, self).__init__(EMFPackage.ENAME, EMFPackage.ENS_URI, EMFPackage.ENS_PREFIX)
        super(EMFPackage, self).set_eFactoryInstance(EMFFactory.get_instance())
    def _initialize(self):
        super(EMFPackage, self).initialize()
        self.factory = EMFFactory.get_instance()
        self.factory.package = self
    @staticmethod
    def get_instance(): 
        if EMFPackage._instance == None:
            EMFPackage._instance = EMFPackage()
            EMFPackage._instance._initialize()
            
        return EMFPackage._instance    
    
#End Class EMFPackage Definition
class EMFPackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(EMFPackageDescriptor, self).__init__()
        
    #
    #
    # TODO: move hard coded strings to configuration files
    #
    #
    
    def _initialize(self):
        super(EMFPackageDescriptor, self)._initialize()
        self._package = EMFPackage.get_instance()
        self._factory = EMFFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') +
                                                   '/schemas/xsd/Ecore.xsd')
    @staticmethod 
    def get_instance(): 
        if EMFPackageDescriptor._instance == None:
            EMFPackageDescriptor._instance = EMFPackageDescriptor()
            EMFPackageDescriptor._instance._initialize()
            
        return EMFPackageDescriptor._instance
def get_namespace(self):
        return 'ecore'
    