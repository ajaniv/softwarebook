
import apps
import sbcalendar
from apps.sb import core

class Mapper(object):
	pass
	

class CalendarRuleMapper(Mapper):
	def __init__(self,
				rule=None):
		self.rule =  rule
		
	def calc_to_dict(self):
		mappings = dict()
		mappings ['name'] = self.rule.rule_name
		mappings ['name_space'] = core.const.NAME_SPACE_CALENDAR_RULES
		mappings ['enabled'] = self.rule.enabled_flag
		
		mappings ['holiday_name'] = self.rule.holiday_name
		mappings ['effective_date_start'] = \
			sbcalendar.date.Date.to_python(self.rule.effective_date_start)
			 
		mappings ['effective_date_end'] = \
			sbcalendar.date.Date.to_python(self.rule.effective_date_end)
		
		return mappings
	
	
class WeekendRuleMapper(CalendarRuleMapper):
	def __init__(self, calc_rule=None):
		super(WeekendRuleMapper,self).__init__(calc_rule)
		
	def calc_to_dict(self):
		mappings = super(WeekendRuleMapper, self).calc_to_dict()
		mappings['day_of_week'] = [ index + 1 
								for index in self.rule.weekend_days_index()]
		return mappings
	
class DateRuleMapper(CalendarRuleMapper):
	def __init__(self, calc_rule=None):
		super(DateRuleMapper,self).__init__(calc_rule)
		
	def calc_to_dict(self):
		mappings = super(DateRuleMapper, self).calc_to_dict()
		mappings['weekend_adjustment'] = self.rule.weekend_adjustment
		mappings['weekend_rule'] = self.rule.weekend_rule.rule_name
		mappings['date_exception'] = self.rule.weekend_rule.rule_name
		mappings['holiday_duration'] = self.rule.holiday_duration.value
		mappings['ignore_friday_month_end_flag'] = self.rule.ignore_friday_month_end_flag
		mappings['add_next_year_flag'] = self.rule.add_next_year_flag
		mappings['add_prior_year_flag'] = self.rule.add_prior_year_flag
		

		return mappings

class SpecificDateRuleMapper(DateRuleMapper):
	def __init__(self, calc_rule=None):
		super(SpecificDateRuleMapper,self).__init__(calc_rule)
	
	def calc_to_dict(self):
		mappings = super(SpecificDateRuleMapper, self).calc_to_dict()
		mappings ['date'] = self.rule.date()
		return mappings

class MonthDayRuleMapper(DateRuleMapper):
	def __init__(self, calc_rule=None):
		super(MonthDayRuleMapper,self).__init__(calc_rule)
	
	def calc_to_dict(self):
		mappings = super(MonthDayRuleMapper, self).calc_to_dict()
		
		mappings ['month'] = self.rule.month.as_int()
		mappings ['day_of_month'] = self.rule.day_of_month.as_int()
		return mappings
	
class MonthWeekDayRuleMapper(DateRuleMapper):
	def __init__(self, calc_rule=None):
		super(MonthWeekDayRuleMapper,self).__init__(calc_rule)
	
	def calc_to_dict(self):
		mappings = super(MonthWeekDayRuleMapper, self).calc_to_dict()
		mappings ['month'] = self.rule.month.as_int()
		mappings ['month_week'] = self.rule.month_week.as_int()
		mappings ['week_day'] = self.rule.week_day.as_int()
		
		return mappings
	
	
class LastDayMonthRuleMapper(DateRuleMapper):
	def __init__(self, calc_rule=None):
		super(LastDayMonthRuleMapper,self).__init__(calc_rule)
	
	def calc_to_dict(self):
		mappings = super(LastDayMonthRuleMapper, self).calc_to_dict()
		mappings ['month'] = self.rule.month.as_int()
		mappings ['week_day'] = self.rule.week_day.as_int()
		
		return mappings
	
	
class FirstDayMonthRuleMapper(DateRuleMapper):
	def __init__(self, calc_rule=None):
		super(FirstDayMonthRuleMapper,self).__init__(calc_rule)
	
	def calc_to_dict(self):
		mappings = super(FirstDayMonthRuleMapper, self).calc_to_dict()
		mappings ['month'] = self.rule.month.as_int()
		mappings ['week_day'] = self.rule.week_day.as_int()
		
		return mappings
	
	
_rule_mappings = {
					'MonthDayRule' : (MonthDayRuleMapper, apps.sb.buscal.models.MonthDayRule),
                    'WeekendRule' :  (WeekendRuleMapper, apps.sb.buscal.models.WeekendRule)
                 }

def rule_mapper(cal_rule):
	return _rule_mappings.get(rule.rule_type)
