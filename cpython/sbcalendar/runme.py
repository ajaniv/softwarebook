'''
Created on Jun 18, 2011

@author: ajaniv
'''


#import calendarp

import sys
import os
sys.path.append('D:/projects/ondalear/python/bin/Win32/Debug')
sys.path.append('D:/projects/ondalear/bin/Win32/Debug')


print "PATH", os.environ["PATH"]
print "extended path: " , sys.path
import calendarp
print "import worked"
busCal = calendarp.BusinessCalendar()
busCal.setCalendarName("someName")
print "CalName: ", busCal.getCalendarName()
date1 =  calendarp.Date()
print "Date: ", date1

