from django.contrib import admin

from apps.sb.event.models import ScheduledEvent



from apps.sb.event.admin_util import ScheduledEventAdmin
 

admin.site.register(ScheduledEvent, ScheduledEventAdmin)
