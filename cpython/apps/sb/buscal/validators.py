from django.core.exceptions import ValidationError

def validate_holiday_duration(holiday_duration):
    """Validate holiday duration"""
    if holiday_duration <= 0 or holiday_duration > 10:
        raise ValidationError(u'%s invalid holiday duration' % value)
    
    
def validate_year(date):
    """Validate year"""
    if date.year < 2000 or date.year > 9999:
        raise ValidationError(u'%s invalid year' % date.year)
    