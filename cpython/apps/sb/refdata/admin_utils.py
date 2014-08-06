from django.contrib import admin

import apps.sb.core.admin_utils as cru
from apps.sb.refdata.models import * #@UnusedWildImport


def refdata_field_sets():
    return cu.common_field_sets()

class ReferenceDataAdmin(cru.NamedModelAdmin):
   pass