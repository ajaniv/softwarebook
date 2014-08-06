from django.contrib import admin
from apps.sb.date import models as dtm
from apps.sb.date import admin_utils as dtu
admin.site.register(dtm.WeekDay, dtu.WeekDayAdmin)
admin.site.register(dtm.MonthWeek, dtu.MonthWeekAdmin)
admin.site.register(dtm.Month, dtu.MonthAdmin)
admin.site.register(dtm.WeekendAdjustment, dtu.WeekendAdjustmentAdmin)
