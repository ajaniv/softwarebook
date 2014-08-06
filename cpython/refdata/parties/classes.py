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
.. module:: refdata.parties.classes
   :synopsis: Reference data parties  classes module

 


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

from emf.core.emfutil import check_list
from busobject.core.classes import BusinessObject
from refdata.core.classes import RefDataObject
from refdata.core.classes import RefDataDomain
from refdata.core.classes import Constant
from refdata.core.classes import ConstantsDomain
from refdata.core.classes import RefDataGrouping
from refdata.core.classes import ConstantsGrouping


#
# Data representation classes.
#

class BusRefDataPartiesConstants(ConstantsDomain):
     
    def __init__(self):
        super(BusRefDataPartiesConstants, self).__init__()
        self.role = None
        self.counterPartyType = None
        self.legalEntityType = None
        self.transactionSide = None
    
    def get_role(self): 
        return self.role
    def set_role(self, role): 
        self.role = role
    @check_list
    def add_role(self, value): 
        self.role.append(value)
    
    def get_counterPartyType(self): 
        return self.counterPartyType
    def set_counterPartyType(self, counterPartyType): 
        self.counterPartyType = counterPartyType
    @check_list
    def add_counterPartyType(self, value): 
        self.counterPartyType.append(value)
    
    def get_legalEntityType(self): 
        return self.legalEntityType
    def set_legalEntityType(self, legalEntityType): 
        self.legalEntityType = legalEntityType
    @check_list
    def add_legalEntityType(self, value): 
        self.legalEntityType.append(value)
     
    def get_transactionSide(self): 
        return self.transactionSide
    def set_transactionSide(self, transactionSide): 
        self.transactionSide = transactionSide
    @check_list
    def add_transactionSide(self, value): 
        self.transactionSide.append(value)
    
   
# End Class BusRefDataPartiesConstants Definition


class BusRefDataPartiesDomain(RefDataDomain):
     
    def __init__(self):
        super(BusRefDataPartiesDomain, self).__init__()
       
  
# End Class BusRefDataPartiesDomain Definition


class BusRefDataPartiesObjects(RefDataDomain):
     
    def __init__(self):
        super(BusRefDataPartiesObjects, self).__init__()
        self.party = None
        self.corporateEntity = None
        self.individualEntity = None
    
    def get_party(self): 
        return self.party
    def set_party(self, party): 
        self.party = party
    @check_list
    def add_party(self, value): 
        self.party.append(value)
    
    def get_corporateEntity(self): 
        return self.corporateEntity
    def set_corporateEntity(self, corporateEntity): 
        self.corporateEntity = corporateEntity
    @check_list
    def add_corporateEntity(self, value): 
        self.corporateEntity.append(value)
    
    def get_individualEntity(self): 
        return self.individualEntity
    def set_individualEntity(self, individualEntity): 
        self.individualEntity = individualEntity
    @check_list
    def add_individualEntity(self, value): 
        self.individualEntity.append(value)
     
    
# End Class BusRefDataPartiesObjects Definition


class CorporateLegalEntityGrouping(RefDataGrouping):
   
    def __init__(self):
        super(CorporateLegalEntityGrouping, self).__init__()
        
    
# End Class CorporateLegalEntityGrouping Definition


class CounterParty(RefDataObject):
     
    def __init__(self ):
        super(CounterParty, self).__init__()
        self.partyType = None
        self.legalEntity = None
        self.location = None
     
    def get_partyType(self): return self.partyType
    def set_partyType(self, partyType): self.partyType = partyType
    
    def get_legalEntity(self): return self.legalEntity
    def set_legalEntity(self, legalEntity): self.legalEntity = legalEntity
   
    def get_location(self): return self.location
    def set_location(self, location): self.location = location
     
    def get_location_attr(self): return self.location_attr
    def set_location_attr(self, location_attr): self.location_attr = location_attr
    
    
# End Class CounterParty Definition


class CounterPartyGrouping(RefDataGrouping):
     
    def __init__(self):
        super(CounterPartyGrouping, self).__init__()
       
    
# End Class CounterPartyGrouping Definition


class CounterPartyRole(Constant):
     
    def __init__(self):
        super(CounterPartyRole, self).__init__()
     
     
    
# End Class CounterPartyRole Definition


class CounterPartyRoleGrouping(ConstantsGrouping):
     
    def __init__(self):
        super(CounterPartyRoleGrouping, self).__init__()
         
     
     
    
# End Class CounterPartyRoleGrouping Definition


class CounterPartySpec(BusinessObject):
     
    def __init__(self):
        super(CounterPartySpec, self).__init__()
        self.role = None
        self.party = None
        self.side = None
     
    def get_role(self): 
        return self.role
    def set_role(self, role): 
        self.role = role
    
    def get_party(self): 
        return self.party
    def set_party(self, party): 
        self.party = party
     
    def get_side(self): 
        return self.side
    def set_side(self, side): 
        self.side = side
    
    def get_party_attr(self): 
        return self.party_attr
    def set_party_attr(self, party_attr): 
        self.party_attr = party_attr
     
    def get_role_attr(self): 
        return self.role_attr
    def set_role_attr(self, role_attr): 
        self.role_attr = role_attr
    
# End Class CounterPartySpec Definition


class CounterPartyType(Constant):
     
    def __init__(self, ):
        super(CounterPartyType, self).__init__()
       
  
# End Class CounterPartyType Definition


class CounterPartyTypeGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(CounterPartyTypeGrouping, self).__init__()
    
# End Class CounterPartyTypeGrouping Definition


class IndividualLegalEntityGrouping(RefDataGrouping):
    
    def __init__(self, list=None):
        super(IndividualLegalEntityGrouping, self).__init__()
       
    
# End Class IndividualLegalEntityGrouping Definition


class LegalEntity(RefDataObject):
     
    def __init__(self):
        def __init__(self):
            super(LegalEntity, self).__init__()
            self.entityType = None
     
    def get_entityType(self): 
        return self.entityType
    def set_entityType(self, entityType): 
        self.entityType = entityType
     
    
# End Class LegalEntity Definition


class LegalEntityType(Constant):
     
    def __init__(self):
        super(LegalEntityType, self).__init__()
       
    
# End Class LegalEntityType Definition


class LegalEntityTypeGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(LegalEntityTypeGrouping, self).__init__()
        
    
# End Class LegalEntityTypeGrouping Definition


class TransactionSide(Constant):
     
    def __init__(self, ):
        super(TransactionSide, self).__init__()
        
    
# End Class TransactionSide Definition


class TransactionSideGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(TransactionSideGrouping, self).__init__()
        
    
# End Class TransactionSideGrouping Definition


class IndividualLegalEntity(LegalEntity):
     
    def __init__(self,):
        super(IndividualLegalEntity, self).__init__()
        self.person = None
     
    def get_person(self): 
        return self.person
    def set_person(self, person): 
        self.person = person
   
    
# End Class IndividualLegalEntity Definition


class CorporateLegalEntity(LegalEntity):
     
    def __init__(self):
        super(CorporateLegalEntity, self).__init__()
        self.company = None
     
    def get_company(self): return self.company
    def set_company(self, company): self.company = company
     
    
# End Class CorporateLegalEntity Definition