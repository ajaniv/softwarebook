#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/mngobject/package.py - managed object package  module
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

.. module:: busobject.mngobject.package
   :synopsis: mngobject run-time meta-data module

The busobject.mngobject.package  module defines the  classes required to provide package
meta data run time information.

Sample usage :
  >>> from busobject.mngobject.package import ManagedObjectFactory
  >>> from busobject.mngobject.package import ManagedObjectPackage
  >>> from busobject.mngobject.package import ManagedObjectPackageDescriptor

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

import os #@UnusedImport

import emf.core.api #@UnusedImport
import busxml.schema.api

from emf.core.classes import EPackage
from emf.core.package import EMFFactory

from emf.core.package import SchemaMetaPackageDescriptor
from emf.core.package import EMFPackageDescriptor




from busobject.mngobject.classes import * #@UnusedWildImport

class ManagedObjectFactory(EMFFactory):
    _instance = None
    
    def __init__(self):
        super(ManagedObjectFactory, self).__init__()
    
    def create_ManagedObject(self, do_init=True):
        obj = ManagedObject()
        self._post_object_creation(obj, ManagedObjectPackage.get_instance(), do_init)
        return obj
    
    def create_ManagedObjectRef(self, do_init=True):
        obj = ManagedObjectRef()
        self._post_object_creation(obj, ManagedObjectPackage.get_instance(), do_init)
        return obj
    @staticmethod
    def get_instance():
        if ManagedObjectFactory._instance is None:
            ManagedObjectFactory._instance = ManagedObjectFactory()
        return ManagedObjectFactory._instance
    
    def create_from_string(self, feature_name, str_value, target_type):
        #TODO: convert to table driven
        result = self._create_from_string(feature_name, str_value, target_type)
             
        if result is None:
            result = super(ManagedObjectFactory, self).create_from_string(feature_name, str_value, target_type)
        return result
    def _create_from_string(self, feature_name, str_value, target_type):
        #TODO: convert to table driven
        result = None
         
        if '_Attribute' in target_type:
            type_name = target_type.split('_')[0]
            
            if 'GUID' in type_name:
                result = GUID.from_string(str_value)
            elif 'ManagedObjectRef' in type_name:
                result = ManagedObjectRef.from_string(str_value)
             
         
        return result
        
        
    
class ManagedObjectPackage(EPackage):
    ENAME = 'mngobject'
    ENS_URI = 'http:///com/ondalear/bus/mngobject.ecore'
    ENS_PREFIX = 'com.ondalear.bus.mngobject'
    _instance = None
    
    def __init__(self):
        super(ManagedObjectPackage, self).__init__(ManagedObjectPackage.ENAME, 
                                                   ManagedObjectPackage.ENS_URI, 
                                                   ManagedObjectPackage.ENS_PREFIX)
        super(ManagedObjectPackage, self).set_eFactoryInstance(ManagedObjectFactory.get_instance())
    
    def _initialize(self):
        super(ManagedObjectPackage, self).initialize()
        self.factory = ManagedObjectFactory.get_instance()
        self.factory.package = self
          
    @staticmethod
    def get_instance():
        if  ManagedObjectPackage._instance is None:
            ManagedObjectPackage._instance = ManagedObjectPackage()
            ManagedObjectPackage._instance._initialize()
        return ManagedObjectPackage._instance
    

class ManagedObjectPackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(ManagedObjectPackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(ManagedObjectPackageDescriptor, self)._initialize()
        self._dependents.append(EMFPackageDescriptor.get_instance())
        self._package = ManagedObjectPackage.get_instance()
        self._factory = ManagedObjectFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') 
                                                  + '/schemas/xsd/ManagedObjectXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if ManagedObjectPackageDescriptor._instance == None:
            ManagedObjectPackageDescriptor._instance = ManagedObjectPackageDescriptor()
            ManagedObjectPackageDescriptor._instance._initialize()
            
        return ManagedObjectPackageDescriptor._instance