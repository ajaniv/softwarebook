#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# busxml/schema/api.py - busxml schema api  module
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
..  module:: busxml.xmi.classes
    :synopsis: Base xmi class definitions module




.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

 


#
# TODO: needs end-2-end review, including properties, private, list protection, etc
#

class XMI(object):
    subclass = None
    superclass = None
    def __init__(self, version='', label='', href='', idref='', typexx=None, uuid='', valueOf_=''):
        self.version = version
        self.label = label
        self.href = href
        self.idref = idref
        self.typexx = typexx
        self.uuid = uuid
        self.valueOf_ = valueOf_
    
     
    def get_version(self): return self.version
    def set_version(self, version): self.version = version
    def get_label(self): return self.label
    def set_label(self, label): self.label = label
    def get_href(self): return self.href
    def set_href(self, href): self.href = href
    def get_idref(self): return self.idref
    def set_idref(self, idref): self.idref = idref
    def get_type(self): return self.typexx
    def set_type(self, typexx): self.typexx = typexx
    def get_uuid(self): return self.uuid
    def set_uuid(self, uuid): self.uuid = uuid
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_
   


class PackageReference(object):
    subclass = None
    superclass = None
    def __init__(self, name_attr=None, name=None, version=None):
        self.name_attr = name_attr
        if name is None:
            self.name = []
        else:
            self.name = name
        if version is None:
            self.version = []
        else:
            self.version = version
    
    
    def get_name(self): return self.name
    def set_name(self, name): self.name = name
    def add_name(self, value): self.name.append(value)
    def insert_name(self, index, value): self.name[index] = value
    def get_version(self): return self.version
    def set_version(self, version): self.version = version
    def add_version(self, value): self.version.append(value)
    def insert_version(self, index, value): self.version[index] = value
    def get_name_attr(self): return self.name_attr
    def set_name_attr(self, name_attr): self.name_attr = name_attr
  


class Model(PackageReference):
    subclass = None
    superclass = PackageReference
    def __init__(self, valueOf_=''):
        PackageReference.__init__(self)
        self.valueOf_ = valueOf_
     
     
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_
 
# end class Model


class Import(PackageReference):
    subclass = None
    superclass = PackageReference
    def __init__(self, valueOf_=''):
        PackageReference.__init__(self)
        self.valueOf_ = valueOf_
    
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_
 


class MetaModel(PackageReference):
    subclass = None
    superclass = PackageReference
    def __init__(self, valueOf_=''):
        PackageReference.__init__(self)
        self.valueOf_ = valueOf_
     
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_
 

class Documentation(object):
    subclass = None
    superclass = None
    def __init__(self, owner_attr=None, exporter_attr=None, exporterVersion_attr=None, contact_attr=None, notice_attr=None, longDescription_attr=None, shortDescription_attr=None, contact=None, exporter=None, exporterVersion=None, longDescription=None, shortDescription=None, notice=None, owner=None):
        self.owner_attr = owner_attr
        self.exporter_attr = exporter_attr
        self.exporterVersion_attr = exporterVersion_attr
        self.contact_attr = contact_attr
        self.notice_attr = notice_attr
        self.longDescription_attr = longDescription_attr
        self.shortDescription_attr = shortDescription_attr
        if contact is None:
            self.contact = []
        else:
            self.contact = contact
        if exporter is None:
            self.exporter = []
        else:
            self.exporter = exporter
        if exporterVersion is None:
            self.exporterVersion = []
        else:
            self.exporterVersion = exporterVersion
        if longDescription is None:
            self.longDescription = []
        else:
            self.longDescription = longDescription
        if shortDescription is None:
            self.shortDescription = []
        else:
            self.shortDescription = shortDescription
        if notice is None:
            self.notice = []
        else:
            self.notice = notice
        if owner is None:
            self.owner = []
        else:
            self.owner = owner
    
   
    def get_contact(self): return self.contact
    def set_contact(self, contact): self.contact = contact
    def add_contact(self, value): self.contact.append(value)
    def insert_contact(self, index, value): self.contact[index] = value
    def get_exporter(self): return self.exporter
    def set_exporter(self, exporter): self.exporter = exporter
    def add_exporter(self, value): self.exporter.append(value)
    def insert_exporter(self, index, value): self.exporter[index] = value
    def get_exporterVersion(self): return self.exporterVersion
    def set_exporterVersion(self, exporterVersion): self.exporterVersion = exporterVersion
    def add_exporterVersion(self, value): self.exporterVersion.append(value)
    def insert_exporterVersion(self, index, value): self.exporterVersion[index] = value
    def get_longDescription(self): return self.longDescription
    def set_longDescription(self, longDescription): self.longDescription = longDescription
    def add_longDescription(self, value): self.longDescription.append(value)
    def insert_longDescription(self, index, value): self.longDescription[index] = value
    def get_shortDescription(self): return self.shortDescription
    def set_shortDescription(self, shortDescription): self.shortDescription = shortDescription
    def add_shortDescription(self, value): self.shortDescription.append(value)
    def insert_shortDescription(self, index, value): self.shortDescription[index] = value
    def get_notice(self): return self.notice
    def set_notice(self, notice): self.notice = notice
    def add_notice(self, value): self.notice.append(value)
    def insert_notice(self, index, value): self.notice[index] = value
    def get_owner(self): return self.owner
    def set_owner(self, owner): self.owner = owner
    def add_owner(self, value): self.owner.append(value)
    def insert_owner(self, index, value): self.owner[index] = value
    def get_owner_attr(self): return self.owner_attr
    def set_owner_attr(self, owner_attr): self.owner_attr = owner_attr
    def get_exporter_attr(self): return self.exporter_attr
    def set_exporter_attr(self, exporter_attr): self.exporter_attr = exporter_attr
    def get_exporterVersion_attr(self): return self.exporterVersion_attr
    def set_exporterVersion_attr(self, exporterVersion_attr): self.exporterVersion_attr = exporterVersion_attr
    def get_contact_attr(self): return self.contact_attr
    def set_contact_attr(self, contact_attr): self.contact_attr = contact_attr
    def get_notice_attr(self): return self.notice_attr
    def set_notice_attr(self, notice_attr): self.notice_attr = notice_attr
    def get_longDescription_attr(self): return self.longDescription_attr
    def set_longDescription_attr(self, longDescription_attr): self.longDescription_attr = longDescription_attr
    def get_shortDescription_attr(self): return self.shortDescription_attr
    def set_shortDescription_attr(self, shortDescription_attr): self.shortDescription_attr = shortDescription_attr
 

class Extension(object):
    subclass = None
    superclass = None
    def __init__(self, extenderID='', extender='', valueOf_=''):
        self.extenderID = extenderID
        self.extender = extender
        self.valueOf_ = valueOf_
     
     
    def get_extenderID(self): return self.extenderID
    def set_extenderID(self, extenderID): self.extenderID = extenderID
    def get_extender(self): return self.extender
    def set_extender(self, extender): self.extender = extender
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_



class Difference(object):
    subclass = None
    superclass = None
    def __init__(self, target_attr=None, container_attr=None, target=None, difference=None, container=None):
        self.target_attr = target_attr
        self.container_attr = container_attr
        if target is None:
            self.target = []
        else:
            self.target = target
        self.difference = difference
        self.container = container
     
    def get_target(self): return self.target
    def set_target(self, target): self.target = target
    def add_target(self, value): self.target.append(value)
    def insert_target(self, index, value): self.target[index] = value
    def get_difference(self): return self.difference
    def set_difference(self, difference): self.difference = difference
    def get_container(self): return self.container
    def set_container(self, container): self.container = container
    def get_target_attr(self): return self.target_attr
    def set_target_attr(self, target_attr): self.target_attr = target_attr
    def get_container_attr(self): return self.container_attr
    def set_container_attr(self, container_attr): self.container_attr = container_attr
 
class Target(object):
    subclass = None
    superclass = None
    def __init__(self, valueOf_=''):
        self.valueOf_ = valueOf_
        self.anyAttributes_ = {}
     
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_
    def getAnyAttributes_(self): return self.anyAttributes_
    def setAnyAttributes_(self, anyAttributes_): self.anyAttributes_ = anyAttributes_
 


class Add(Difference):
    subclass = None
    superclass = Difference
    def __init__(self, addition='', position='', valueOf_=''):
        Difference.__init__(self)
        self.addition = addition
        self.position = position
        self.valueOf_ = valueOf_
     
    def get_addition(self): return self.addition
    def set_addition(self, addition): self.addition = addition
    def get_position(self): return self.position
    def set_position(self, position): self.position = position
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_



class Replace(Difference):
    subclass = None
    superclass = Difference
    def __init__(self, position='', replacement='', valueOf_=''):
        Difference.__init__(self)
        self.position = position
        self.replacement = replacement
        self.valueOf_ = valueOf_
     
    def get_position(self): return self.position
    def set_position(self, position): self.position = position
    def get_replacement(self): return self.replacement
    def set_replacement(self, replacement): self.replacement = replacement
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_
 

class Delete(Difference):
    subclass = None
    superclass = Difference
    def __init__(self, valueOf_=''):
        Difference.__init__(self)
        self.valueOf_ = valueOf_
     
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_

class Any(object):
    subclass = None
    superclass = None
    def __init__(self, valueOf_=''):
        self.valueOf_ = valueOf_
        self.anyAttributes_ = {}
    
    def getValueOf_(self): return self.valueOf_
    def setValueOf_(self, valueOf_): self.valueOf_ = valueOf_
    def getAnyAttributes_(self): return self.anyAttributes_
    def setAnyAttributes_(self, anyAttributes_): self.anyAttributes_ = anyAttributes_

