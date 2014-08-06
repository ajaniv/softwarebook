from django.core.exceptions import ValidationError
from django.core.exceptions import NON_FIELD_ERRORS

from apps.sb.core import choices as crc

def validate_name(obj):
    """@TODO need to review implementation, should not be required"""
    if hasattr(obj, 'name_space') and hasattr(obj, 'name'):
        dup_detected = False
        saved_name_space = obj.name_space
        saved_name = obj.name
        results = None
        try:
            results = obj.__class__.objects.get(name_space=saved_name_space, name=saved_name)
        except obj.DoesNotExist:
                pass
        except obj.MultipleObjectsReturned:
            dup_detected = True
        else:
            if obj.id is not None and results.id != obj.id:
                dup_detected = True;
        if dup_detected:
            raise ValidationError({NON_FIELD_ERRORS : ["Object instance with this name (%s) exists in name space (%s)"  
                                    % (saved_name, crc.name_space_display(saved_name_space))]})
                
    else:
        raise ValidationError("Object instance missing name and/or namespace")

