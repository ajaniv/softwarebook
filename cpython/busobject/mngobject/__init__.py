#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busobject/mngobject/__init__.py - business object managed object package
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
.. module:: busobject.mngobject
   :synopsis: Package with features required to manage object graphs .
   
The busobject.mngobject  package  supports features required to manage object graphs.
 
It contains the following modules/sub-packages:

- classes.  Introduces concept of a ManagedObject as an abstraction for building object 
  hierarchies and run time environments.
- package.  Run time meta data support.
- test.  Package unit test suite.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'




__all__ = [
    'api',
    'classes',
    'package',
    'xmlutil'
    ]