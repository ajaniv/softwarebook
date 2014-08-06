# This file was automatically generated by SWIG (http://www.swig.org).
# Version 2.0.4
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.



from sys import version_info
if version_info >= (2,6,0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_example', [dirname(__file__)])
        except ImportError:
            import _example
            return _example
        if fp is not None:
            try:
                _mod = imp.load_module('_example', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _example = swig_import_helper()
    del swig_import_helper
else:
    import _example
del version_info
try:
    _swig_property = property
except NameError:
    pass # Python < 2.2 doesn't have 'property'.
def _swig_setattr_nondynamic(self,class_type,name,value,static=1):
    if (name == "thisown"): return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name,None)
    if method: return method(self,value)
    if (not static):
        self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)

def _swig_setattr(self,class_type,name,value):
    return _swig_setattr_nondynamic(self,class_type,name,value,0)

def _swig_getattr(self,class_type,name):
    if (name == "thisown"): return self.this.own()
    method = class_type.__swig_getmethods__.get(name,None)
    if method: return method(self)
    raise AttributeError(name)

def _swig_repr(self):
    try: strthis = "proxy of " + self.this.__repr__()
    except: strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object : pass
    _newclass = 0


class SwigPyIterator(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SwigPyIterator, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SwigPyIterator, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _example.delete_SwigPyIterator
    __del__ = lambda self : None;
    def value(self): return _example.SwigPyIterator_value(self)
    def incr(self, n = 1): return _example.SwigPyIterator_incr(self, n)
    def decr(self, n = 1): return _example.SwigPyIterator_decr(self, n)
    def distance(self, *args): return _example.SwigPyIterator_distance(self, *args)
    def equal(self, *args): return _example.SwigPyIterator_equal(self, *args)
    def copy(self): return _example.SwigPyIterator_copy(self)
    def next(self): return _example.SwigPyIterator_next(self)
    def __next__(self): return _example.SwigPyIterator___next__(self)
    def previous(self): return _example.SwigPyIterator_previous(self)
    def advance(self, *args): return _example.SwigPyIterator_advance(self, *args)
    def __eq__(self, *args): return _example.SwigPyIterator___eq__(self, *args)
    def __ne__(self, *args): return _example.SwigPyIterator___ne__(self, *args)
    def __iadd__(self, *args): return _example.SwigPyIterator___iadd__(self, *args)
    def __isub__(self, *args): return _example.SwigPyIterator___isub__(self, *args)
    def __add__(self, *args): return _example.SwigPyIterator___add__(self, *args)
    def __sub__(self, *args): return _example.SwigPyIterator___sub__(self, *args)
    def __iter__(self): return self
SwigPyIterator_swigregister = _example.SwigPyIterator_swigregister
SwigPyIterator_swigregister(SwigPyIterator)

class Shape(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Shape, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Shape, name)
    def __init__(self, *args, **kwargs): raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _example.delete_Shape
    __del__ = lambda self : None;
    __swig_setmethods__["x"] = _example.Shape_x_set
    __swig_getmethods__["x"] = _example.Shape_x_get
    if _newclass:x = _swig_property(_example.Shape_x_get, _example.Shape_x_set)
    __swig_setmethods__["y"] = _example.Shape_y_set
    __swig_getmethods__["y"] = _example.Shape_y_get
    if _newclass:y = _swig_property(_example.Shape_y_get, _example.Shape_y_set)
    def move(self, *args): return _example.Shape_move(self, *args)
    def area(self): return _example.Shape_area(self)
    def perimeter(self): return _example.Shape_perimeter(self)
    __swig_setmethods__["nshapes"] = _example.Shape_nshapes_set
    __swig_getmethods__["nshapes"] = _example.Shape_nshapes_get
    if _newclass:nshapes = _swig_property(_example.Shape_nshapes_get, _example.Shape_nshapes_set)
Shape_swigregister = _example.Shape_swigregister
Shape_swigregister(Shape)
cvar = _example.cvar

class Circle(Shape):
    __swig_setmethods__ = {}
    for _s in [Shape]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, Circle, name, value)
    __swig_getmethods__ = {}
    for _s in [Shape]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, Circle, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _example.new_Circle(*args)
        try: self.this.append(this)
        except: self.this = this
    def area(self): return _example.Circle_area(self)
    def perimeter(self): return _example.Circle_perimeter(self)
    __swig_destroy__ = _example.delete_Circle
    __del__ = lambda self : None;
Circle_swigregister = _example.Circle_swigregister
Circle_swigregister(Circle)

class Square(Shape):
    __swig_setmethods__ = {}
    for _s in [Shape]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, Square, name, value)
    __swig_getmethods__ = {}
    for _s in [Shape]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, Square, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _example.new_Square(*args)
        try: self.this.append(this)
        except: self.this = this
    def area(self): return _example.Square_area(self)
    def perimeter(self): return _example.Square_perimeter(self)
    __swig_destroy__ = _example.delete_Square
    __del__ = lambda self : None;
Square_swigregister = _example.Square_swigregister
Square_swigregister(Square)

class Rectangle(Shape):
    __swig_setmethods__ = {}
    for _s in [Shape]: __swig_setmethods__.update(getattr(_s,'__swig_setmethods__',{}))
    __setattr__ = lambda self, name, value: _swig_setattr(self, Rectangle, name, value)
    __swig_getmethods__ = {}
    for _s in [Shape]: __swig_getmethods__.update(getattr(_s,'__swig_getmethods__',{}))
    __getattr__ = lambda self, name: _swig_getattr(self, Rectangle, name)
    __repr__ = _swig_repr
    def __init__(self, *args): 
        this = _example.new_Rectangle(*args)
        try: self.this.append(this)
        except: self.this = this
    def area(self): return _example.Rectangle_area(self)
    def perimeter(self): return _example.Rectangle_perimeter(self)
    def getSides(self): return _example.Rectangle_getSides(self)
    __swig_destroy__ = _example.delete_Rectangle
    __del__ = lambda self : None;
Rectangle_swigregister = _example.Rectangle_swigregister
Rectangle_swigregister(Rectangle)

class DoubleVector(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, DoubleVector, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, DoubleVector, name)
    __repr__ = _swig_repr
    def iterator(self): return _example.DoubleVector_iterator(self)
    def __iter__(self): return self.iterator()
    def __nonzero__(self): return _example.DoubleVector___nonzero__(self)
    def __bool__(self): return _example.DoubleVector___bool__(self)
    def __len__(self): return _example.DoubleVector___len__(self)
    def pop(self): return _example.DoubleVector_pop(self)
    def __getslice__(self, *args): return _example.DoubleVector___getslice__(self, *args)
    def __setslice__(self, *args): return _example.DoubleVector___setslice__(self, *args)
    def __delslice__(self, *args): return _example.DoubleVector___delslice__(self, *args)
    def __delitem__(self, *args): return _example.DoubleVector___delitem__(self, *args)
    def __getitem__(self, *args): return _example.DoubleVector___getitem__(self, *args)
    def __setitem__(self, *args): return _example.DoubleVector___setitem__(self, *args)
    def append(self, *args): return _example.DoubleVector_append(self, *args)
    def empty(self): return _example.DoubleVector_empty(self)
    def size(self): return _example.DoubleVector_size(self)
    def clear(self): return _example.DoubleVector_clear(self)
    def swap(self, *args): return _example.DoubleVector_swap(self, *args)
    def get_allocator(self): return _example.DoubleVector_get_allocator(self)
    def begin(self): return _example.DoubleVector_begin(self)
    def end(self): return _example.DoubleVector_end(self)
    def rbegin(self): return _example.DoubleVector_rbegin(self)
    def rend(self): return _example.DoubleVector_rend(self)
    def pop_back(self): return _example.DoubleVector_pop_back(self)
    def erase(self, *args): return _example.DoubleVector_erase(self, *args)
    def __init__(self, *args): 
        this = _example.new_DoubleVector(*args)
        try: self.this.append(this)
        except: self.this = this
    def push_back(self, *args): return _example.DoubleVector_push_back(self, *args)
    def front(self): return _example.DoubleVector_front(self)
    def back(self): return _example.DoubleVector_back(self)
    def assign(self, *args): return _example.DoubleVector_assign(self, *args)
    def resize(self, *args): return _example.DoubleVector_resize(self, *args)
    def insert(self, *args): return _example.DoubleVector_insert(self, *args)
    def reserve(self, *args): return _example.DoubleVector_reserve(self, *args)
    def capacity(self): return _example.DoubleVector_capacity(self)
    __swig_destroy__ = _example.delete_DoubleVector
    __del__ = lambda self : None;
DoubleVector_swigregister = _example.DoubleVector_swigregister
DoubleVector_swigregister(DoubleVector)

# This file is compatible with both classic and new-style classes.


