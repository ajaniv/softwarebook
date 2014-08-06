from django.utils.translation import ugettext as _
from django.utils.encoding import force_unicode
from django.http import HttpResponse, HttpResponseRedirect
from django.core.urlresolvers import reverse
from django.template.defaultfilters import escape
from django.contrib import admin
from django.forms.models import BaseInlineFormSet
from django.forms import ModelForm

from django import forms
from django.contrib import admin

from apps.sb.core.admin_utils import NamedModelAdmin
from apps.sb.core.admin_utils import BaseModelAdmin
from apps.sb.core.admin_utils import NamedAdminForm
from apps.sb.core.admin_utils import core_base_field_set
from apps.sb.core.admin_utils import core_name_field_set

import apps.sb.core.const as core_const

from apps.sb.event.models import ScheduledEvent


def _config_obj(obj, request):
    if  obj.id is None:
        obj.creation_user = request.user
        obj.name_space = core_const.NAME_SPACE_EVENT
    obj.update_user = request.user

class ScheduledEventForm(NamedAdminForm):
     
    class Meta:
        model = ScheduledEvent
    def clean(self):
        return super(ScheduledEventForm, self).clean()
        

class ScheduledEventAdmin(NamedModelAdmin):
    form = ScheduledEventForm
    fieldsets = (
        ( 'Event', {
            'fields': (
                       ("name",),
                       ("summary",),
                       ("date","remind"),
                       ("annotations", "attachments", ),
                       ("body", )),}) ,
        core_base_field_set(),
     )
    
    list_display = ("name", "id", "creation_user", "date", "summary")
    
    search_fields = ("name",)
    list_filter = ("creation_user",)
  
    def save_model(self, request, obj, form, change):
        _config_obj(obj, request)
        super(ScheduledEventAdmin, self).save_model(request, obj, form, change)