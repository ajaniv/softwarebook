from django.contrib import admin
from  apps.sb.core import admin_utils as cru
from  apps.sb.refdata import admin_utils as rdu




class WeekDayAdmin(rdu.ReferenceDataAdmin):
  
    fieldsets = (
        ('Week day', {
            'fields': ('day',),
        }) ,
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )
    
class MonthWeekAdmin(rdu.ReferenceDataAdmin):
  
    fieldsets = (
        ('Month week', {
            'fields': ('week',),
        }) ,
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )
    
class MonthAdmin(rdu.ReferenceDataAdmin):
  
    fieldsets = (
        ('Month', {
            'fields': ('month', 'max_days_in_month'),
        }) ,
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )

class WeekendAdjustmentAdmin(rdu.ReferenceDataAdmin):
  
    fieldsets = (
        ("Weekend Adjustment", {
            'fields': ('adjustment',),
        }) ,
        cru.core_field_sets(),
        cru.advanced_field_sets(),
        
    )