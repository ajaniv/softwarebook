#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/common/package.py - reference data package  module
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
.. module:: refdata.common.package
   :synopsis: Reference data common meta-data module



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

from refdata.common.classes import * #@UnusedWildImport


 



#
# TODO: eliminate unnecessary classes, constructors
#
class BusRefDataCommonFactory(BusinessObjectCoreFactory):
    """ Factory to create elements from Business RefData Common Module
    """ 
    _instance = None
    
    def __init__(self):
        super(BusRefDataCommonFactory, self).__init__()
    
    
    @staticmethod
    def get_instance():
        if BusRefDataCommonFactory._instance is None:
            BusRefDataCommonFactory._instance = BusRefDataCommonFactory()
        return BusRefDataCommonFactory._instance

    def create_AddressType(self, do_init=True):
        """
        Create an instance of AddressType.
        """
        obj = AddressType()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
            
    def create_AddressTypeGrouping(self, do_init=True):
        """
        Create an instance of AddressTypeGrouping.
        """
        obj = AddressTypeGrouping()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
        
        return obj
            
    def create_BusRefDataCommonConstants(self, do_init=True):
        """
        Create an instance of RefDataSource.
        """
        obj = BusRefDataCommonConstants()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
            
    def create_BusRefDataCommonDomain(self, do_init=True):
        """
        Create an instance of BusRefDataCommonDomai.
        """
        obj = BusRefDataCommonDomain()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
            
    def create_BusReffDataCommonObjects(self, do_init=True):
        """
        Create an instance of BusReffDataCommonObjects.
        """
        obj = BusRefDataCommonObjects()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
            
    def create_Company(self, do_init=True):
        """
        Create an instance of Company.
        """
        obj = Company()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
            
    def create_CompanyGrouping(self, do_init=True):
        """
        Create an instance of CompanyGrouping.
        """
        obj = CompanyGrouping()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
            
    def create_ContactAddress(self, do_init=True):
        """
        Create an instance of ContactAddress.
        """
        obj = ContactAddress()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
        
        return obj
            
    def create_ContractableUnit(self, do_init=True):
        """
        Create an instance of BusRefDataCoreDomain.
        """
        obj = ContractableUnit()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
        
        return obj
            
    def create_ContractableUnitGrouping(self, do_init=True):
        """
        Create an instance of ContractableUnitGrouping.
        """
        obj = ContractableUnitGrouping()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
            
    def create_Country(self, do_init=True):
        """
        Create an instance of Country.
        """
        obj = Country()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
            
    def create_Currency(self, do_init=True):
        """
        Create an instance of Currency.
        """
        obj = Currency()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
        
        return obj
            
    def create_CurrencyGrouping(self, do_init=True):
        """
        Create an instance of CurrencyGrouping.
        """
        obj = CurrencyGrouping()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    def create_EmailAddress(self, do_init=True):
        """
        Create an instance of EmailAddress.
        """
        obj = EmailAddress()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_EmailAddressType(self, do_init=True):
        """
        Create an instance of EmailAddressType.
        """
        obj = EmailAddressType()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_EmailAddressTypeGrouping(self, do_init=True):
        """
        Create an instance of EmailAddressTypeGrouping.
        """
        obj = EmailAddressTypeGrouping()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_LocationAddress(self, do_init=True):
        """
        Create an instance of LocationAddress.
        """
        obj = LocationAddress()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_Person(self, do_init=True):
        """
        Create an instance of Person.
        """
        obj = Person()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_PersonGrouping(self, do_init=True):
        """
        Create an instance of PersonGrouping.
        """
        obj = PersonGrouping()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj

    def create_PersonName(self, do_init=True):
        """
        Create an instance of PersonName.
        """
        obj = PersonName()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_PhoneNumber(self, do_init=True):
        """
        Create an instance of PersonNumber.
        """
        obj = PhoneNumber()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_PhoneNumberType(self, do_init=True):
        """
        Create an instance of PhoneNumberType.
        """
        obj = PhoneNumberType()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_PhoneNumberTypeGrouping(self, do_init=True):
        """
        Create an instance of PhoneNumberTypeGrouping.
        """
        obj = PhoneNumberTypeGrouping()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_RefRateDescriptor(self, do_init=True):
        """
        Create an instance of RefRateDescriptor.
        """
        obj = RefRateDescriptor()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_RefRateDescriptorGrouping(self, do_init=True):
        """
        Create an instance of RefRateDescriptorGrouping.
        """
        obj = RefRateDescriptorGrouping()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_ReferenceRate(self, do_init=True):
        """
        Create an instance of ReferenceRate.
        """
        obj = ReferenceRate()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_ReferenceRateGrouping(self, do_init=True):
        """
        Create an instance of ReferenceRateGrouping.
        """
        obj = ReferenceRateGrouping()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_TimePeriod(self, do_init=True):
        """
        Create an instance of TimePeriod.
        """
        obj = TimePeriod()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_TimePeriodGrouping(self, do_init=True):
        """
        Create an instance of TimePeriodGrouping.
        """
        obj = TimePeriodGrouping
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_Libor(self, do_init=True):
        """
        Create an instance of Libor.
        """
        obj = Libor()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
    def create_FixedRate(self, do_init=True):
        """
        Create an instance of FixedRate.
        """
        obj = FixedRate()
        self._post_object_creation(obj, BusRefDataCommonPackage.get_instance(), do_init)
         
        return obj
    
#End BusRefDataCoreFactory Class Definition
    
        
        
    
class BusRefDataCommonPackage(EPackage):
    ENAME = 'common'
    ENS_URI = 'http:///com/ondalear/bus/refdata/common.ecore'
    ENS_PREFIX = 'com.ondalear.bus.refdata.common'
    _instance = None
    
    def __init__(self):
        super(BusRefDataCommonPackage, self).__init__(BusRefDataCommonPackage.ENAME, 
                                                   BusRefDataCommonPackage.ENS_URI, 
                                                   BusRefDataCommonPackage.ENS_PREFIX)
        super(BusRefDataCommonPackage, self).set_eFactoryInstance(BusRefDataCommonFactory.get_instance())
        
    @staticmethod
    def get_instance():
        if  BusRefDataCommonPackage._instance is None:
            BusRefDataCommonPackage._instance = BusRefDataCommonPackage()
            BusRefDataCommonPackage._instance._initialize()
        return BusRefDataCommonPackage._instance
    
    def _initialize(self):
        super(BusRefDataCommonPackage, self).initialize()
        self.factory = BusRefDataCommonFactory.get_instance()
        self.factory.package = self 
#End BusRefDataCorePackage Class Definition
    
    
class BusRefDataCommonPackageDescriptor(SchemaMetaPackageDescriptor):
    _instance = None
    def __init__(self):
        super(BusRefDataCommonPackageDescriptor, self).__init__()
        
    #
    # TODO: better error handling, eliminate hard coded strings
    # Environment Variables to be included in the initialization, done once
    #
    def _initialize(self):
        super(BusRefDataCommonPackageDescriptor, self)._initialize()
        #Need to add dependencies on reference data
        self._dependents.append(BusRefDataCorePackageDescriptor.get_instance())
        self._package = BusRefDataCommonPackage.get_instance()
        self._factory = BusRefDataCommonFactory.get_instance()
        self._package_meta =  busxml.schema.api.parse(os.environ.get('APP_ROOT')
                                                   + '/schemas/xsd/BusRefDataCommonXMI.xsd')
    @staticmethod 
    def get_instance(): 
        if BusRefDataCommonPackageDescriptor._instance == None:
            BusRefDataCommonPackageDescriptor._instance = BusRefDataCommonPackageDescriptor()
            BusRefDataCommonPackageDescriptor._instance._initialize()
            
        return BusRefDataCommonPackageDescriptor._instance
    
    
#End BusContractCorePackageDescriptor Class Definition