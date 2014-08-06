#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/common/classes.py - reference data common classes  module
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
.. module:: refdata.common.classes
   :synopsis: Reference data common classes  module



.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""
__revision__ = '$Id: $'
__version__ = '0.0.1'

from emf.core.emfutil import check_list
from refdata.core.classes import RefDataObject
from refdata.core.classes import Constant
from refdata.core.classes import ConstantsGrouping
from refdata.core.classes import RefDataDomain
from refdata.core.classes import ConstantsDomain

from refdata.core.classes import RefDataGrouping
#
# Data representation classes.
#

class AddressType(Constant):
    
    def __init__(self):
        super(AddressType, self).__init__()
     
    
# End Class AddressType Definition


class AddressTypeGrouping(ConstantsGrouping):
    
    def __init__(self):
        super(AddressTypeGrouping, self).__init__()
         
   
# End Class AddressTypeGrouping Definition


class BusRefDataCommonConstants(ConstantsDomain):
    
    def __init__(self):
        super(AddressTypeGrouping, self).__init__()
        self.addressType = None
        self.unit = None
        self.emailAddressType = None
        self.phoneNumberType = None
        
    
    def get_addressType(self): return self.addressType
    def set_addressType(self, addressType): self.addressType = addressType
    @check_list
    def add_addressType(self, value): self.addressType.append(value)
  
    def get_unit(self): return self.unit
    def set_unit(self, unit): self.unit = unit
    @check_list
    def add_unit(self, value): self.unit.append(value)
  
    def get_emailAddressType(self): return self.emailAddressType
    def set_emailAddressType(self, emailAddressType): self.emailAddressType = emailAddressType
    @check_list
    def add_emailAddressType(self, value): self.emailAddressType.append(value)
     
    def get_phoneNumberType(self): return self.phoneNumberType
    def set_phoneNumberType(self, phoneNumberType): self.phoneNumberType = phoneNumberType
    @check_list
    def add_phoneNumberType(self, value): self.phoneNumberType.append(value)
   
    
# End Class BusRefDataCommonConstants Definition


class BusRefDataCommonDomain(RefDataDomain):
     
    def __init__(self):
        super(BusRefDataCommonDomain, self).__init__()
        self.constants = None
        self.objects = None
         
     
    def get_constants(self): return self.constants
    def set_constants(self, constants): self.constants = constants
    @check_list
    def add_constants(self, value): self.constants.append(value)
    
    def get_objects(self): return self.objects
    def set_objects(self, objects): self.objects = objects
    @check_list
    def add_objects(self, value): self.objects.append(value)
 
    
# End Class BusRefDataCommonDomain Definition


class BusRefDataCommonObjects(RefDataDomain):
     
    def __init__(self):
        super(BusRefDataCommonObjects, self).__init__()
        self.currency = None
        self.rateDescriptor = None
        self.period = None
        self.rate = None
        self.company = None
        self.country = None
        self.person = None
    
    def get_currency(self): return self.currency
    def set_currency(self, currency): self.currency = currency
    @check_list
    def add_currency(self, value): self.currency.append(value)
    
    def get_rateDescriptor(self): return self.rateDescriptor
    def set_rateDescriptor(self, rateDescriptor): self.rateDescriptor = rateDescriptor
    @check_list
    def add_rateDescriptor(self, value): self.rateDescriptor.append(value)
     
    def get_period(self): return self.period
    def set_period(self, period): self.period = period
    @check_list
    def add_period(self, value): self.period.append(value)
     
    def get_rate(self): return self.rate
    def set_rate(self, rate): self.rate = rate
    @check_list
    def add_rate(self, value): self.rate.append(value)
    
    def get_company(self): return self.company
    def set_company(self, company): self.company = company
    @check_list
    def add_company(self, value): self.company.append(value)
  
    def get_country(self): return self.country
    def set_country(self, country): self.country = country
    @check_list
    def add_country(self, value): self.country.append(value)
     
    def get_person(self): return self.person
    def set_person(self, person): self.person = person
    @check_list
    def add_person(self, value): self.person.append(value)
     
    
# End Class BusRefDataCommonObjects Definition


class Company(RefDataObject):
     
    def __init__(self):
        super(Company, self).__init__()
        self.primary = None
        self.emails = None
        self.addresses = None
        self.phones = None
    
    def get_primary(self): return self.primary
    def set_primary(self, primary): self.primary = primary
    
    def get_emails(self): return self.emails
    def set_emails(self, emails): self.emails = emails
    @check_list
    def add_emails(self, value): self.emails.append(value)
    
    def get_addresses(self): return self.addresses
    def set_addresses(self, addresses): self.addresses = addresses
    @check_list
    def add_addresses(self, value): self.addresses.append(value)
   
    def get_phones(self): return self.phones
    def set_phones(self, phones): self.phones = phones
    @check_list
    def add_phones(self, value): self.phones.append(value)
  
    
  
# End Class Company Definition


class CompanyGrouping(RefDataGrouping):
    
    def __init__(self, list=None):
        super(CompanyGrouping, self).__init__()
         
    
# End Class CompanyGrouping RefDataGrouping


class ContactAddress(RefDataObject):
     
    def __init__(self):
        super(ContactAddress, self).__init__()
        self.primary = None
        self.purpose = None
        self.address = None
        self.addressType = None
        
     
   
    def get_addressType(self): return self.addressType
    def set_addressType(self, addressType): self.addressType = addressType
    
    def get_primary(self): return self.primary
    def set_primary(self, primary): self.primary = primary
    
    def get_purpose(self): return self.purpose
    def set_purpose(self, purpose): self.purpose = purpose
     
    def get_address(self): return self.address
    def set_address(self, address): self.address = address
   
# End Class ContactAddress Definition


class ContractableUnit(Constant):
     
    def __init__(self):
        super(ContractableUnit, self).__init__()
    
    
   
# End Class ContractableUnit Definition


class ContractableUnitGrouping(ConstantsGrouping):
     
    def __init__(self):
        super(ContractableUnitGrouping, self).__init__()
        
    
# End Class ContractableUnitGrouping Definition


class Country(RefDataObject):
     
    def __init__(self):
        super(Country, self).__init__()
        self.code = None
         
     
    def get_code(self): return self.code
    def set_code(self, code): self.code = code
     
    
# End Class Country Definition


class CountryGrouping(RefDataGrouping):
     
    def __init__(self, list=None):
        super(CountryGrouping, self).__init__()
     
    
   
# End Class CountryGrouping Definition


class Currency(RefDataObject):
    
    def __init__(self, valueOf_=''):
        super(Currency, self).__init__()
    
    
   
# End Class Currency Definition

#
# TODO: review replacement of grouping classes with  a simple construct that will generate the proper xml
#
class CurrencyGrouping(RefDataGrouping):
     
    def __init__(self, list=None):
        super(CurrencyGrouping, self).__init__()
     
    
# End Class CurrencyGrouping Definition


class EmailAddress(ContactAddress):
    
    def __init__(self):
        super(EmailAddress, self).__init__()
        self.emailAddress = None
        
     
    def get_emailAddress(self): return self.emailAddress
    def set_emailAddress(self, emailAddress): self.emailAddress = emailAddress
     
   
# End Class EmailAddress Definition


class EmailAddressType(Constant):
     
    def __init__(self):
        super(EmailAddressType, self).__init__()
     
    
    
# End Class EmailAddressType Definition


class EmailAddressTypeGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(EmailAddressTypeGrouping, self).__init__()
      
   
# End Class EmailAddressTypeGrouping Definition


class LocationAddress(ContactAddress):
    def __init__(self):
        super(LocationAddress, self).__init__()
        self.countyName = None
        self.stateName = None
        self.cityName = None
        self.zipCode = None
        self.street = None
        self.formattedAddress = None
        self.country = None
        self.buildingNumber = None
        self.valueOf_ = None
   
    def get_countyName(self): return self.countyName
    def set_countyName(self, countyName): self.countyName = countyName
    def get_stateName(self): return self.stateName
    def set_stateName(self, stateName): self.stateName = stateName
    def get_cityName(self): return self.cityName
    def set_cityName(self, cityName): self.cityName = cityName
    def get_zipCode(self): return self.zipCode
    def set_zipCode(self, zipCode): self.zipCode = zipCode
    def get_street(self): return self.street
    def set_street(self, street): self.street = street
    def get_formattedAddress(self): return self.formattedAddress
    def set_formattedAddress(self, formattedAddress): self.formattedAddress = formattedAddress
    def get_country(self): return self.country
    def set_country(self, country): self.country = country
    def get_buildingNumber(self): return self.buildingNumber
    def set_buildingNumber(self, buildingNumber): self.buildingNumber = buildingNumber
   
  
# End Class LocationAddress Definition


class Person(RefDataObject):
    
    def __init__(self):
        super(Person, self).__init__()
        self.personName = None
        self.emails = None
        self.locations = None
        self.phones = None
        self.companies = None
   
    def get_personName(self): return self.personName
    def set_personName(self, personName): self.personName = personName
    
    def get_emails(self): return self.emails
    def set_emails(self, emails): self.emails = emails
    @check_list
    def add_emails(self, value): self.emails.append(value)
   
    def get_locations(self): return self.locations
    def set_locations(self, locations): self.locations = locations
    @check_list
    def add_locations(self, value): self.locations.append(value)
    
    def get_phones(self): return self.phones
    def set_phones(self, phones): self.phones = phones
    @check_list
    def add_phones(self, value): self.phones.append(value)
    
    def get_companies(self): return self.companies
    def set_companies(self, companies): self.companies = companies
    @check_list
    def add_companies(self, value): self.companies.append(value)
    
     
    
# End Class Person Definition


class PersonGrouping(RefDataGrouping):
     
    def __init__(self, list=None):
        super(PersonGrouping, self).__init__()
       
   
# End Class PersonGrouping Definition


class PersonName(RefDataObject):
     
    def __init__(self):
        super(PersonName, self).__init__()
        self.suffiex = None
        self.firstName = None
        self.title = None
        self.lastName = None
        self.middelName = None
        self.nickName = None
         
     
    def get_suffiex(self): return self.suffiex
    def set_suffiex(self, suffiex): self.suffiex = suffiex
    def get_firstName(self): return self.firstName
    def set_firstName(self, firstName): self.firstName = firstName
    def get_title(self): return self.title
    def set_title(self, title): self.title = title
    def get_lastName(self): return self.lastName
    def set_lastName(self, lastName): self.lastName = lastName
    def get_middelName(self): return self.middelName
    def set_middelName(self, middelName): self.middelName = middelName
    def get_nickName(self): return self.nickName
    def set_nickName(self, nickName): self.nickName = nickName
     
    
# End Class PersonName Definition


class PhoneNumber(ContactAddress):
     
    def __init__(self):
        super(PhoneNumber, self).__init__()
        self.countryCode = None
        self.extension = None
        self.regionCode = None
        self.phoneNumber = None
        self.localNumber = None
        self.phoneNumberType = None
     
     
    def get_phoneNumberType(self): return self.phoneNumberType
    def set_phoneNumberType(self, phoneNumberType): self.phoneNumberType = phoneNumberType
  
    def get_countryCode(self): return self.countryCode
    def set_countryCode(self, countryCode): self.countryCode = countryCode
    def get_extension(self): return self.extension
    def set_extension(self, extension): self.extension = extension
     
    def get_regionCode(self): return self.regionCode
    def set_regionCode(self, regionCode): self.regionCode = regionCode
    def get_phoneNumber(self): return self.phoneNumber
    def set_phoneNumber(self, phoneNumber): self.phoneNumber = phoneNumber
    def get_localNumber(self): return self.localNumber
    def set_localNumber(self, localNumber): self.localNumber = localNumber
   
# End Class PhoneNumber Definition


class PhoneNumberType(Constant):
     
    def __init__(self):
        super(PhoneNumberType, self).__init__()
    
   
   
# End Class PhoneNumberType Definition


class PhoneNumberTypeGrouping(ConstantsGrouping):
     
    def __init__(self):
        super(PhoneNumberTypeGrouping, self).__init__()
    
   
# End class PhoneNumberTypeGrouping Definition


class RefRateDescriptor(RefDataObject):
     
    def __init__(self, ):
        super(RefRateDescriptor, self).__init__()
        self.currency = None
     
     
    def get_currency(self): return self.currency
    def set_currency(self, currency): self.currency = currency
     
    
# end class RefRateDescriptor Definition


class RefRateDescriptorGrouping(RefDataGrouping):
     
    def __init__(self, list=None):
        super(RefRateDescriptorGrouping, self).__init__()
    
    
# End Class RefRateDescriptorGrouping Definition


class ReferenceRate(RefDataObject):
     
    def __init__(self):
        super(ReferenceRate, self).__init__()
        self.descriptor = None
        self.period = None
     
    def get_descriptor(self): return self.descriptor
    def set_descriptor(self, descriptor): self.descriptor = descriptor
     
    def get_period(self): return self.period
    def set_period(self, period): self.period = period
   
    
# end class ReferenceRate


class ReferenceRateGrouping(RefDataGrouping):
     
    def __init__(self, list=None):
        super(ReferenceRateGrouping, self).__init__()
    
    
    
# End Class ReferenceRateGrouping Definition


class TimePeriod(RefDataObject):
     
    def __init__(self, valueOf_=''):
        super(TimePeriod, self).__init__()
     
     
   
# End Class TimePeriod Definition


class TimePeriodGrouping(RefDataGrouping):
     
    def __init__(self, list=None):
        super(TimePeriodGrouping, self).__init__()
    
   
    
# End Class TimePeriodGrouping Definition


class Libor(ReferenceRate):
     
    def __init__(self):
        super(Libor, self).__init__()
  
# End Class Libor Definition


class FixedRate(ReferenceRate):
    
    def __init__(self):
        super(FixedRate, self).__init__()
    
# End Class FixedRate Definition
