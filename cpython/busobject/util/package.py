#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/util/package.py - busobject util package  module
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
.. module:: busobject.util.package
   :synopsis: Run-time meta data utilities module

The busobject.util.package  module defines the  classes required to provide uitl package
meta data run time information.

Sample usage :
  >>> from busobject.mngobject.package import BusinessObjectUtilFactory
  >>> from busobject.mngobject.package import BusinessObjectUtilPackage
  >>> from busobject.mngobject.package import BusinessObjectUtilPackageDescriptor

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

import os

import emf.core.api #@UnusedImport
import busxml.schema.api

from emf.core.classes import EPackage
from emf.core.package import SchemaMetaPackageDescriptor


from busobject.core.package import BusinessObjectCoreFactory
from busobject.core.package import BusinessObjectCorePackageDescriptor

from busobject.util.classes import * #@UnusedWildImport


 




class BusinessObjectUtilFactory(BusinessObjectCoreFactory):
    _instance = None
    
    def __init__(self):
        super(BusinessObjectUtilFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusinessObjectUtilFactory._instance is None:
            BusinessObjectUtilFactory._instance = BusinessObjectUtilFactory()
        return BusinessObjectUtilFactory._instance

   
            
    def createDocumentAttachement(self, do_init=True):
        """
        Create an instance of DocumentAttachement.
        """
        obj = DocumentAttachment()
        self._post_object_creation(obj, BusinessObjectUtilPackage.get_instance(), do_init)
        
        return obj

    
        
        
    
class BusinessObjectUtilPackage(EPackage):
    ENAME = 'util'
    ENS_URI = 'http:///com/ondalear/bus/object/util.ecore'
    ENS_PREFIX = 'com.ondalear.bus.object.util'
    _instance = None
    
    def __init__(self):
        super(BusinessObjectUtilPackage, self).__init__(BusinessObjectUtilPackage.ENAME, 
                                                   BusinessObjectUtilPackage.ENS_URI, 
                                                   BusinessObjectUtilPackage.ENS_PREFIX)
        super(BusinessObjectUtilPackage, self).set_eFactoryInstance(BusinessObjectUtilFactory.get_instance())
    def _initialize(self):
        super(BusinessObjectUtilPackage, self).initialize()
        self.factory = BusinessObjectUtilFactory.get_instance()
        self.factory.package = self 
    @staticmethod
    def get_instance():
        if  BusinessObjectUtilPackage._instance is None:
            BusinessObjectUtilPackage._instance = BusinessObjectUtilPackage()
            BusinessObjectUtilPackage._instance._initialize()
        return BusinessObjectUtilPackage._instance
    
    
    
class BusinessObjectUtilPackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusinessObjectUtilPackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusinessObjectUtilPackageDescriptor, self)._initialize()
        #
        # TODO: need to add dependency on reference data core
        #
        self._dependents.append(BusinessObjectCorePackageDescriptor.get_instance())
        self._package = BusinessObjectUtilPackage.get_instance()
        self._factory = BusinessObjectUtilFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') + 
                                                  '/schemas/xsd/BusObjectUtilXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusinessObjectUtilPackageDescriptor._instance == None:
            BusinessObjectUtilPackageDescriptor._instance = BusinessObjectUtilPackageDescriptor()
            BusinessObjectUtilPackageDescriptor._instance._initialize()
            
        return BusinessObjectUtilPackageDescriptor._instance