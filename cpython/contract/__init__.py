#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# contract/__init__.py - contract package
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
..  module:: contract
    :synopsis: Contract life cycle management package

The contract package provides facilities for business contract composition from 
underlying building blocks including contract clauses and other contracts.

It its current state it only supports a few  basic contract building blocks.  
In the future vertical industry and business line (i.e. finance interest rate derivatives
sub-packages) may be added 

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'

__all__ = [ 
     
     'core',
          ]