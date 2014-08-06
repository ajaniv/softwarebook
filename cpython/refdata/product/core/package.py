#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/product/core/package.py - reference data product core package module
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
.. module:: refdata.product.core.package
   :synopsis: Reference data product core package modules

 


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

from refdata.product.core.classes import * #@UnusedWildImport


 



#
# TODO: eliminate unnecessary classes, constructors
#
class BusRefDataProductCoreFactory(BusinessObjectCoreFactory):
    """ Factory to create elements from Business RefData Product Core Module
    """ 
    _instance = None
    
    def __init__(self):
        super(BusRefDataProductCoreFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusRefDataProductCoreFactory._instance is None:
            BusRefDataProductCoreFactory._instance = BusRefDataProductCoreFactory()
        return BusRefDataProductCoreFactory._instance

    def create_BusRefDataProductCoreConstants(self, do_init=True):
        """
        Create an instance of BusRefDataProductCoreConstants.
        """
        obj = BusRefDataProductCoreConstants()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_BusRefDataProductCoreDomain(self, do_init=True):
        """
        Create an instance of BusRefDataProductCoreDomain.
        """
        obj = BusRefDataProductCoreDomain()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(),do_init)
        
        return obj
            
    def create_BusinessProduct(self, do_init=True):
        """
        Create an instance of BusinessProduct.
        """
        obj = BusinessProduct()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_ContractableSpec(self, do_init=True):
        """
        Create an instance of ContractableSpec.
        """
        obj = ContractableSpec()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_Money(self, do_init=True):
        """
        Create an instance of Money.
        """
        obj = Money()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_ProductFamily(self, do_init=True):
        """
        Create an instance of ProductFamily.
        """
        obj = ProductFamily()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_ProductFamilyGrouping(self, do_init=True):
        """
        Create an instance of ProductFamilyGrouping.
        """
        obj = ProductFamilyGrouping()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(),do_init)
         
        return obj
            
    def create_ProductType(self, do_init=True):
        """
        Create an instance of ProductType.
        """
        obj = ProductType()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(), do_init)
        
        return obj
            
    def create_ProductTypeGrouping(self, do_init=True):
        """
        Create an instance of ProductTypeGrouping.
        """
        obj = ProductTypeGrouping()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(),do_init)
        
        return obj
            
    def create_Quantity(self, do_init=True):
        """
        Create an instance of Quantity.
        """
        obj = Quantity()
        self._post_object_creation(obj, BusRefDataProductCorePackage.get_instance(), do_init)
         
        return obj
            
    

   
    
#End BusRefDataProductCoreFactory Class Definition
    
        
        
    
class BusRefDataProductCorePackage(EPackage):
    ENAME = 'core'
    ENS_URI = 'http:///com/ondalear/bus/refdata/product/core.ecore'
    ENS_PREFIX = 'com.ondalear.bus.refdata.product.core'
    _instance = None
    
    def __init__(self):
        super(BusRefDataProductCorePackage, self).__init__(BusRefDataProductCorePackage.ENAME, 
                                                   BusRefDataProductCorePackage.ENS_URI, 
                                                   BusRefDataProductCorePackage.ENS_PREFIX)
        super(BusRefDataProductCorePackage, self).set_eFactoryInstance(BusRefDataProductCoreFactory.get_instance())
    def _initialize(self):
        super(BusRefDataProductCorePackage, self).initialize()
        self.factory = BusRefDataProductCoreFactory.get_instance()
        self.factory.package = self     
    @staticmethod
    def get_instance():
        if  BusRefDataProductCorePackage._instance is None:
            BusRefDataProductCorePackage._instance = BusRefDataProductCorePackage()
            BusRefDataProductCorePackage._instance._initialize()
        return BusRefDataProductCorePackage._instance
#End BusRefDataProductCorePackage Class Definition
    
    
class BusRefDataProductCorePackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusRefDataProductCorePackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusRefDataProductCorePackageDescriptor, self)._initialize()
        #Need to add dependencies on reference data
        self._dependents.append(BusRefDataCorePackageDescriptor.get_instance())
        self._package = BusRefDataProductCorePackage.get_instance()
        self._factory = BusRefDataProductCoreFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') 
                                                  + '/schemas/xsd/BusRefDataProductCoreXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusRefDataProductCorePackageDescriptor._instance == None:
            BusRefDataProductCorePackageDescriptor._instance = BusRefDataProductCorePackageDescriptor()
            BusRefDataProductCorePackageDescriptor._instance._initialize()
            
        return BusRefDataProductCorePackageDescriptor._instance
    
    
#End BusRefDataProductCorePackageDescriptor Class Definition