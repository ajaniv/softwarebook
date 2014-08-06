from django.db import models
from django.contrib.auth.models import User


from string import join
from django.db import models
from django.contrib.auth.models import User

from django.db.models.signals import post_save

from apps.sb.core.models import BusinessObject
import apps.sb.core.const as core_const



class ScheduledEvent(BusinessObject):
    parent_business_object_id = models.OneToOneField(BusinessObject, 
                            related_name="%(app_label)s_%(class)s_related",
                            parent_link=True, 
                            db_column='parent_business_object_id')

    summary = models.CharField(max_length=150, blank=False, null=False)
    body = models.TextField(max_length=10000, blank=True, null=True)
    date = models.DateTimeField(blank=False, null=False)
    remind = models.BooleanField(default=False)

    def __unicode__(self):
        if self.name:
            return unicode(self.creation_user) + u" - " + self.name
        else:
            return unicode(self.creation_user) + u" - " + self.summary[:40]

    def short(self):
        if self.summary:
            return "<i>%s</i> - %s" % (self.name, self.summary)
        else:
            return self.name
    short.allow_tags = True

    class Meta:
        verbose_name_plural = "events"
        db_table = 'event_scheduled'