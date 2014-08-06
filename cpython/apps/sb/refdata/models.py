from django.db import models
from django.contrib.sites.models import Site
from django.contrib.auth.models import User

from  apps.sb.core import models as crm

    
class ReferenceData(crm.BusinessObject):
    parent_business_object_id = models.OneToOneField(crm.BusinessObject, 
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True, 
                            db_column='parent_business_object_id')
    class Meta:
        db_table = 'refdata_core_reference_data'