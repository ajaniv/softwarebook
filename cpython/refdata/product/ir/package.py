#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/product/ir/package.py - reference data product core classes module
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
.. module:: refdata.product.ir.package
   :synopsis: Reference data product ir package modules

 


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
from refdata.product.core.package import BusRefDataProductCorePackageDescriptor
from refdata.product.ir.classes import * #@UnusedWildImport


 



#
# TODO: eliminate unnecessary classes, constructors
#
class BusRefDataProductIRFactory(BusinessObjectCoreFactory):
    """ Factory to create elements from Business RefData Product IR Module
    """ 
    _instance = None
    
    def __init__(self):
        super(BusRefDataProductIRFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusRefDataProductIRFactory._instance is None:
            BusRefDataProductIRFactory._instance = BusRefDataProductIRFactory()
        return BusRefDataProductIRFactory._instance

    def create_BusRefDataProductIRDomain(self, do_init=True):
        """
        Create an instance of BusRefDataProductIRDomain.
        """
        obj = BusRefDataProductIRDomain()
        self._post_object_creation(obj, BusRefDataProductIRPackage.get_instance(),do_init)
         
        return obj
            
    def create_BusRefDataProductIRObjects(self, do_init=True):
        """
        Create an instance of BusRefDataProductIRObjects.
        """
        obj = BusRefDataProductIRObjects()
        self._post_object_creation(obj, BusRefDataProductIRPackage.get_instance(),do_init)
        
        return obj
            
    def create_CashProduct(self, do_init=True):
        """
        Create an instance of CashProduct.
        """
        obj = CashProduct()
        self._post_object_creation(obj, BusRefDataProductIRPackage.get_instance(),do_init)
         
        return obj
            
    def create_CashProductGrouping(self, do_init=True):
        """
        Create an instance of CashProductGrouping.
        """
        obj = CashProductGrouping()
        self._post_object_creation(obj, BusRefDataProductIRPackage.get_instance(),do_init)
         
        return obj
            
    def create_FixedProductGrouping(self, do_init=True):
        """
        Create an instance of Money.
        """
        obj = FixedProductGrouping()
        self._post_object_creation(obj, BusRefDataProductIRPackage.get_instance(),do_init)
         
        return obj
            
    def create_FloatProductGrouping(self, do_init=True):
        """
        Create an instance of FloatProductGrouping.
        """
        obj = FloatProductGrouping()
        self._post_object_creation(obj, BusRefDataProductIRPackage.get_instance(),do_init)
         
        return obj
            
    def create_SimpleRateProduct(self, do_init=True):
        """
        Create an instance of SimpleRateProduct.
        """
        obj = SimpleRateProduct()
        self._post_object_creation(obj, BusRefDataProductIRPackage.get_instance(),do_init)
         
        return obj
            
    def create_FloatProduct(self, do_init=True):
        """
        Create an instance of FloatProduct.
        """
        obj = FloatProduct()
        self._post_object_creation(obj, BusRefDataProductIRPackage.get_instance(),do_init)
        
        return obj
            
    def create_FixedProduct(self, do_init=True):
        """
        Create an instance of FixedProduct.
        """
        obj = FixedProduct()
        self._post_object_creation(obj, BusRefDataProductIRPackage.get_instance(), do_init)
        
        return obj
            
    
            
    

   
    
#End BusRefDataProductIRFactory Class Definition
    
        
        
    
class BusRefDataProductIRPackage(EPackage):
    ENAME = 'ir'
    ENS_URI = 'http:///com/ondalear/bus/refdata/product/ir.ecore'
    ENS_PREFIX = 'com.ondalear.bus.refdata.product.ir'
    _instance = None
    
    def __init__(self):
        super(BusRefDataProductIRPackage, self).__init__(BusRefDataProductIRPackage.ENAME, 
                                                   BusRefDataProductIRPackage.ENS_URI, 
                                                   BusRefDataProductIRPackage.ENS_PREFIX)
        super(BusRefDataProductIRPackage, self).set_eFactoryInstance(BusRefDataProductIRFactory.get_instance())
    def _initialize(self):
        super(BusRefDataProductIRPackage, self).initialize()
        self.factory = BusRefDataProductIRFactory.get_instance()
        self.factory.package = self   
    @staticmethod
    def get_instance():
        if  BusRefDataProductIRPackage._instance is None:
            BusRefDataProductIRPackage._instance = BusRefDataProductIRPackage()
            BusRefDataProductIRPackage._instance._initialize()
        return BusRefDataProductIRPackage._instance
#End BusRefDataProductCorePackage Class Definition
    
    
class BusRefDataProductIRPackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusRefDataProductIRPackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusRefDataProductIRPackageDescriptor, self)._initialize()
        #Need to add dependencies on reference data
        self._dependents.append(BusRefDataCorePackageDescriptor.get_instance())
        self._dependents.append(BusRefDataProductCorePackageDescriptor.get_instance())
        self._package = BusRefDataProductIRPackage.get_instance()
        self._factory = BusRefDataProductIRFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') + 
                                                  '/schemas/xsd/BusRefDataProductIRXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusRefDataProductIRPackageDescriptor._instance == None:
            BusRefDataProductIRPackageDescriptor._instance = BusRefDataProductIRPackageDescriptor()
            BusRefDataProductIRPackageDescriptor._instance._initialize()
            
        return BusRefDataProductIRPackageDescriptor._instance
    
    
#End BusRefDataProductCorePackageDescriptor Class Definition