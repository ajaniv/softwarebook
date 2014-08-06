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
.. module:: refdata.product.ir.classes
   :synopsis: Reference data product ir classes modules

 


.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

from emf.core.emfutil import check_list
from refdata.core.classes import RefDataDomain
from refdata.core.classes import RefDataGrouping

from refdata.product.core.classes import BusinessProduct

#
# Data representation classes.
#

class BusRefDataProductIRDomain(RefDataDomain):
    
    def __init__(self):
        super(BusRefDataProductIRDomain,self).__init__()
    
# End Class BusRefDataProductIRDomain Definition


class BusRefDataProductIRObjects(RefDataDomain):
     
    def __init__(self):
        super(BusRefDataProductIRObjects,self).__init__()
        self.cash = None
        self.float_ = None
        self.fixed = None
     
    def get_cash(self): return self.cash
    def set_cash(self, cash): self.cash = cash
    @check_list
    def add_cash(self, value): self.cash.append(value)
     
    def get_float(self): return self.float_
    def set_float(self, float_): self.float_ = float_
    @check_list
    def add_float(self, value): self.float_.append(value)
     
    def get_fixed(self): return self.fixed
    def set_fixed(self, fixed): self.fixed = fixed
    @check_list
    def add_fixed(self, value): self.fixed.append(value)
     
    
# End Class BusRefDataProductIRObjects Definition


class CashProduct(BusinessProduct):
     
    def __init__(self):
        super(CashProduct,self).__init__()
     
    
# End Class CashProduct Definition


class CashProductGrouping(RefDataGrouping):
     
    def __init__(self):
        super(CashProductGrouping,self).__init__()
         
    
# End Class CashProductGrouping Definition


class FixedProductGrouping(RefDataGrouping):
    def __init__(self):
        super(FixedProductGrouping,self).__init__()
   
# End Class FixedProductGrouping Definition


class FloatProductGrouping(RefDataGrouping):
    def __init__(self):
        super(FloatProductGrouping,self).__init__()
        
# End Class FloatProductGrouping Definition  


class SimpleRateProduct(BusinessProduct):
     
    def __init__(self, ):
        super(SimpleRateProduct,self).__init__()
        self.refRate = None
       
    def get_refRate(self): 
        return self.refRate
    def set_refRate(self, refRate): 
        self.refRate = refRate
    
    
# End Class SimpleRateProduct Definition


class FloatProduct(SimpleRateProduct):
     
    def __init__(self):
        super(FloatProduct,self).__init__()
       
    
# End Class FloatProduct Definition


class FixedProduct(SimpleRateProduct):
    def __init__(self):
        super(FixedProduct,self).__init__()
     
# end class FixedProduct