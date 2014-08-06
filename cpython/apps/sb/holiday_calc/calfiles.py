
import sbcalendar.calendar
from apps.sb.holiday_calc import config

from apps.sb.holiday_calc import mappings
import   apps.sb.buscal.models as buscal_models
def load(calendar_file, grammar_file=None):
    """load a calendar file using the designated grammar"""
    grammar_file = grammar_file or config.cal_grammar_file
    calendar_file = str(calendar_file.replace('\\', '/'))
    cache_cl = sbcalendar.calendar.CalendarCache
    
    cache = cache_cl.load_from_xml_file(grammar_file, 
                                        calendar_file)
    #TODO: enhance beyond single calendar
    calendar_names = cache.calendar_names()
    calendar_name  = calendar_names[0]
    calendar = cache.find_calendar(calendar_name)
   
    return calendar

def save(cal):
    rules = cal.rules()
    dgrules = []
    for rule in rules:
        print rule.rule_name
        mapr, cls  = mappings.rule_mapper(rule)
        attr_dict = mappings.calc_to_dict()
        if attr_dict:
            dgrule = cls(**attr_dict)
            dgrules.append(dgrule)
        
        