#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/__init__.py - reference data package
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
.. module:: refdata
   :synopsis: Reference data   package

The Reference data  package  provides reference data foundation required
in order to capture business activity.
It is comprised of the following sub-packages:

- core
- common
- contract.  
- parties
- product
- users
- workspace

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

__all__ = [
	'core',
	'common',
    'contract',
	'parties',
	'product',
	'users',
	'workspace'
    ]
