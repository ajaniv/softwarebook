#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/parties/classes.py - reference data parties clasess module
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
.. module:: refdata.parties.package
   :synopsis: Reference data parties  package module

 


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

from refdata.parties.classes import * #@UnusedWildImport


 



#
# TODO: eliminate unnecessary classes, constructors
#
class BusRefDataPartiesFactory(BusinessObjectCoreFactory):
    """ Factory to create elements from Business RefData Parties Module
    """ 
    _instance = None
    
    def __init__(self):
        super(BusRefDataPartiesFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusRefDataPartiesFactory._instance is None:
            BusRefDataPartiesFactory._instance = BusRefDataPartiesFactory()
        return BusRefDataPartiesFactory._instance

    def create_BusRefDataPartiesConstants(self, do_init=True):
        """
        Create an instance of BusRefDataPartiesConstants.
        """
        obj = BusRefDataPartiesConstants()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
            
    def create_BusRefDataPartiesDomain(self, do_init=True):
        """
        Create an instance of BusRefDataPartiesDomain.
        """
        obj = BusRefDataPartiesDomain()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
        
        return obj
            
    def create_BusRefDataPartiesObjects(self, do_init=True):
        """
        Create an instance of BusRefDataPartiesObjects.
        """
        obj = BusRefDataPartiesObjects()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
            
    def create_CorporateLegalEntityGrouping(self, do_init=True):
        """
        Create an instance of CorporateLegalEntityGrouping.
        """
        obj = CorporateLegalEntityGrouping()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
            
    def create_CounterParty(self, do_init=True):
        """
        Create an instance of CounterParty.
        """
        obj = CounterParty()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
            
    def create_CounterPartyGrouping(self, do_init=True):
        """
        Create an instance of CounterPartyGrouping.
        """
        obj = CounterPartyGrouping()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
            
    def create_CounterPartyRole(self, do_init=True):
        """
        Create an instance of CounterPartyRole.
        """
        obj = CounterPartyRole()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
            
    def create_CounterPartyRoleGrouping(self, do_init=True):
        """
        Create an instance of CounterPartyRoleGrouping.
        """
        obj = CounterPartyRoleGrouping()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
        
        return obj
            
    def create_CounterPartySpec(self, do_init=True):
        """
        Create an instance of CounterPartySpec.
        """
        obj = CounterPartySpec()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
        
        return obj
            
    def create_CounterPartyType(self, do_init=True):
        """
        Create an instance of CounterPartyType.
        """
        obj = CounterPartyType()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
            
    def create_CounterPartyTypeGrouping(self, do_init=True):
        """
        Create an instance of CounterPartyTypeGrouping.
        """
        obj = CounterPartyTypeGrouping()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
            
    def create_IndividualLegalEntityGrouping(self, do_init=True):
        """
        Create an instance of IndividualLegalEntityGrouping.
        """
        obj = IndividualLegalEntityGrouping()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
        
        return obj
            
    def create_LegalEntity(self, do_init=True):
        """
        Create an instance of LegalEntity.
        """
        obj = LegalEntity()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
    def create_LegalEntityType(self, do_init=True):
        """
        Create an instance of LegalEntityType
        """
        obj = LegalEntityType()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
    
    def create_LegalEntityTypeGrouping(self, do_init=True):
        """
        Create an instance of LegalEntityTypeGrouping.
        """
        obj = LegalEntityTypeGrouping()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
    
    def create_TransactionSide(self, do_init=True):
        """
        Create an instance of TransactionSide.
        """
        obj = TransactionSide()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
    
    def create_TransactionSideGrouping(self, do_init=True):
        """
        Create an instance of LocationAddress.
        """
        obj = TransactionSideGrouping()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
    
    def create_IndividualLegalEntity(self, do_init=True):
        """
        Create an instance of IndividualLegalEntity.
        """
        obj = IndividualLegalEntity()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(),do_init)
         
        return obj
    
    def create_CorporateLegalEntity(self, do_init=True):
        """
        Create an instance of CorporateLegalEntity.
        """
        obj = CorporateLegalEntity()
        self._post_object_creation(obj, BusRefDataPartiesPackage.get_instance(), do_init)
         
        return obj

#End BusRefDataPartiesFactory Class Definition
    
        
        
    
class BusRefDataPartiesPackage(EPackage):
    ENAME = 'parties'
    ENS_URI = 'http:///com/ondalear/bus/refdata/parties.ecore'
    ENS_PREFIX = 'com.ondalear.bus.refdata.parties'
    _instance = None
    
    def __init__(self):
        super(BusRefDataPartiesPackage, self).__init__(BusRefDataPartiesPackage.ENAME, 
                                                   BusRefDataPartiesPackage.ENS_URI, 
                                                   BusRefDataPartiesPackage.ENS_PREFIX)
        super(BusRefDataPartiesPackage, self).set_eFactoryInstance(BusRefDataPartiesFactory.get_instance())
    def _initialize(self):
        super(BusRefDataPartiesPackage, self).initialize()
        self.factory = BusRefDataPartiesFactory.get_instance()
        self.factory.package = self     
    @staticmethod
    def get_instance():
        if  BusRefDataPartiesPackage._instance is None:
            BusRefDataPartiesPackage._instance = BusRefDataPartiesPackage()
            BusRefDataPartiesPackage._instance._initialize()
        return BusRefDataPartiesPackage._instance
#End BusRefDataPartiesPackage Class Definition
    
    
class BusRefDataPartiesPackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusRefDataPartiesPackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusRefDataPartiesPackageDescriptor, self)._initialize()
        #Need to add dependencies on reference data
        self._dependents.append(BusRefDataCorePackageDescriptor.get_instance())
        self._package = BusRefDataPartiesPackage.get_instance()
        self._factory = BusRefDataPartiesFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT') 
                                                  + '/schemas/xsd/BusRefDataPartiesXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusRefDataPartiesPackageDescriptor._instance == None:
            BusRefDataPartiesPackageDescriptor._instance = BusRefDataPartiesPackageDescriptor()
            BusRefDataPartiesPackageDescriptor._instance._initialize()
            
        return BusRefDataPartiesPackageDescriptor._instance
    
    
#End BusRefDataPartiesPackageDescriptor Class Definition