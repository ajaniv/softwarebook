#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/contract/core/classes.py - reference data contract core classes  module
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
.. module:: refdata.contract.core.classes
   :synopsis: Reference data contract core classes  module



.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

from emf.core.emfutil import check_list

from refdata.core.classes import ConstantsDomain
from refdata.core.classes import RefDataDomain
from refdata.core.classes import Constant
from refdata.core.classes import ConstantsGrouping

class BusRefDataContractCoreConstants(ConstantsDomain):
     
    def __init__(self):
        super(BusRefDataContractCoreConstants, self).__init__()
        self.contractType = None
        self.contractClauseType = None
        self.contractActionType = None
        self.contractInstructionType = None
        self.businessLine = None
        self.contractDomain = None
        self.contractState = None
    
    def get_contractType(self): 
        return self.contractType
    def set_contractType(self, contractType): 
        self.contractType = contractType
    @check_list
    def add_contractType(self, value): 
        self.contractType.append(value)
    
    def get_contractClauseType(self): 
        return self.contractClauseType
    def set_contractClauseType(self, contractClauseType): 
        self.contractClauseType = contractClauseType
    @check_list
    def add_contractClauseType(self, value): 
        self.contractClauseType.append(value)
     
    def get_contractActionType(self): 
        return self.contractActionType
    def set_contractActionType(self, contractActionType): 
        self.contractActionType = contractActionType
    @check_list
    def add_contractActionType(self, value): 
        self.contractActionType.append(value)
     
    def get_contractInstructionType(self): 
        return self.contractInstructionType
    def set_contractInstructionType(self, contractInstructionType): 
        self.contractInstructionType = contractInstructionType
    @check_list
    def add_contractInstructionType(self, value): 
        self.contractInstructionType.append(value)
     
    def get_businessLine(self): 
        return self.businessLine
    def set_businessLine(self, businessLine): 
        self.businessLine = businessLine
    @check_list
    def add_businessLine(self, value): 
        self.businessLine.append(value)
    
    def get_contractDomain(self): 
        return self.contractDomain
    def set_contractDomain(self, contractDomain): 
        self.contractDomain = contractDomain
    @check_list
    def add_contractDomain(self, value): 
        self.contractDomain.append(value)
     
    def get_contractState(self): 
        return self.contractState
    def set_contractState(self, contractState): 
        self.contractState = contractState
    @check_list
    def add_contractState(self, value): 
        self.contractState.append(value)
    
   
# End Class BusRefDataContractCoreConstants Definition


class BusRefDataContractCoreDomain(RefDataDomain):
     
    def __init__(self):
        super(BusRefDataContractCoreDomain, self).__init__()
        
     
   
     
# End Class BusRefDataContractCoreDomain Definition


class BusinessContractActionType(Constant):
     
    def __init__(self ):
        super(BusinessContractActionType, self).__init__()
     
    
    
# End Class BusinessContractActionType Definition


class BusinessContractActionTypeGrouping(ConstantsGrouping):
     
    def __init__(self):
        super(BusinessContractActionType, self).__init__()
        
   
# End Class BusinessContractActionTypeGrouping Definition


class BusinessContractClauseType(Constant):
     
    def __init__(self):
        super(BusinessContractClauseType, self).__init__()
         
     
    
# End Class BusinessContractClauseType Definition


class BusinessContractClauseTypeGrouping(ConstantsGrouping):
     
    def __init__(self):
        super(BusinessContractClauseTypeGrouping, self).__init__()
         
     
    
   
# End Class BusinessContractClauseTypeGrouping Definition


class BusinessContractInstructionType(Constant):
     
    def __init__(self):
        super(BusinessContractInstructionType, self).__init__()
        
    
# End Class BusinessContractInstructionType Definition


class BusinessContractInstructionTypeGrouping(ConstantsGrouping):
     
    def __init__(self):
        super(BusinessContractInstructionTypeGrouping, self).__init__()
         
    
# End Class BusinessContractInstructionTypeGrouping Definition


class BusinessLine(Constant):
    def __init__(self):
        super(BusinessLine, self).__init__()
    
# End Class BusinessLine Definition


class BusinessLineGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(BusinessLineGrouping, self).__init__()
         
    
# End Class BusinessLineGrouping Definition


class ContractDomain(Constant):
     
    def __init__(self):
        
        super(ContractDomain, self).__init__()
         
   
# End Class ContractDomain Definition


class ContractDomainGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(ContractDomainGrouping, self).__init__()
         
      
    
# End Class ContractDomainGrouping Domain


class ContractState(Constant):
     
    def __init__(self):
        super(ContractState, self).__init__()
        
    
# End Class ContractState Definiiton


class ContractStateGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(ContractStateGrouping, self).__init__()
         
    
# End Class ContractStateGrouping Definition


class ContractType(Constant):
     
    def __init__(self):
        super(ContractType, self).__init__()
      
   
# End Class ContractType Definition


class ContractTypeGrouping(ConstantsGrouping):
     
    def __init__(self):
        super(ContractTypeGrouping, self).__init__()
         
   
# End Class ContractTypeGrouping Definition
