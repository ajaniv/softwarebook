#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/core/package.py - business object package module
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

.. module:: busobject.core.package
   :synopsis: busobject.core package run-time meta-data module

The busobject.core.package  module defines base classes providing run-time meta-data information.

Sample usage :
  >>> from busobject.core.package import BusinessObjectCoreFactory
  >>> from busobject.core.package import BusinessObjectCorePackage
  >>> from busobject.core.package import BusinessObjectCorePackageDescriptor

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""


import os

import busxml.schema.api
import emf.core.api #@UnusedImport

from emf.core.classes import EPackage



from emf.core.package import SchemaMetaPackageDescriptor
from busobject.mngobject.package import ManagedObjectFactory
from busobject.mngobject.package import ManagedObjectPackageDescriptor

from busobject.core.classes import * #@UnusedWildImport


 




class BusinessObjectCoreFactory(ManagedObjectFactory):
    _instance = None
    
    def __init__(self):
        super(BusinessObjectCoreFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusinessObjectCoreFactory._instance is None:
            BusinessObjectCoreFactory._instance = BusinessObjectCoreFactory()
        return BusinessObjectCoreFactory._instance

    def create_EStringToEJavaObjectMapEntry(self, do_init=True):
        """
        Create an instance of EStringToEJavaObjectMapEntry.
        """
        obj = EStringToEJavaObjectMapEntry()
        self._post_object_creation(obj, BusinessObjectCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_BusinessObjectAssoc(self, do_init=True):
        """
        Create an instance of BusinessObjectAssoc.
        """
        obj = BusinessObjectAssoc()
        self._post_object_creation(obj, BusinessObjectCorePackage.get_instance(),do_init)
        
        return obj
            
    def create_BusinessObjectCategory(self, do_init=True):
        """
        Create an instance of BusinessObjectCategory.
        """
        obj = BusinessObjectCategory()
        self._post_object_creation(obj, BusinessObjectCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_BusinessObjectList(self, do_init=True):
        """
        Create an instance of BusinessObjectList.
        """
        obj = BusinessObjectList()
        self._post_object_creation(obj, BusinessObjectCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_BusinessObjectRef(self, do_init=True):
        """
        Create an instance of BusinessObjectRef.
        """
        obj = BusinessObjectRef()
        self._post_object_creation(obj, BusinessObjectCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_ObjectAnnotation(self, do_init=True):
        """
        Create an instance of ObjectAnnotation.
        """
        obj = ObjectAnnotation()
        self._post_object_creation(obj, BusinessObjectCorePackage.get_instance(), do_init)
        
        return obj

    
        
        
    
class BusinessObjectCorePackage(EPackage):
    ENAME = 'core'
    ENS_URI = 'http:///com/ondalear/bus/object/core.ecore'
    ENS_PREFIX = 'com.ondalear.bus.object.core'
    _instance = None
    
    def __init__(self):
        super(BusinessObjectCorePackage, self).__init__(BusinessObjectCorePackage.ENAME, 
                                                   BusinessObjectCorePackage.ENS_URI, 
                                                   BusinessObjectCorePackage.ENS_PREFIX)
        super(BusinessObjectCorePackage, self).set_eFactoryInstance(BusinessObjectCoreFactory.get_instance())
        
    def _initialize(self):
        super(BusinessObjectCorePackage, self).initialize()
        self.factory = BusinessObjectCoreFactory.get_instance()
        self.factory.package = self       
    @staticmethod
    def get_instance():
        if  BusinessObjectCorePackage._instance is None:
            BusinessObjectCorePackage._instance = BusinessObjectCorePackage()
            BusinessObjectCorePackage._instance._initialize()
        return BusinessObjectCorePackage._instance
    
    
    
class BusinessObjectCorePackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusinessObjectCorePackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusinessObjectCorePackageDescriptor, self)._initialize()
        self._dependents.append(ManagedObjectPackageDescriptor.get_instance())
        self._package = BusinessObjectCorePackage.get_instance()
        self._factory = BusinessObjectCoreFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') 
                                                  + '/schemas/xsd/BusObjectCoreXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusinessObjectCorePackageDescriptor._instance == None:
            BusinessObjectCorePackageDescriptor._instance = BusinessObjectCorePackageDescriptor()
            BusinessObjectCorePackageDescriptor._instance._initialize()
            
        return BusinessObjectCorePackageDescriptor._instance