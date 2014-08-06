from django import forms
from django.contrib import admin

from apps.sb.core import choices as crc

def core_field_sets():
    return ('Core', {
            'fields': (('name', 'name_space', 'description'), 
            ('enabled', 'deleted'), 
            ('annotations', 'attachments', 'sites')),
        })

def core_base_fields():
    return(('id', 'version'), 
            ('update_time','update_user'), 
            ('creation_time', 'creation_user' ), 
            ('enabled', 'deleted','sites',))

def core_base_field_set():
     return ('Core', {
            'classes': ('collapse',),
            'fields': core_base_fields(),
        })

def core_name_fields():
    return (('name', 'name_space'),)

def core_name_field_set():
     return ('Name', {
            'fields': core_name_fields(),
        })

def name_field_sets():
    return ('Name', {
            'fields': (('name', 'name_space', 'description'), 
            ('enabled', 'deleted'), 
            ('annotations', 'attachments', 'sites')),
        })
def advanced_field_sets():
     return ('Advanced options', {
            'classes': ('collapse',),
            'fields': (('version'), ('update_time','update_user'), ('creation_time', 'creation_user' ))
        })

class BaseAdminForm(forms.ModelForm):
    pass
    
class NamedAdminForm(BaseAdminForm):
    def clean(self):
       
        #=======================================================================
        # cleaned_data = self.cleaned_data
        # if cleaned_data.has_key('name_space') and cleaned_data.has_key('name'):
        #    save_name_space = cleaned_data['name_space']
        #    save_name = cleaned_data['name']
        #    results = None
        #    try:
        #        results = self.Meta.model.objects.get(name_space=save_name_space, name=save_name)
        #    except self.Meta.model.DoesNotExist:
        #            pass
        #    else:
        #        if self.instance is not None and results.id != self.instance.id:
        #            raise forms.ValidationError("Object instance with this name (%s) exists in name space (%s)"  
        #                                % (save_name, crc.name_space_display(save_name_space)))
        #=======================================================================
        return super(NamedAdminForm,self).clean()
    
class BaseModelAdmin(admin.ModelAdmin):
    form = BaseAdminForm
    list_display = ('id', 'version','update_time', 'update_user')
    list_filter = ('update_time',)
    date_hierarchy = 'update_time' #TODO@does not seem to have any effect
    readonly_fields = ('id','version', 'creation_time','update_time', 'creation_user', 'update_user')
    ordering = ('id',)
   
    def save_model(self, request, obj, form, change):
        if obj.id is None:
            obj.creation_user = request.user
        obj.update_user = request.user
        super(BaseModelAdmin, self).save_model(request, obj, form, change)
    
    
class NamedModelAdmin(BaseModelAdmin):
    form = NamedAdminForm
    list_display = BaseModelAdmin.list_display + ('name',) 
    list_filter = ('name',) + BaseModelAdmin.list_filter
    
    search_fields = ('name_space',)
    ordering = ('name',)

    

    
        
 