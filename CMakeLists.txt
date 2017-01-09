project(hkdio)
cmake_minimum_required(VERSION 3.0 FATAL_ERROR)

set(CPACK_PACKAGE_VERSION_MAJOR "0")
set(CPACK_PACKAGE_VERSION_MINOR "0")
set(CPACK_PACKAGE_VERSION_PATCH "0")

add_compile_options("-Wall")
add_compile_options("-Wextra")
add_compile_options("-Werror")

set(CMAKE_INSTALL_LIBDIR lib)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake/modules")

find_package(ROOT REQUIRED)
string(REPLACE "." ";" VERSION_LIST ${ROOT_VERSION})
list(GET VERSION_LIST 0 ROOT_VERSION_MAJOR)
if (ROOT_VERSION_MAJOR GREATER 5)
  include(Root6Macros)
endif (ROOT_VERSION_MAJOR GREATER 5)
include(RootMacros)

option (OPENMP "Use OpenMP" ON)

if(OPENMP)
find_package(OpenMP)
if (OPENMP_FOUND)
    set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
    option (USE_OPENMP "Use OpenMP" ON)
endif()
endif()

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/HkdioConfig.h.in"
  "${PROJECT_BINARY_DIR}/HkdioConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")

if(PAR)
add_custom_target(par-all ALL)
endif()

add_subdirectory(HkBase)
add_subdirectory(HkTasks)
add_subdirectory(doc)

set(CPACK_SOURCE_GENERATOR "TGZ")
set(CPACK_SOURCE_PACKAGE_FILE_NAME
  "${CMAKE_PROJECT_NAME}-${CPACK_PACKAGE_VERSION_MAJOR}.${CPACK_PACKAGE_VERSION_MINOR}.${CPACK_PACKAGE_VERSION_PATCH}")
set(CPACK_SOURCE_IGNORE_FILES
  "/build/;/.git/;/tmp/;~$;${CPACK_SOURCE_IGNORE_FILES}")
add_custom_target(dist COMMAND ${CMAKE_MAKE_PROGRAM} package_source) 

include(CPack)

CONFIGURE_FILE(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
  "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake"
  IMMEDIATE @ONLY)

ADD_CUSTOM_TARGET(uninstall
  "${CMAKE_COMMAND}" -P "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake")

