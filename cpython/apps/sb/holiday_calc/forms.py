import time
import datetime
from django import forms
from django.forms.extras.widgets import SelectDateWidget
from django.forms.widgets import Textarea
from django.forms.widgets import CheckboxSelectMultiple
from django.utils.safestring import mark_safe

from django.core.exceptions import ValidationError

from sb.date.choices  import MONTH_CHOICES
from sb.date.choices  import WEEK_DAY_CHOICES
from  sb.holiday_calc import widgets
from  sb.holiday_calc import config
_current_year = int(time.localtime()[0])
_current_year_end = datetime.date(_current_year, 12, 31)
_year_max = 9999
_today = datetime.date.today()


class HorizontalCheckboxSelectMultiple(CheckboxSelectMultiple):
    def render(self, name, value, attrs=None, choices=()):
        raw_output = super(HorizontalCheckboxSelectMultiple, self).render(name, 
                                                                value, 
                                                                attrs, 
                                                                choices)
        return mark_safe(raw_output.replace('<li>', 
                                            '<li  style="display: inline;">'))


class FileListForm(forms.Form):
    from_year = forms.IntegerField(label='From year:', 
                                   required=True, 
                                   help_text='Holiday calculation start year',
                                   initial=_current_year, min_value=2000, 
                                   max_value=_year_max
                                   )
    to_year = forms.IntegerField(label='To year:', 
                                 required=False, 
                                 help_text='Holiday calculation end year (inclusive)',
                                 min_value=2000, 
                                 max_value=_year_max
                                   )
    
    from_date = forms.DateField(label='From date:', 
                                   required=True, 
                                   widget=SelectDateWidget,
                                   initial=_today,
                                   help_text='Holiday calculation start date'
                                   )
    to_date = forms.DateField(label='To date:', 
                                 required=False, 
                                 widget=SelectDateWidget,
                                 initial=_current_year_end,
                                 help_text='Holiday calculation end date (exclusive)'
                                   )
    CALC_TYPE_CHOICES = (('1', 'Is Business Day'), ('2', 'Is Holiday' ), ('3', 'Is Weekend'))
   
    
    
    date_calc_type = forms.MultipleChoiceField(required=False, 
                                               widget=HorizontalCheckboxSelectMultiple(),
                                               choices=CALC_TYPE_CHOICES,
                                               initial='1'
                                               )
    is_holiday_1 = forms.DateField(required=False, 
                                   initial=_today,
                                   help_text='Date as yyyy-mm-dd'
                                   )
    is_holiday_2 = forms.DateField(required=False, 
                                   initial=_today,
                                   help_text='Date as yyyy-mm-dd'
                                   )
    is_holiday_3 = forms.DateField(required=False, 
                                   initial=_today,
                                   help_text='Date as yyyy-mm-dd'
                                   )
    
    VIEW_TYPE_CHOICES = ((1, 'Summary'), (2, 'Calendar' ), (3, 'Detailed'))
    view_type = forms.ChoiceField(required=False,
                                               choices=VIEW_TYPE_CHOICES, 
                                               
                                               initial=1)
    _is_holiday_prefix='is_holiday_'
    _is_holiday_max_input = 10
    def __init__(self, *args, **kwargs):
        super(FileListForm, self).__init__(*args, **kwargs) # Call to ModelForm constructor
        self.fields['from_year'].widget.attrs['size'] = 4
        self.fields['to_year'].widget.attrs['size'] = 4
        
        for index in xrange(1, FileListForm._is_holiday_max_input):
            field_name = FileListForm._is_holiday_prefix + str(index)
            if field_name in  self.fields:
                 self.fields[field_name].widget.attrs['size'] = 10
            else:
                break
       
        
    @property
    def calc_choices(self):
        return len(FileListForm.CALC_TYPE_CHOICES)
    
    @property
    def holiday_fields(self):
        fields = []
        for index in xrange(1, FileListForm._is_holiday_max_input):
            field_name = FileListForm._is_holiday_prefix + str(index)
            if field_name in  self.fields:
                fields.append(self[field_name])
            else:
                break
        return fields 
        
        
    def clean(self):
        
        cleaned_data = super(FileListForm, self).clean()
        from_year = cleaned_data.get("from_year")
        to_year = cleaned_data.get("to_year")
        if not self.data or not 'files' in self.data:
            raise ValidationError("Select a calendar file")
        if from_year and to_year and to_year < from_year:
            # We know these are not in self._errors now (see discussion
            # below).
            msg = u"To year can not be less than from year"
            self._errors["to_year"] = self.error_class([msg])
            # These fields are no longer valid. Remove them from the
            # cleaned data.
            del cleaned_data["to_year"]
        # Always return the full collection of cleaned data.
        return cleaned_data


from apps.sb.buscal import models as bcm  

class CalendarForm(forms.Form):
    calendar_name = forms.CharField(label='Name:', 
                                   required=False,
                                   
                                   help_text='Calendar name used in searches',
                                   )
    description = forms.CharField(label='Description:',
                                  widget=Textarea,
                                  required=False)
    
    def __init__(self, *args, **kwargs):
        super(CalendarForm, self).__init__(*args, **kwargs) # Call to ModelForm constructor
        self.fields['calendar_name'].widget.attrs['size'] = 64
        self.fields['calendar_name'].widget.attrs['readonly'] = True
        self.fields['description'].widget.attrs['rows'] = 5
        self.fields['description'].widget.attrs['readonly'] = True
        
        
class CalendarRuleForm(forms.Form):
    name = forms.CharField(label='Name:', 
                                   required=False,
                                   help_text='Calendar name used in searches',
                                   )
    
    holiday_name = forms.CharField(label='Holiday:', 
                                   required = False,
                                   help_text='Holiday name',
                                   )
    
    enabled = forms.BooleanField (label = 'Enabled:', 
                                       required = False,
                                       help_text = ' Determines if rule is used in date calculations')
    
    effective_date_start = forms.DateField(label = 'Start:',
                                           required = 'False')
    
    effective_date_end = forms.DateField(label = 'End:',
                                           required = 'False')
    
    def __init__(self, *args, **kwargs):
        super(CalendarRuleForm, self).__init__(*args, **kwargs) 
        for field in self.fields:
            self.fields[field].widget.attrs['readonly'] = True
            
    def prepare(self, *args, **kwargs):
        pass

class DateRuleForm(CalendarRuleForm):
    weekend_rule = forms.URLField(label='Weekend:',
                                  required=False,
                                  help_text='Weekend rule link',
                                  widget=widgets.LinkFieldWidget(text='rule',url='%s'))
    holiday_duration = forms.IntegerField(label='Duration:', 
                                   required=False, 
                                   help_text='Holiday length in days',
                                   min_value=1, 
                                   max_value=31
                                   )

    def __init__(self, *args, **kwargs):  
        super(DateRuleForm, self).__init__(*args, **kwargs)
        
    
    def prepare(self, *args, **kwargs):
        if 'calendar' in kwargs:
            calendar = kwargs['calendar']
            rule_name = self.initial['weekend_rule']
            wknd_widget = self.fields['weekend_rule'].widget
            wknd_widget.url = '/holiday_calc/rule/' \
             + calendar.calendar_name + '/' + rule_name + '/'
        
class WeekendRuleForm(CalendarRuleForm):
    def __init__(self, *args, **kwargs):
        super(WeekendRuleForm, self).__init__(*args, **kwargs)
        
    weekend_days = forms.MultipleChoiceField(label='Days:' ,
                                    choices=WEEK_DAY_CHOICES,
                                   required=False,
                                   
                                   help_text='Month name')
            
class MonthDayRuleForm(DateRuleForm):
    month = forms.ChoiceField(label='Month:', 
                                    choices=MONTH_CHOICES,
                                   required=False,
                                   
                                   help_text='Month name'
                                   )
    day_of_month = forms.IntegerField(label='Day:', 
                                   required=False, 
                                   help_text='Day of month',
                                   min_value=1, 
                                   max_value=31
                                   )
    def __init__(self, *args, **kwargs):
        super(MonthDayRuleForm, self).__init__(*args, **kwargs)
        


class ImportCalendarFileForm(forms.Form):
    file = forms.FileField(label='File:',
                       help_text='Import calendar file name',
                       required=True)
#    path = forms.FilePathField(path=config.file_path, 
#                               match=".*\.xml$", 
#                               #help_text='Calendar file name',
#                               recursive=True)
   


from sb.buscal import admin_utils
from sb.buscal import models
from apps.sb.holiday_calc import mappings

_form_mappings = {'MonthDayRule' : (MonthDayRuleForm, 
                                    mappings.MonthDayRuleMapper),
                  'WeekendRule' :   (WeekendRuleForm,
                                     mappings.WeekendRuleMapper)}
def create_form(calendar, 
                rule):
    entry = _form_mappings.get(rule.rule_type())
    if entry:
        rule_maper = entry[1](rule)
        rule_dict = rule_maper.calc_to_dict()
        #model_rule.holiday_name = rule.holiday_name
       # model_rule.month = Month() #rule.month.as_int()
       # model_rule.day_of_month = rule.day_of_month.as_int()
        rule_form = entry[0](initial=rule_dict,
                             )
        
        rule_form.prepare(calendar=calendar,rule=rule)
        

    return rule_form