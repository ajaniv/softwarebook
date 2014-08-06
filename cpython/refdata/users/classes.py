#/usr/bin/env python
# -#- coding: utf-8 -#-

#
# refdata/users/classes.py - reference data users classes  module
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
.. module:: refdata.users.classes
   :synopsis: Reference data users classes  module

 

.. moduleauthor:: Amnon Janiv <amnon.janiv@ondalear.com>
"""

__revision__ = '$Id: $'
__version__ = '0.0.1'



from emf.core.emfutil import check_list
from refdata.core.classes import RefDataObject
from refdata.core.classes import Constant
from refdata.core.classes import ConstantsGrouping
from refdata.core.classes import RefDataDomain
from refdata.core.classes import RefDataGrouping
from refdata.core.classes import ConstantsDomain
#
# Data representation classes.
#

class FunctionalRole(Constant):
    
    def __init__(self, ):
        super(FunctionalRole, self).__init__()
    
# End Class FunctionalRole Definition


class FunctionalRoleGrouping(ConstantsGrouping):
    
    def __init__(self, list=None):
        super(FunctionalRoleGrouping, self).__init__()
        
    
# end class FunctionalRoleGrouping Definition


class SystemUser(RefDataObject):
     
    def __init__(self):
        super(SystemUser, self).__init__()
        self.loginId = None
        self.person = None
        self.groups = None
        self.primaryGroup = None
        self.currentGroup = None
        self.roles = None
        self.primaryRole = None
        self.currentRole = None
        self.userType = None
     
    def get_person(self): return self.person
    def set_person(self, person): self.person = person
    
    def get_groups(self): return self.groups
    def set_groups(self, groups): self.groups = groups
    @check_list
    def add_groups(self, value): self.groups.append(value)
    
    def get_primaryGroup(self): return self.primaryGroup
    def set_primaryGroup(self, primaryGroup): self.primaryGroup = primaryGroup
     
    def get_currentGroup(self): return self.currentGroup
    def set_currentGroup(self, currentGroup): self.currentGroup = currentGroup
     
    def get_roles(self): return self.roles
    def set_roles(self, roles): self.roles = roles
    @check_list
    def add_roles(self, value): self.roles.append(value)
    
    def get_primaryRole(self): return self.primaryRole
    def set_primaryRole(self, primaryRole): self.primaryRole = primaryRole
     
    def get_currentRole(self): return self.currentRole
    def set_currentRole(self, currentRole): self.currentRole = currentRole
     
    def get_userType(self): return self.userType
    def set_userType(self, userType): self.userType = userType
    
    def get_loginId(self): return self.loginId
    def set_loginId(self, loginId): self.loginId = loginId
   
# End Class SystemUser Definition


class SystemUserGroup(RefDataObject):
     
    def __init__(self, users):
        super(SystemUserGroup, self).__init__()
        self.subGroups = None
        self.users = None
    
    def get_subGroups(self): return self.subGroups
    def set_subGroups(self, subGroups): self.subGroups = subGroups
    @check_list
    def add_subGroups(self, value): self.subGroups.append(value)
     
    def get_users(self): return self.users
    def set_users(self, users): self.users = users
    @check_list
    def add_users(self, value): self.users.append(value)
     
    
# End Class SystemUserGroup Definition


class SystemUserGroupGrouping(RefDataGrouping):
     
    def __init__(self):
        super(SystemUserGroupGrouping, self).__init__()
      
    
# End Class SystemUserGroupGrouping Definition


class SystemUserGrouping(RefDataGrouping):
    
    def __init__(self):
        super(SystemUserGrouping, self).__init__()
        
    
# End Cass SystemUserGrouping Definition


class UserType(Constant):
     
    def __init__(self):
        super(UserType, self).__init__()
     
    
# End Class UserType Definition


class UserTypeGrouping(ConstantsGrouping):
     
    def __init__(self, list=None):
        super(UserTypeGrouping, self).__init__()
        
       
    
# End Class UserTypeTypeGrouping Definition


class BusRefDataUsersConstants(ConstantsDomain):
    
    def __init__(self, ):
        super(BusRefDataUsersConstants, self).__init__()
        self.role = None
        self.userType = None
     
    def get_role(self): return self.role
    def set_role(self, role): self.role = role
    @check_list
    def add_role(self, value): self.role.append(value)
     
    def get_userType(self): return self.userType
    def set_userType(self, userType): self.userType = userType
    @check_list
    def add_userType(self, value): self.userType.append(value)
    
    
# End Class BusRefDataUsersConstants Definition


class BusRefDataUsersDomain(RefDataDomain):
    
    def __init__(self):
        super(BusRefDataUsersDomain, self).__init__()
     
    
    
# End Class BusRefDataUsersDomain Definition


class BusRefDataUsersObjects(RefDataDomain):
     
    def __init__(self):
        super(BusRefDataUsersObjects, self).__init__()
        self.user = None
        self.userGroup = None
     
    def get_user(self): return self.user
    def set_user(self, user): self.user = user
    @check_list
    def add_user(self, value): self.user.append(value)
     
    def get_userGroup(self): return self.userGroup
    def set_userGroup(self, userGroup): self.userGroup = userGroup
    @check_list
    def add_userGroup(self, value): self.userGroup.append(value)
    
    
# End Class BusRefDataUsersObjects Definition