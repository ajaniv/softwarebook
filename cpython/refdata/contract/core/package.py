#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/contract/core/package.py - reference contract core  package  module
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
.. module:: refdata.contract.core.package
   :synopsis: Reference data contract core  meta-data module



.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

import os
import busxml.schema.api


from emf.core.classes import EPackage

from emf.core.package import SchemaMetaPackageDescriptor
from busobject.core.package import BusinessObjectCoreFactory
from refdata.core.package import BusRefDataCorePackageDescriptor

from refdata.contract.core.classes import * #@UnusedWildImport


 
_class_lookup = { 'ContractType' : ContractType , 
                 'ContractDomain' : ContractDomain,
                 'BusinessLine' : BusinessLine
                 }


#
# TODO: eliminate unnecessary classes, constructors
#
class BusRefDataContractCoreFactory(BusinessObjectCoreFactory):
    """ Factory to create elements from Business RefData Contract Core Module
    """ 
    _instance = None
    
    def __init__(self):
        super(BusRefDataContractCoreFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusRefDataContractCoreFactory._instance is None:
            BusRefDataContractCoreFactory._instance = BusRefDataContractCoreFactory()
        return BusRefDataContractCoreFactory._instance

    def create_from_string(self, feature_name, str_value, target_type):
        #TODO: convert to table driven
        result = self._create_from_string(feature_name, str_value, target_type)
             
        if result is None:
            result = super(BusRefDataContractCoreFactory, self).create_from_string(feature_name, str_value, target_type)
        return result
    
    def _create_from_string(self, feature_name, str_value, target_type):
        #TODO: convert to table driven
        result = None
         
        if '_Attribute' in target_type:
            type_name = target_type.split('_')[0]
            cls = _class_lookup(type_name)
            if cls is not None:
                result = cls(str_value)
             
         
        return result
    def create_BusRefDataContractCoreConstants(self, do_init=True):
        """
        Create an instance of BusRefDataContractCoreConstants.
        """
        obj = BusRefDataContractCoreConstants()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_BusRefDataContractCoreDomain(self, do_init=True):
        """
        Create an instance of BusRefDataContractCoreDomain.
        """
        obj = BusRefDataContractCoreDomain()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
        
        return obj
            
    def create_BusinessContractActionType(self, do_init=True):
        """
        Create an instance of BusinessContractActionType.
        """
        obj = BusinessContractActionType()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_BusinessContractActionTypeGrouping(self, do_init=True):
        """
        Create an instance of BusinessContractActionTypeGrouping.
        """
        obj = BusinessContractActionTypeGrouping()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_BusinessContractClauseType(self, do_init=True):
        """
        Create an instance of BusinessContractClauseType.
        """
        obj = BusinessContractClauseType()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_BusinessContractClauseTypeGrouping(self, do_init=True):
        """
        Create an instance of BusinessContractClauseTypeGrouping.
        """
        obj = BusinessContractClauseTypeGrouping()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_BusinessContractInstructionType(self, do_init=True):
        """
        Create an instance of BusinessContractInstructionType.
        """
        obj = BusinessContractInstructionType()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_BusinessContractInstructionTypeGrouping(self, do_init=True):
        """
        Create an instance of BusinessContractInstructionTypeGrouping.
        """
        obj = BusinessContractInstructionTypeGrouping()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
        
        return obj
            
    def create_BusinessLine(self, do_init=True):
        """
        Create an instance of create_BusinessLine.
        """
        obj = BusinessLine()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
        
        return obj
            
    def create_BusinessLineGrouping(self, do_init=True):
        """
        Create an instance of BusinessLineGrouping.
        """
        obj = BusinessLineGrouping()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_ContractDomain(self, do_init=True):
        """
        Create an instance of ContractDomain.
        """
        obj = ContractDomain()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_ContractDomainGrouping(self, do_init=True):
        """
        Create an instance of ContractDomainGrouping.
        """
        obj = ContractDomainGrouping()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
        
        return obj
            
    def create_ContractState(self, do_init=True):
        """
        Create an instance of ContractState.
        """
        obj = ContractState()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
    def create_ContractStateGrouping(self, do_init=True):
        """
        Create an instance of ContractStateGrouping.
        """
        obj = ContractStateGrouping()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
    
    def create_ContractType(self, do_init=True):
        """
        Create an instance of ContractType.
        """
        obj = ContractType()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(),do_init)
         
        return obj
    
    def create_ContractTypeGrouping(self, do_init=True):
        """
        Create an instance of ContractTypeTypeGrouping.
        """
        obj = ContractTypeGrouping()
        self._post_object_creation(obj, BusRefDataContractCorePackage.get_instance(), do_init)
         
        return obj
    
    
    
#End BusRefDataContractCoreFactory Class Definition
    
        
        
    
class BusRefDataContractCorePackage(EPackage):
    ENAME = 'core'
    ENS_URI = 'http:///com/ondalear/bus/refdata/contract/core.ecore'
    ENS_PREFIX = 'com.ondalear.bus.refdata.contract.core'
    _instance = None
    
    def __init__(self):
        super(BusRefDataContractCorePackage, self).__init__(BusRefDataContractCorePackage.ENAME, 
                                                   BusRefDataContractCorePackage.ENS_URI, 
                                                   BusRefDataContractCorePackage.ENS_PREFIX)
        super(BusRefDataContractCorePackage, self).set_eFactoryInstance(BusRefDataContractCoreFactory.get_instance())
        
    def _initialize(self):
        super(BusRefDataContractCorePackage, self).initialize()
        self.factory = BusRefDataContractCoreFactory.get_instance()
        self.factory.package = self 
        
    @staticmethod
    def get_instance():
        if  BusRefDataContractCorePackage._instance is None:
            BusRefDataContractCorePackage._instance = BusRefDataContractCorePackage()
            BusRefDataContractCorePackage._instance._initialize()
        return BusRefDataContractCorePackage._instance
#End BusRefDataContractCorePackage Class Definition
    
    
class BusRefDataContractCorePackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusRefDataContractCorePackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusRefDataContractCorePackageDescriptor, self)._initialize()
        #Need to add dependencies on reference data
        self._dependents.append(BusRefDataCorePackageDescriptor.get_instance())
        self._package = BusRefDataContractCorePackage.get_instance()
        self._factory = BusRefDataContractCoreFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') 
                                                  + '/schemas/xsd/BusRefDataContractCoreXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusRefDataContractCorePackageDescriptor._instance == None:
            BusRefDataContractCorePackageDescriptor._instance = BusRefDataContractCorePackageDescriptor()
            BusRefDataContractCorePackageDescriptor._instance._initialize()
            
        return BusRefDataContractCorePackageDescriptor._instance
    
    
#End BusRefDataContractCorePackageDescriptor Class Definition