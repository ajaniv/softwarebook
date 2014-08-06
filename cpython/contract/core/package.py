#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# contract/core/package.py - contract package meta data
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
.. module:: contract.core.package
   :synopsis: Contracts run-time meta data for  module

Classes required to manage contract.core package meta data

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""


import os
import busxml.schema.api


from emf.core.classes import EPackage
from emf.core.package import SchemaMetaPackageDescriptor


from busobject.core.package import BusinessObjectCoreFactory
from busobject.core.package import BusinessObjectCorePackageDescriptor
from busobject.util.package import BusinessObjectUtilPackageDescriptor
from refdata.common.package import BusRefDataCommonPackageDescriptor
from refdata.contract.core.package import BusRefDataContractCorePackageDescriptor
from refdata.parties.package import BusRefDataPartiesPackageDescriptor
from refdata.product.ir.package import BusRefDataProductIRPackageDescriptor

from contract.core.classes import * #@UnusedWildImport


 




class BusContractCoreFactory(BusinessObjectCoreFactory):
    """ 
    Factory to create objects from Business Contract Core Module
    
    Factory pattern is used to control how the instance is initialized,
    which attributes are added to it, all coming from meta data information.
    """ 
    
    _instance = None
    
    def __init__(self):
        super(BusContractCoreFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        """
        Singleton pattern implementation
        """
        
        if BusContractCoreFactory._instance is None:
            BusContractCoreFactory._instance = BusContractCoreFactory()
        return BusContractCoreFactory._instance

    def create_BusinessContract(self, do_init=True):
        """
        Create an instance of BusinessContract.
        
        :param init: post initialization flag. If set to true, instance default values will be set
        :type name: bool.
        :returns:  BusinessContract -- instance of configured BusinessContract object.
        """
        obj = BusinessContract()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_BusinessContractAction(self, do_init=True):
        """
        Create an instance of BusinessContractAction.
        """
        obj = BusinessContractAction()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_BusinessContractClause(self, do_init=True):
        """
        Create an instance of BusinessContractClause.
        """
        obj = BusinessContractClause()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_BusinessContractClauseGrouping(self, do_init=True):
        """
        Create an instance of BusinessContractClauseGrouping.
        """
        obj = BusinessContractClauseGrouping()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_BusinessContractClauseList(self, do_init=True):
        """
        Create an instance of BusinessContractClauseList.
        """
        obj = BusinessContractClauseList()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_BusinessContractInstruction(self, do_init=True):
        """
        Create an instance of BusinessContractInstruction.
        """
        obj = BusinessContractInstruction()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_BusinessContractList(self, do_init=True):
        """
        Create an instance of BusinessContractList.
        """
        obj = BusinessContractList()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_BusinessContractWorkspace(self, do_init=True):
        """
        Create an instance of BusinessContractWorkspace.
        """
        obj = BusinessContractWorkspace()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_ContractActionSpec(self, do_init=True):
        """
        Create an instance of ContractActionSpec.
        """
        obj = ContractActionSpec()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_ContractClauseSpec(self, do_init=True):
        """
        Create an instance of ContractClauseSpec.
        """
        obj = ContractClauseSpec()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_ContractInstructionSpec(self, do_init=True):
        """
        Create an instance of ContractInstructionSpec.
        """
        obj = ContractInstructionSpec()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
         
        return obj
            
    def create_ContractPartSpec(self, do_init=True):
        """
        Create an instance of ContractPartSpec.
        """
        obj = ContractPartSpec()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_ContractSpec(self, do_init=True):
        """
        Create an instance of ContractSpec.
        """
        obj = ContractSpec()
        self._post_object_creation(obj, BusContractCorePackage.get_instance(), do_init)
         
        return obj
    
#End BusContractCoreFactory Class Definition
    
        
        
    
class BusContractCorePackage(EPackage):
    """
    Describes package meta data
    """
    ENAME = 'core'
    ENS_URI = 'http:///com/ondalear/bus/contract/core.ecore'
    ENS_PREFIX = 'com.ondalear.bus.contract.core'
    _instance = None
    
    def __init__(self):
        super(BusContractCorePackage, self).__init__(BusContractCorePackage.ENAME, 
                                                   BusContractCorePackage.ENS_URI, 
                                                   BusContractCorePackage.ENS_PREFIX)
        super(BusContractCorePackage, self).set_eFactoryInstance(BusContractCoreFactory.get_instance())
        
    @staticmethod
    def get_instance():
        """
        Singleton pattern implementation
        """
        if  BusContractCorePackage._instance is None:
            BusContractCorePackage._instance = BusContractCorePackage()
            BusContractCorePackage._instance._initialize()
        return BusContractCorePackage._instance
    
    def _initialize(self):
        super(BusContractCorePackage, self).initialize()
        self.factory = BusContractCoreFactory.get_instance()
        self.factory.package = self
    
class BusContractCorePackageDescriptor(SchemaMetaPackageDescriptor):
    """
    Container of package meta data including package, factory classes
    """
    _instance = None
    def __init__(self):
        super(BusContractCorePackageDescriptor, self).__init__()
    
    """
        .. todo::
            better error handling, eliminate hard coded strings
        .. todo::
            Environment Variables to be included in the initialization, done once
    """

    def _initialize(self):
        super(BusContractCorePackageDescriptor, self)._initialize()
        #Need to add dependencies on reference data
        self._dependents.append(BusinessObjectCorePackageDescriptor.get_instance())
        self._dependents.append(BusinessObjectUtilPackageDescriptor.get_instance())
        self._dependents.append(BusRefDataCommonPackageDescriptor.get_instance())
        self._dependents.append(BusRefDataContractCorePackageDescriptor.get_instance())
        self._dependents.append(BusRefDataPartiesPackageDescriptor.get_instance())
        self._dependents.append(BusRefDataProductIRPackageDescriptor.get_instance())
         
         
        
        self._package = BusContractCorePackage.get_instance()
        self._factory = BusContractCoreFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') 
                                                  + '/schemas/xsd/BusContractCoreXMI.xsd')
    @staticmethod 
    def get_instance(): 
        """
        Singleton pattern implementation
        """
        
        if BusContractCorePackageDescriptor._instance == None:
            BusContractCorePackageDescriptor._instance = BusContractCorePackageDescriptor()
            BusContractCorePackageDescriptor._instance._initialize()
            
        return BusContractCorePackageDescriptor._instance
    
    def get_namespace(self):
        """
        Return the name space which uniquely identifies the package
        """
        return BusContractCorePackage.ENS_PREFIX
   
