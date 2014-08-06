#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# emf/core/xmlutil.py - emf core xmlutil module
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
.. module:: emf.core.xmlutil
   :synopsis: Eclipse Modeling Framework core xmlutil module

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

from busxml.core.classes import XMLProcessingRegistry
from busxml.core.classes import XMLTokenDescriptor
from busxml.core.classes import XMLProcessingRegistryEntry

from busxml.core.handlers import XMLObjectBuilder
from busxml.core.handlers import XMLObjectExporter

from emf.core.package  import EMFFactory



def create_instance(class_name):
    factory = EMFFactory.get_instance()
    return factory.create(class_name)

def input_conversion(value, input_format, output_format):
    pass

def output_conversion(value, input_format, output_format):
    pass

class FeatureDescriptor(object):
    def __init__(self, internal_name, external_name=None, new_instance_func=None, 
                 input_conversion_func=None, output_conversion_func=None, input_format=None, output_format=None):
        self.internal_name = internal_name
        self.external_name = external_name
        self.new_instance_func = new_instance_func
        self.input_conversion_func = input_conversion_func
        self.output_conversion_func = output_conversion_func
        self.input_format = input_format
        self.output_format = output_format
        


class EMFCoreSetup(object):
    _instance = None
    @staticmethod
    def get_instance():
        if EMFCoreSetup._instance is None:
            EMFCoreSetup._instance = EMFCoreSetup()
        return EMFCoreSetup._instance
            
     
    def initialize(self):
        for entry in  EMFCoreSetup.__dict__.items():
            if 'register' in entry[0] and type(entry[1]).__name__ ==  'function' :
                entry[1](self)
                
       
    def register_package(self):
        token_desc = XMLTokenDescriptor( 
                        name = 'EPackage',
                        namespace = 'ecore:',
                        attributes = { 
                            'nsURI' : FeatureDescriptor(internal_name='nsURI', 
                                            output_conversion_func=output_conversion,
                                            input_format="%s", output_format="%s"),
                            'nsPrefix' : FeatureDescriptor(internal_name='nsPrefix',
                                            output_conversion_func=output_conversion,
                                            input_format="%s", output_format="%s"),
                                                            
                                        },
                        children=['eClassifiers', 'eSubpackages'],
                        new_instance_function=create_instance)
        export_entry = XMLProcessingRegistryEntry(
                                                 handler=XMLObjectExporter(), 
                                                 descriptor=token_desc)
        build_entry = XMLProcessingRegistryEntry(handler=XMLObjectBuilder(), 
                                                 descriptor=token_desc)
        XMLProcessingRegistry.add_export_entry('EPackage', export_entry)
        XMLProcessingRegistry.add_build_entry('EPackage', build_entry)
        
    