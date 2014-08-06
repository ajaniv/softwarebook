#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/product/core/classes.py - reference data product core classes module
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
.. module:: refdata.product.core.classes
   :synopsis: Reference data product core classes modules

 


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'


from emf.core.classes import EObject
from emf.core.emfutil import check_list

from busobject.core.classes import BusinessObject

from refdata.core.classes import RefDataObject
from refdata.core.classes import Constant
from refdata.core.classes import ConstantsGrouping
from refdata.core.classes import ConstantsDomain
from refdata.core.classes import RefDataDomain


#
# Data representation classes.
#


class BusRefDataProductCoreConstants(ConstantsDomain):
     
    def __init__(self, productFamily=None, productType=None):
        super(BusRefDataProductCoreConstants, self).__init__()
        self.productFamily = None
        self.productType = None
     
    def get_productFamily(self): 
        return self.productFamily
    def set_productFamily(self, productFamily): 
        self.productFamily = productFamily
    @check_list
    def add_productFamily(self, value): 
        self.productFamily.append(value)
     
    def get_productType(self): 
        return self.productType
    def set_productType(self, productType): 
        self.productType = productType
    @check_list
    def add_productType(self, value): 
        self.productType.append(value)
     
    
# End Class BusRefDataProductCoreConstants Definition


class BusRefDataProductCoreDomain(RefDataDomain):
     
    def __init__(self, constants=None):
        super(BusRefDataProductCoreDomain, self).__init__()
     
    
    
# End Class BusRefDataProductCoreDomain Definition


class BusinessProduct(RefDataObject):
     
    def __init__(self):
        super(BusinessProduct, self).__init__()
        self.productType = None
        self.currency = None
     
    def get_productType(self): 
        return self.productType
    def set_productType(self, productType): 
        self.productType = productType
     
    def get_currency(self): 
        return self.currency
    def set_currency(self, currency): 
        self.currency = currency
     
    
# End Class BusinessProduct Definition


class ContractableSpec(BusinessObject):
     
    def __init__(self, ):
        super(ContractableSpec, self).__init__()
        self.product = None
        self.quantity = None
        self.notional = None
     
    def get_product(self): 
        return self.product
    def set_product(self, product): 
        self.product = product
     
    def get_quantity(self): 
        return self.quantity
    def set_quantity(self, quantity): 
        self.quantity = quantity
     
    def get_notional(self): 
        return self.notional
    def set_notional(self, notional): 
        self.notional = notional
     
    
# End Class ContractableSpec Definition


class Money(EObject):
     
    def __init__(self):
        super(Money, self).__init__()
        self.value = None
        self.currency = None
       
     
    def get_currency(self): 
        return self.currency
    def set_currency(self, currency): 
        self.currency = currency
      
    def get_value(self): 
        return self.value
    def set_value(self, value): 
        self.value = value
    
# End Class Money Definition


class ProductFamily(Constant):
     
    def __init__(self):
        super(ProductFamily, self).__init__()
        self.productTypes = None
     
    def get_productTypes(self): 
        return self.productTypes
    def set_productTypes(self, productTypes): 
        self.productTypes = productTypes
    @check_list
    def add_productTypes(self, value): 
        self.productTypes.append(value)
     
    
# End Class ProductFamily Definition


class ProductFamilyGrouping(ConstantsGrouping):
    
    def __init__(self):
        super(ProductFamilyGrouping, self).__init__()
       
    
# End Class ProductFamilyGrouping Definition


class ProductType(Constant):
     
    def __init__(self):
        super(ProductType, self).__init__()
         
  
# End Class ProductType Definition


class ProductTypeGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(ProductTypeGrouping, self).__init__()
         
# End Class ProductTypeGrouping Definition


class Quantity(EObject):
     
    def __init__(self):
        super(Quantity, self).__init__()
        self.value = None
        self.unit = None
         
    def get_unit(self): 
        return self.unit
    def set_unit(self, unit): 
        self.unit = unit
    
    def get_value(self): 
        return self.value
    def set_value(self, value): 
        self.value = value
    
    
# End Class Quantity Definition