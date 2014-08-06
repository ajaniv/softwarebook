from  abc import ABCMeta, abstractmethod, abstractproperty

from common import DelegatedProperty, ReadOnlyDelegatedProperty

    

class CalendarImpl:
    __metaclass__ = ABCMeta
    @abstractmethod
    def get_name(self):
        pass
    @abstractmethod
    def set_name(self, value):
        pass
    
class SBCalendarImpl(CalendarImpl):
    def __init__(self):
        pass
    def get_name(self):
        return 'myname'
    def set_name(self, value):
        print "setting value", value
    
class Calendar(object):
     name = DelegatedProperty('name')
     start = ReadOnlyDelegatedProperty('start')
     
     def __init__(self):
          self.impl = SBCalendarImpl()
     
       
       
       
if __name__ == '__main__':
    cal = Calendar()
    cal.name = "MyName"
    print "cal name:{0}".format(cal.name)
    try:
        del cal.start
    except AttributeError as ex:
        print ex
    try:
        cal.start = 'some'
    except AttributeError as ex:
        print ex
