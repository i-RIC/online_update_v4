#----------------------------------------------------------------
# Generated CMake target import file for configuration "Release".
#----------------------------------------------------------------

# Commands may need to know the format version.
set(CMAKE_IMPORT_FILE_VERSION 1)

# Import target "iriclib::iriclib" for configuration "Release"
set_property(TARGET iriclib::iriclib APPEND PROPERTY IMPORTED_CONFIGURATIONS RELEASE)
set_target_properties(iriclib::iriclib PROPERTIES
  IMPORTED_IMPLIB_RELEASE "${_IMPORT_PREFIX}/lib/iriclib.lib"
  IMPORTED_LINK_DEPENDENT_LIBRARIES_RELEASE "hdf5::hdf5-shared;Poco::Foundation"
  IMPORTED_LOCATION_RELEASE "${_IMPORT_PREFIX}/bin/iriclib.dll"
  )

list(APPEND _IMPORT_CHECK_TARGETS iriclib::iriclib )
list(APPEND _IMPORT_CHECK_FILES_FOR_iriclib::iriclib "${_IMPORT_PREFIX}/lib/iriclib.lib" "${_IMPORT_PREFIX}/bin/iriclib.dll" )

# Commands beyond this point should not need to know the version.
set(CMAKE_IMPORT_FILE_VERSION)
