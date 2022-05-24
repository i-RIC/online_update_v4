#----------------------------------------------------------------
# Generated CMake target import file for configuration "Debug".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "iriclib::iriclib" for configuration "Debug"
set_property(TARGET iriclib::iriclib APPEND PROPERTY IMPORTED_CONFIGURATIONS DEBUG)
set_target_properties(iriclib::iriclib PROPERTIES
  IMPORTED_IMPLIB_DEBUG "${_IMPORT_PREFIX}/lib/iriclibd.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_DEBUG "hdf5::hdf5-shared;Poco::Foundation"
  IMPORTED_LOCATION_DEBUG "${_IMPORT_PREFIX}/bin/iriclibd.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS iriclib::iriclib )
list(APPEND _IMPORT_CHECK_FILES_FOR_iriclib::iriclib "${_IMPORT_PREFIX}/lib/iriclibd.lib" "${_IMPORT_PREFIX}/bin/iriclibd.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
