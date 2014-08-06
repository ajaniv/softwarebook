#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# contract/core/api.py - functions which simplify contract package feature access
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
.. module:: contract.core.api
   :synopsis: Contract core simplified feature access module

Set of functions which simplify access to contract.core features.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

from contract.core.package import BusContractCorePackageDescriptor
import  busxml.core.api

def parse_file(file_name):
    """Parse an xml file containing contract object graph
  
    :param file_name: XML file name.
    :type file_name: str.
    :returns:  BusinessContractWorkspace -- contract object graph container.

    """
    
    package_desc = BusContractCorePackageDescriptor.get_instance()
    root_obj = busxml.core.api.parse_file(file_name, package_desc)
    return root_obj

def export_to_string(obj):
    """Export contract object graph to string
    
    :param obj: Contract object graph container.
    :type obj: BusinessContractWorkspace.
    :returns: unicode -- xml string with underlying contract information
       
    """
    
    package_desc = BusContractCorePackageDescriptor.get_instance()
    buf = busxml.core.api.export_to_string(obj, package_desc)
    return buf