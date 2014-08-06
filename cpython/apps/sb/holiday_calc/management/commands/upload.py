import sys
import os
from django.core.management.base import BaseCommand, CommandError



from apps.sb.settings import MEDIA_ROOT
from apps.sb.holiday_calc import calfiles

class Command(BaseCommand):
    args = '<poll_id file ...>'
    help = 'Uploads specified calendar files to db'

    def handle(self, *args, **options):
        if not  hasattr(self, 'stdout'):
            self.stdout = sys.stdout
        if not hasattr(self, 'stderr'):
            self.stderr = sys.stderr
        
        self.stdout.write('upload started\n')
        for file in args:
#            try:
#                poll = Poll.objects.get(pk=int(poll_id))
#            except Poll.DoesNotExist:
#                raise CommandError('Poll "%s" does not exist' % poll_id)
#
#            poll.opened = False
#            poll.save()
            self.stdout.write('Processing  "%s"\n' % file)
            cal = calfiles.load(file)
            calfiles.save(cal)
         
            
            
if __name__ == '__main__':
    
    file = os.path.join(MEDIA_ROOT, 
                        'upload\user\\ajaniv\\calendar\\us_federal_holiday_calendar_specs.xml').replace('\\', '/')

    cmd = Command()
    cmd.handle(file)