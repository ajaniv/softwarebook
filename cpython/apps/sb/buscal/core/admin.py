#/usr/bin/env python
# -#- coding: utf-8 -#-


#
# dates/admin.py - django dates application admin config
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
.. module:: calendar.admin
   :synopsis: dates django application admin config 

Django calendar application admin  facility registration.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'


from django.contrib import admin
from apps.sb.core.models import * #@UnusedWildImport
import  apps.sb.core.admin_utils  as cru


admin.site.register(ObjectAnnotation, cru.NamedModelAdmin)
admin.site.register(ObjectAttachement, cru.NamedModelAdmin)
