#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/core/package.py - reference  core  package  module
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
.. module:: refdata.core.package
   :synopsis: Reference data core  meta-data module



.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

import os
import busxml.schema.api


from emf.core.classes import EPackage

from emf.core.package import SchemaMetaPackageDescriptor
from busobject.core.package import BusinessObjectCoreFactory
from busobject.core.package import BusinessObjectCorePackageDescriptor

from refdata.core.classes import * #@UnusedWildImport


 




class BusRefDataCoreFactory(BusinessObjectCoreFactory):
    """ Factory to create elements from Business RefData Core Module
    """ 
    _instance = None
    
    def __init__(self):
        super(BusRefDataCoreFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusRefDataCoreFactory._instance is None:
            BusRefDataCoreFactory._instance = BusRefDataCoreFactory()
        return BusRefDataCoreFactory._instance

    def create_RefDataDomain(self, do_init=True):
        """
        Create an instance of RefDataDomain.
        """
        obj = RefDataDomain()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_RefDataObject(self, do_init=True):
        """
        Create an instance of RefDataObject.
        """
        obj = RefDataObject()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_RefDataSource(self, do_init=True):
        """
        Create an instance of RefDataSource.
        """
        obj = RefDataSource()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_RefDataGrouping(self, do_init=True):
        """
        Create an instance of RefDataGrouping.
        """
        obj = RefDataGrouping()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_GenericRefDataObjectGrouping(self, do_init=True):
        """
        Create an instance of GenericRefDataObjectGrouping.
        """
        obj = GenericRefDataObjectGrouping()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_ConstantsGrouping(self, do_init=True):
        """
        Create an instance of ConstantsGrouping.
        """
        obj = ConstantsGrouping()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_ConstantsDomain(self, do_init=True):
        """
        Create an instance of ConstantsDomain.
        """
        obj = ConstantsDomain()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_BusRefDataCoreObjects(self, do_init=True):
        """
        Create an instance of BusRefDataCoreObjects.
        """
        obj = BusRefDataCoreObjects()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_BusRefDataCoreDomain(self, do_init=True):
        """
        Create an instance of BusRefDataCoreDomain.
        """
        obj = BusRefDataCoreDomain()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_BusRefDataCoreConstants(self, do_init=True):
        """
        Create an instance of BusRefDataCoreConstants.
        """
        obj = BusRefDataCoreConstants()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_AttachmentTypeGrouping(self, do_init=True):
        """
        Create an instance of AttachmentTypeGrouping.
        """
        obj = AttachmentTypeGrouping()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_AttachmentType(self, do_init=True):
        """
        Create an instance of AttachmentType.
        """
        obj = AttachmentType()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_RefDataSourceTypeGrouping(self, do_init=True):
        """
        Create an instance of RefDataSourceTypeGrouping.
        """
        obj = RefDataSourceTypeGrouping()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
    def create_RefDataSourceGrouping(self, do_init=True):
        """
        Create an instance of RefDataSourceGrouping.
        """
        obj = RefDataSourceGrouping()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
    
    def create_GenericConstantGrouping(self, do_init=True):
        """
        Create an instance of GenericConstantGrouping.
        """
        obj = GenericConstantGrouping()
        self._post_object_creation(obj, BusRefDataCorePackage.get_instance(), do_init)
         
        return obj
    
#End BusRefDataCoreFactory Class Definition
    
        
        
    
class BusRefDataCorePackage(EPackage):
    ENAME = 'core'
    ENS_URI = 'http:///com/ondalear/bus/refdata/core.ecore'
    ENS_PREFIX = 'com.ondalear.bus.refdata.core'
    _instance = None
    
    def __init__(self):
        super(BusRefDataCorePackage, self).__init__(BusRefDataCorePackage.ENAME, 
                                                   BusRefDataCorePackage.ENS_URI, 
                                                   BusRefDataCorePackage.ENS_PREFIX)
        super(BusRefDataCorePackage, self).set_eFactoryInstance(BusRefDataCoreFactory.get_instance())
    def _initialize(self):
        super(BusRefDataCorePackage, self).initialize()
        self.factory = BusRefDataCoreFactory.get_instance()
        self.factory.package = self 
    @staticmethod
    def get_instance():
        if  BusRefDataCorePackage._instance is None:
            BusRefDataCorePackage._instance = BusRefDataCorePackage()
            BusRefDataCorePackage._instance._initialize()
        return BusRefDataCorePackage._instance
#End BusRefDataCorePackage Class Definition
    
    
class BusRefDataCorePackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusRefDataCorePackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusRefDataCorePackageDescriptor, self)._initialize()
        #Need to add dependencies on reference data
        self._dependents.append(BusinessObjectCorePackageDescriptor.get_instance())
        self._package = BusRefDataCorePackage.get_instance()
        self._factory = BusRefDataCoreFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') 
                                                  + '/schemas/xsd/BusRefDataCoreXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusRefDataCorePackageDescriptor._instance == None:
            BusRefDataCorePackageDescriptor._instance = BusRefDataCorePackageDescriptor()
            BusRefDataCorePackageDescriptor._instance._initialize()
            
        return BusRefDataCorePackageDescriptor._instance
    
    
#End BusContractCorePackageDescriptor Class Definition
