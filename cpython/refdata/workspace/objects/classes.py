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
.. module:: refdata.workspace.objects.classes
   :synopsis: Reference data workspace objects classes  module

 

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

from emf.core.emfutil import check_list
from busobject.core.classes import BusinessWorkspace

#
# Data representation classes.
#

class RefDataWorkspace(BusinessWorkspace):
     
    def __init__(self):
        super(RefDataWorkspace, self).__init__()
        self.refDataDomain = None
        self.coreRefDataDomain = None
        self.comRefDataDomain = None
        self.partiesDomain = None
        self.productCoreDomain = None
        self.productIRDomain = None
        self.usersDomain = None
        self.busContractDomain = None
    
    def get_refDataDomain(self): return self.refDataDomain
    def set_refDataDomain(self, refDataDomain): self.refDataDomain = refDataDomain
    @check_list
    def add_refDataDomain(self, value): self.refDataDomain.append(value)
     
    def get_coreRefDataDomain(self): return self.coreRefDataDomain
    def set_coreRefDataDomain(self, coreRefDataDomain): self.coreRefDataDomain = coreRefDataDomain
    @check_list
    def add_coreRefDataDomain(self, value): self.coreRefDataDomain.append(value)
     
    def get_comRefDataDomain(self): return self.comRefDataDomain
    def set_comRefDataDomain(self, comRefDataDomain): self.comRefDataDomain = comRefDataDomain
    @check_list
    def add_comRefDataDomain(self, value): self.comRefDataDomain.append(value)
     
    def get_partiesDomain(self): return self.partiesDomain
    def set_partiesDomain(self, partiesDomain): self.partiesDomain = partiesDomain
    @check_list
    def add_partiesDomain(self, value): self.partiesDomain.append(value)
    
    def get_productCoreDomain(self): return self.productCoreDomain
    def set_productCoreDomain(self, productCoreDomain): self.productCoreDomain = productCoreDomain
    @check_list
    def add_productCoreDomain(self, value): self.productCoreDomain.append(value)
     
    def get_productIRDomain(self): return self.productIRDomain
    def set_productIRDomain(self, productIRDomain): self.productIRDomain = productIRDomain
    @check_list
    def add_productIRDomain(self, value): self.productIRDomain.append(value)
     
    def get_usersDomain(self): return self.usersDomain
    def set_usersDomain(self, usersDomain): self.usersDomain = usersDomain
    @check_list
    def add_usersDomain(self, value): self.usersDomain.append(value)
     
    def get_busContractDomain(self): return self.busContractDomain
    def set_busContractDomain(self, busContractDomain): self.busContractDomain = busContractDomain
    @check_list
    def add_busContractDomain(self, value): self.busContractDomain.append(value)
     
    
# End Class RefDataWorkspace Definition