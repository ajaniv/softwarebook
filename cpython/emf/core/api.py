#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# emf/core/api.py - functions which simplify emf core  feature access
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
.. module:: emf.core.api
   :synopsis: Eclipse Modeling Framework core features access module

Set of functions which simplify access to emf.core features.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

from emf.core.package import EMFPackageDescriptor
import  busxml.core.api

def parse_file(file_name):
    emf_package_desc = EMFPackageDescriptor.get_instance()
    root_obj = busxml.core.api.parse_file(file_name, emf_package_desc)
    return root_obj

def export_to_string(obj):
    emf_package_desc = EMFPackageDescriptor.get_instance()
    buf = busxml.core.api.export_to_string(obj, emf_package_desc)
    return buf