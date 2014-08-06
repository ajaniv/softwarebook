#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# app/sb/core.py - apps sb core  module 
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

..  module:: sb.core
    :synopsis: SB apps core    models



SB apps core models

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>

"""
 
__revision__ = '$Id: $'
__version__ = '0.01'


from django.db import models
from django.contrib.sites.models import Site
from django.contrib.auth.models import User
from django.core.exceptions import ValidationError
from apps.sb.core.validators import validate_name

from apps.sb.core import choices as crc
import apps.sb.core.const as core_const

#@TODO: replace with config, some defaults
_def_site = None
def default_site():
    global _def_site
    if not _def_site:
        _def_site = str(Site.objects.get(domain=core_const.DEFAULT_SITE).id)
    return _def_site
     
#@TODO: rename to basemodel
class CoreModel(models.Model):
    class Meta:
        abstract = True
        
    id = models.AutoField(primary_key=True, unique=True)
    version = models.IntegerField(default=0)
    enabled = models.BooleanField(null=False, blank=True, default=True)
    deleted = models.BooleanField(null=False, blank=True, default=False)
    creation_time = models.DateTimeField(auto_now_add=True)
    creation_user = models.ForeignKey(User, null=False, blank=False, 
                                    related_name="%(app_label)s_%(class)s_related_creation_user")
    update_time = models.DateTimeField(auto_now=True)
    update_user = models.ForeignKey(User, null=False, blank=False, 
                                    related_name="%(app_label)s_%(class)s_related_update_user")
     
    sites = models.ManyToManyField(Site, default=default_site)
     
    


    def save(self, *args, **kwargs):
        """Save an instance
        """
        super(CoreModel, self).save(*args, **kwargs)
        
    def clean(self):
        "@TODO: move version field to derived autoincrement"
        self.version += 1
        super(CoreModel,self).clean()
        
    

class NamedModel(CoreModel):
    name_space = models.PositiveSmallIntegerField(
                            null=False, blank=False,
                            choices=crc.NAME_SPACE_CHOICES)
    
    name = models.CharField(max_length=128, 
                            null=False, blank=False,
                            verbose_name='name')
    
    class Meta:
        abstract = True
        unique_together = (('name_space', 'name',))
        ordering = ["name"]

    def __unicode__(self):
        return self.name
    
    def clean(self):
        #self.validate_unique()
        super(NamedModel,self).clean()
        
    def full_clean(self):
        super(NamedModel,self).full_clean()
        
    def validate_unique(self,exclude=None):
        "@TODO: move to ddl layer?"
        validate_name(self)
        super(NamedModel, self).validate_unique(exclude)


class ObjectAnnotation(NamedModel):
    class Meta:
        db_table = 'core_object_annotation'
        
    annotation = models.TextField(null=False, blank=False)
    

class ObjectAttachement(NamedModel):
    class Meta:
        db_table = 'core_object_attachement'
        
    description = models.TextField(null=True, blank=True)
    attachement = models.FileField(upload_to='attachements/%Y/%m/%d')
    


class BusinessObject(NamedModel):
    class Meta:
        db_table = 'core_business_object'
        
    description = models.TextField(null=True, blank=True)
    annotations = models.ManyToManyField(ObjectAnnotation, null=True, blank=True)
    attachments = models.ManyToManyField(ObjectAttachement, null=True, blank=True)

