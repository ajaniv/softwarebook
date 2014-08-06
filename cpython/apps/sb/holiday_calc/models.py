from django.db import models
from django.contrib.sites.models import Site
from django.contrib.auth.models import User


class FileDescriptor(models.Model):
    name =  models.CharField(max_length=128, 
                            null=False, blank=False,
                            verbose_name='file name')
    
    
