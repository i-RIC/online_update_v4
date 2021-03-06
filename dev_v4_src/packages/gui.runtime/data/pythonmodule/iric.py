# This file was automatically generated by SWIG (http://www.swig.org).
# Version 3.0.8
#
# Do not make changes to this file unless you know what you are doing--modify
# the SWIG interface file instead.





from sys import version_info
if version_info >= (2, 6, 0):
    def swig_import_helper():
        from os.path import dirname
        import imp
        fp = None
        try:
            fp, pathname, description = imp.find_module('_iric', [dirname(__file__)])
        except ImportError:
            import _iric
            return _iric
        if fp is not None:
            try:
                _mod = imp.load_module('_iric', fp, pathname, description)
            finally:
                fp.close()
            return _mod
    _iric = swig_import_helper()
    del swig_import_helper
else:
    import _iric
del version_info
try:
    _swig_property = property
except NameError:
    pass  # Python < 2.2 doesn't have 'property'.


def _swig_setattr_nondynamic(self, class_type, name, value, static=1):
    if (name == "thisown"):
        return self.this.own(value)
    if (name == "this"):
        if type(value).__name__ == 'SwigPyObject':
            self.__dict__[name] = value
            return
    method = class_type.__swig_setmethods__.get(name, None)
    if method:
        return method(self, value)
    if (not static):
        if _newclass:
            object.__setattr__(self, name, value)
        else:
            self.__dict__[name] = value
    else:
        raise AttributeError("You cannot add attributes to %s" % self)


def _swig_setattr(self, class_type, name, value):
    return _swig_setattr_nondynamic(self, class_type, name, value, 0)


def _swig_getattr_nondynamic(self, class_type, name, static=1):
    if (name == "thisown"):
        return self.this.own()
    method = class_type.__swig_getmethods__.get(name, None)
    if method:
        return method(self)
    if (not static):
        return object.__getattr__(self, name)
    else:
        raise AttributeError(name)

def _swig_getattr(self, class_type, name):
    return _swig_getattr_nondynamic(self, class_type, name, 0)


def _swig_repr(self):
    try:
        strthis = "proxy of " + self.this.__repr__()
    except Exception:
        strthis = ""
    return "<%s.%s; %s >" % (self.__class__.__module__, self.__class__.__name__, strthis,)

try:
    _object = object
    _newclass = 1
except AttributeError:
    class _object:
        pass
    _newclass = 0


class SwigPyIterator(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, SwigPyIterator, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, SwigPyIterator, name)

    def __init__(self, *args, **kwargs):
        raise AttributeError("No constructor defined - class is abstract")
    __repr__ = _swig_repr
    __swig_destroy__ = _iric.delete_SwigPyIterator
    __del__ = lambda self: None

    def value(self):
        return _iric.SwigPyIterator_value(self)

    def incr(self, n=1):
        return _iric.SwigPyIterator_incr(self, n)

    def decr(self, n=1):
        return _iric.SwigPyIterator_decr(self, n)

    def distance(self, x):
        return _iric.SwigPyIterator_distance(self, x)

    def equal(self, x):
        return _iric.SwigPyIterator_equal(self, x)

    def copy(self):
        return _iric.SwigPyIterator_copy(self)

    def next(self):
        return _iric.SwigPyIterator_next(self)

    def __next__(self):
        return _iric.SwigPyIterator___next__(self)

    def previous(self):
        return _iric.SwigPyIterator_previous(self)

    def advance(self, n):
        return _iric.SwigPyIterator_advance(self, n)

    def __eq__(self, x):
        return _iric.SwigPyIterator___eq__(self, x)

    def __ne__(self, x):
        return _iric.SwigPyIterator___ne__(self, x)

    def __iadd__(self, n):
        return _iric.SwigPyIterator___iadd__(self, n)

    def __isub__(self, n):
        return _iric.SwigPyIterator___isub__(self, n)

    def __add__(self, n):
        return _iric.SwigPyIterator___add__(self, n)

    def __sub__(self, *args):
        return _iric.SwigPyIterator___sub__(self, *args)
    def __iter__(self):
        return self
SwigPyIterator_swigregister = _iric.SwigPyIterator_swigregister
SwigPyIterator_swigregister(SwigPyIterator)

class IntVector(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, IntVector, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, IntVector, name)
    __repr__ = _swig_repr

    def iterator(self):
        return _iric.IntVector_iterator(self)
    def __iter__(self):
        return self.iterator()

    def __nonzero__(self):
        return _iric.IntVector___nonzero__(self)

    def __bool__(self):
        return _iric.IntVector___bool__(self)

    def __len__(self):
        return _iric.IntVector___len__(self)

    def __getslice__(self, i, j):
        return _iric.IntVector___getslice__(self, i, j)

    def __setslice__(self, *args):
        return _iric.IntVector___setslice__(self, *args)

    def __delslice__(self, i, j):
        return _iric.IntVector___delslice__(self, i, j)

    def __delitem__(self, *args):
        return _iric.IntVector___delitem__(self, *args)

    def __getitem__(self, *args):
        return _iric.IntVector___getitem__(self, *args)

    def __setitem__(self, *args):
        return _iric.IntVector___setitem__(self, *args)

    def pop(self):
        return _iric.IntVector_pop(self)

    def append(self, x):
        return _iric.IntVector_append(self, x)

    def empty(self):
        return _iric.IntVector_empty(self)

    def size(self):
        return _iric.IntVector_size(self)

    def swap(self, v):
        return _iric.IntVector_swap(self, v)

    def begin(self):
        return _iric.IntVector_begin(self)

    def end(self):
        return _iric.IntVector_end(self)

    def rbegin(self):
        return _iric.IntVector_rbegin(self)

    def rend(self):
        return _iric.IntVector_rend(self)

    def clear(self):
        return _iric.IntVector_clear(self)

    def get_allocator(self):
        return _iric.IntVector_get_allocator(self)

    def pop_back(self):
        return _iric.IntVector_pop_back(self)

    def erase(self, *args):
        return _iric.IntVector_erase(self, *args)

    def __init__(self, *args):
        this = _iric.new_IntVector(*args)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def push_back(self, x):
        return _iric.IntVector_push_back(self, x)

    def front(self):
        return _iric.IntVector_front(self)

    def back(self):
        return _iric.IntVector_back(self)

    def assign(self, n, x):
        return _iric.IntVector_assign(self, n, x)

    def resize(self, *args):
        return _iric.IntVector_resize(self, *args)

    def insert(self, *args):
        return _iric.IntVector_insert(self, *args)

    def reserve(self, n):
        return _iric.IntVector_reserve(self, n)

    def capacity(self):
        return _iric.IntVector_capacity(self)
    __swig_destroy__ = _iric.delete_IntVector
    __del__ = lambda self: None
IntVector_swigregister = _iric.IntVector_swigregister
IntVector_swigregister(IntVector)

class Application(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Application, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Application, name)
    __repr__ = _swig_repr
    __swig_getmethods__["init"] = lambda x: _iric.Application_init
    if _newclass:
        init = staticmethod(_iric.Application_init)

    def __init__(self):
        this = _iric.new_Application()
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _iric.delete_Application
    __del__ = lambda self: None

    def openProject(self, filename):
        return _iric.Application_openProject(self, filename)

    def saveProject(self):
        return _iric.Application_saveProject(self)

    def saveProjectAs(self, filename):
        return _iric.Application_saveProjectAs(self, filename)

    def closeProject(self):
        return _iric.Application_closeProject(self)

    def pre(self):
        return _iric.Application_pre(self)

    def solver(self):
        return _iric.Application_solver(self)

    def calcResult(self):
        return _iric.Application_calcResult(self)
Application_swigregister = _iric.Application_swigregister
Application_swigregister(Application)

def Application_init(path):
    return _iric.Application_init(path)
Application_init = _iric.Application_init

class CalculationResult(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, CalculationResult, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, CalculationResult, name)
    __repr__ = _swig_repr
    ExportType_ESRIShape = _iric.CalculationResult_ExportType_ESRIShape
    ExportType_CSV = _iric.CalculationResult_ExportType_CSV
    ExportType_VtkBinary = _iric.CalculationResult_ExportType_VtkBinary
    ExportType_vtkAscii = _iric.CalculationResult_ExportType_vtkAscii

    def __init__(self, app):
        this = _iric.new_CalculationResult(app)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def length(self):
        return _iric.CalculationResult_length(self)

    def exportToFolder(self, folderName, prefix, steps, type):
        intVecSteps = IntVector()
        for v in steps:
            intVecSteps.push_back(v)
        return _iric.CalculationResult_exportToFolder(self, folderName, prefix,intVecSteps, type)
    __swig_destroy__ = _iric.delete_CalculationResult
    __del__ = lambda self: None
CalculationResult_swigregister = _iric.CalculationResult_swigregister
CalculationResult_swigregister(CalculationResult)

class GeoData(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, GeoData, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, GeoData, name)
    __repr__ = _swig_repr

    def __init__(self, dataItem):
        this = _iric.new_GeoData(dataItem)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def geoDataItem(self):
        return _iric.GeoData_geoDataItem(self)
    __swig_destroy__ = _iric.delete_GeoData
    __del__ = lambda self: None
GeoData_swigregister = _iric.GeoData_swigregister
GeoData_swigregister(GeoData)

class GeoDataGroup(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, GeoDataGroup, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, GeoDataGroup, name)
    __repr__ = _swig_repr

    def __init__(self, item):
        this = _iric.new_GeoDataGroup(item)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _iric.delete_GeoDataGroup
    __del__ = lambda self: None

    def name(self):
        return _iric.GeoDataGroup_name(self)

    def importer(self, name):
        return _iric.GeoDataGroup_importer(self, name)

    def add(self, data):
        return _iric.GeoDataGroup_add(self, data)
GeoDataGroup_swigregister = _iric.GeoDataGroup_swigregister
GeoDataGroup_swigregister(GeoDataGroup)

class GeoDataImporter(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, GeoDataImporter, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, GeoDataImporter, name)
    __repr__ = _swig_repr

    def __init__(self, importer, att, groupItem):
        this = _iric.new_GeoDataImporter(importer, att, groupItem)
        try:
            self.this.append(this)
        except Exception:
            self.this = this

    def importGeoData(self, filename):
        return _iric.GeoDataImporter_importGeoData(self, filename)
    __swig_destroy__ = _iric.delete_GeoDataImporter
    __del__ = lambda self: None
GeoDataImporter_swigregister = _iric.GeoDataImporter_swigregister
GeoDataImporter_swigregister(GeoDataImporter)

class GridType(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, GridType, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, GridType, name)
    __repr__ = _swig_repr

    def __init__(self, gtItem):
        this = _iric.new_GridType(gtItem)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _iric.delete_GridType
    __del__ = lambda self: None

    def name(self):
        return _iric.GridType_name(self)

    def isPrimary(self):
        return _iric.GridType_isPrimary(self)

    def geoDataGroup(self, name):
        return _iric.GridType_geoDataGroup(self, name)

    def geoDataGroups(self):
        return _iric.GridType_geoDataGroups(self)

    def mapAllGeoData(self):
        return _iric.GridType_mapAllGeoData(self)

    def mapGeoData(self, name):
        return _iric.GridType_mapGeoData(self, name)

    def gridZones(self):
        return _iric.GridType_gridZones(self)
GridType_swigregister = _iric.GridType_swigregister
GridType_swigregister(GridType)

class GridZone(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, GridZone, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, GridZone, name)
    __repr__ = _swig_repr

    def __init__(self, item):
        this = _iric.new_GridZone(item)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _iric.delete_GridZone
    __del__ = lambda self: None

    def mapAllGeoData(self):
        return _iric.GridZone_mapAllGeoData(self)

    def mapGeoData(self, name):
        return _iric.GridZone_mapGeoData(self, name)
GridZone_swigregister = _iric.GridZone_swigregister
GridZone_swigregister(GridZone)

class Pre(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Pre, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Pre, name)
    __repr__ = _swig_repr

    def __init__(self, app):
        this = _iric.new_Pre(app)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _iric.delete_Pre
    __del__ = lambda self: None

    def gridType(self, name):
        return _iric.Pre_gridType(self, name)

    def gridTypes(self):
        return _iric.Pre_gridTypes(self)

    def geoDataGroup(self, name):
        return _iric.Pre_geoDataGroup(self, name)

    def geoDataGroups(self):
        return _iric.Pre_geoDataGroups(self)

    def mapAllGeoData(self):
        return _iric.Pre_mapAllGeoData(self)

    def mapGeoData(self, name):
        return _iric.Pre_mapGeoData(self, name)

    def clearGridTypes(self):
        return _iric.Pre_clearGridTypes(self)
Pre_swigregister = _iric.Pre_swigregister
Pre_swigregister(Pre)

class Solver(_object):
    __swig_setmethods__ = {}
    __setattr__ = lambda self, name, value: _swig_setattr(self, Solver, name, value)
    __swig_getmethods__ = {}
    __getattr__ = lambda self, name: _swig_getattr(self, Solver, name)
    __repr__ = _swig_repr

    def __init__(self, app):
        this = _iric.new_Solver(app)
        try:
            self.this.append(this)
        except Exception:
            self.this = this
    __swig_destroy__ = _iric.delete_Solver
    __del__ = lambda self: None

    def start(self):
        return _iric.Solver_start(self)

    def stop(self):
        return _iric.Solver_stop(self)

    def startAndWaitForFinish(self):
        return _iric.Solver_startAndWaitForFinish(self)
Solver_swigregister = _iric.Solver_swigregister
Solver_swigregister(Solver)

# This file is compatible with both classic and new-style classes.


