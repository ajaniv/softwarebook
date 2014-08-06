#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/workspace/objects/classes.py - reference data workspace objects classes  module
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
.. module:: refdata.workspace.objects.package
   :synopsis: Reference data workspace objects package  module

 

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
from refdata.common.package import BusRefDataCommonPackageDescriptor
from refdata.contract.core.package import BusRefDataContractCorePackageDescriptor
from refdata.parties.package import BusRefDataPartiesPackageDescriptor
from refdata.product.core.package import BusRefDataProductCorePackageDescriptor
from refdata.product.ir.package import BusRefDataProductIRPackageDescriptor
from refdata.users.package import BusRefDataUsersPackageDescriptor

from refdata.workspace.objects.classes import * #@UnusedWildImport


 



#
# TODO: eliminate unnecessary classes, constructors
#
class BusRefDataWorkspaceObjectsFactory(BusinessObjectCoreFactory):
    """ Factory to create elements from Business RefData Objects Workspace  Module
    """ 
    _instance = None
    
    def __init__(self):
        super(BusRefDataWorkspaceObjectsFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusRefDataWorkspaceObjectsFactory._instance is None:
            BusRefDataWorkspaceObjectsFactory._instance = BusRefDataWorkspaceObjectsFactory()
        return BusRefDataWorkspaceObjectsFactory._instance

    def create_RefDataWorkspace(self, do_init):
        """
        Create an instance of create_RefDataWorkspace.
        """
        obj = RefDataWorkspace()
        self._post_object_creation(obj, BusRefDataWorkspaceObjectsPackage.get_instance(), do_init)
         
        return obj
            
    
            
    
            
    

   
    
#End BusRefDataWorkspaceObjectsFactory Class Definition
    
        
        
    
class BusRefDataWorkspaceObjectsPackage(EPackage):
    ENAME = 'objects'
    ENS_URI = 'http:///com/ondalear/bus/refdata/workspace/objects.ecore'
    ENS_PREFIX = 'com.ondalear.bus.refdata.workspace.objects'
    _instance = None
    
    def __init__(self):
        super(BusRefDataWorkspaceObjectsPackage, self).__init__(BusRefDataWorkspaceObjectsPackage.ENAME, 
                                                   BusRefDataWorkspaceObjectsPackage.ENS_URI, 
                                                   BusRefDataWorkspaceObjectsPackage.ENS_PREFIX)
        super(BusRefDataWorkspaceObjectsPackage, self).set_eFactoryInstance(BusRefDataWorkspaceObjectsFactory.get_instance())
    def _initialize(self):
        super(BusRefDataWorkspaceObjectsPackage, self).initialize()
        self.factory = BusRefDataWorkspaceObjectsFactory.get_instance()
        self.factory.package = self     
    @staticmethod
    def get_instance():
        if  BusRefDataWorkspaceObjectsPackage._instance is None:
            BusRefDataWorkspaceObjectsPackage._instance = BusRefDataWorkspaceObjectsPackage()
            BusRefDataWorkspaceObjectsPackage._instance._initialize()
        return BusRefDataWorkspaceObjectsPackage._instance
#End BusRefDataWorkspaceObjectsPackage Class Definition
    
    
class BusRefDataWorkspaceObjectsPackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusRefDataWorkspaceObjectsPackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusRefDataWorkspaceObjectsPackageDescriptor, self)._initialize()
        #Need to add dependencies on reference data
        self._dependents.append(BusRefDataCorePackageDescriptor.get_instance())
        self._dependents.append(BusRefDataCommonPackageDescriptor.get_instance())
        self._dependents.append(BusRefDataContractCorePackageDescriptor.get_instance())
        self._dependents.append(BusRefDataPartiesPackageDescriptor.get_instance())
        self._dependents.append(BusRefDataProductCorePackageDescriptor.get_instance())
        self._dependents.append(BusRefDataProductIRPackageDescriptor.get_instance())
        self._dependents.append(BusRefDataUsersPackageDescriptor.get_instance())
        self._package = BusRefDataWorkspaceObjectsPackage.get_instance()
        
        self._factory = BusRefDataWorkspaceObjectsFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT')
                                                    + '/xsd/BusRefDataWorkspaceObjectsXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusRefDataWorkspaceObjectsPackageDescriptor._instance == None:
            BusRefDataWorkspaceObjectsPackageDescriptor._instance = BusRefDataWorkspaceObjectsPackageDescriptor()
            BusRefDataWorkspaceObjectsPackageDescriptor._instance._initialize()
            
        return BusRefDataWorkspaceObjectsPackageDescriptor._instance
    
    
#End BusRefDataWorkspaceObjectsPackageDescriptor Class Definition