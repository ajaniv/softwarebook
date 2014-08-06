#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# contract/core/__init__.py - contract core  package
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
..  module:: contract.core 
    :synopsis: Industry agnostic contract  features package

The core  package provides basic contract composition facilities
from simple building blocks including clauses and other contracts.

It contains the following modules:

- api: the primary entry point
- classes: set of classes from which contracts can be composed
- package: rules for contract class creation  designed to support import/export requirements

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'

__all__ = [
    'api',
    'classes',
    'package'
    
    ]