#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# dates/models.py - django dates application models
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
.. module:: buscal.models
   :synopsis: business calendar django application models

Django dates application model definitions.

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'

__version__ = '0.0.1'


from django.db import models
from django.core import validators
from apps.sb.refdata import models as rdm
from apps.sb.date import choices as dtc

class WeekDay(rdm.ReferenceData):
    parent_reference_data_id = models.OneToOneField(rdm.ReferenceData, 
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True, 
                            db_column='parent_reference_data_id')
    
    day = models.PositiveSmallIntegerField(
                            choices=dtc.WEEK_DAY_CHOICES, 
                            validators=[validators.MinValueValidator(1),
                                        validators.MaxValueValidator(7)], 
                            unique=True, null=False)

    
    class Meta:
        db_table = 'refdata_date_week_day'

class MonthWeek(rdm.ReferenceData):
    parent_reference_data_id = models.OneToOneField(rdm.ReferenceData, 
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True, 
                            db_column='parent_reference_data_id')
    
    week = models.PositiveSmallIntegerField(
                            choices=dtc.MONTH_WEEK_CHOICES, 
                            validators=[validators.MinValueValidator(1),
                                        validators.MaxValueValidator(5)], 
                            unique=True, null=False)

    
    class Meta:
        db_table = 'refdata_date_month_week'

class Month(rdm.ReferenceData):
    parent_reference_data_id = models.OneToOneField(rdm.ReferenceData, 
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True, 
                            db_column='parent_reference_data_id')
    
    month = models.PositiveSmallIntegerField(
                            choices=dtc.MONTH_CHOICES, 
                            validators=[validators.MinValueValidator(1),
                                        validators.MaxValueValidator(12)], 
                            unique=True, null=False)
    
    max_days_in_month = models.PositiveSmallIntegerField(
                            choices=dtc.MONTH_DAY_COUNT_CHOICES, 
                            validators=[validators.MinValueValidator(29),
                                        validators.MaxValueValidator(31)], 
                            null=False)

    
    class Meta:
        db_table = 'refdata_date_month'

class WeekendAdjustment(rdm.ReferenceData):
    parent_reference_data_id = models.OneToOneField(rdm.ReferenceData, 
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True, 
                            db_column='parent_reference_data_id')
    
    adjustment = models.PositiveSmallIntegerField(
                            choices=dtc.WEEKEND_ADJUSTMENT_CHOICES,
                            validators=[validators.MinValueValidator(1),
                                        validators.MaxValueValidator(5)],
                            unique=True, 
                            blank=False)
    
    class Meta:
        db_table = 'refdata_date_weekend_adjustment'
        
        
 

