cmake_minimum_required(VERSION 3.20)

if("${CMAKE_SOURCE_DIR}" STREQUAL "${CMAKE_BINARY_DIR}")
    if(NOT DEFINED IN_SOURCE_BUILD)
        message(FATAL_ERROR
          "CMake generation not allowed within the source directory!"
          "\n Remove \"${CMAKE_SOURCE_DIR}/CMakeCache.txt\" and try again from another folder, e.g.:"
          "\n "
          "\n rm CMakeCache.txt"
          "\n mkdir build"
          "\n cd build"
          "\n cmake ../"
          "\n "
          "\n Alternatively define IN_SOURCE_BUILD to force this option (not recommended!)"
        )
    endif()
endif()

# ------------------------------------------------------------------------------------------------
# Options
option(ITC_ARCHITECTURE "Set the build architecture to either x64 or x86" "x64")
option(ITC_BUILD_TESTS "Include tests into the solution/makefile" ON)

# ------------------------------------------------------------------------------------------------
# Set architecture acording to ITC_ARCHITECTURE option above
if(UNIX AND NOT APPLE)
    if("${ITC_ARCHITECTURE}" STREQUAL "x64")
    	message(STATUS "Setting Build Architecture (Linux) to x64")
        set(CMAKE_C_FLAGS "-m64")
        set(CMAKE_CXX_FLAGS "-m64")
    elseif("${ITC_ARCHITECTURE}" STREQUAL "x86")
    	message(STATUS "Setting Build Architecture (Linux) to x86")
        set(CMAKE_C_FLAGS "-m32")
        set(CMAKE_CXX_FLAGS "-m32")
    endif()
elseif(WIN32)
    # Should be automatically set using the -A switch in the .bat script
elseif(APPLE)
    if("${ITC_ARCHITECTURE}" STREQUAL "x64")
        set(CMAKE_OSX_ARCHITECTURES "x86_64")
	    message(STATUS "Setting Build Architecture (Apple) to x86_64")
    elseif("${ITC_ARCHITECTURE}" STREQUAL "x86")
    	message(STATUS "Setting Build Architecture (Apple) to i386")
        set(CMAKE_OSX_ARCHITECTURES "i386")
    endif()
endif()

# ------------------------------------------------------------------------------------------------
# Set common options
set(VIOLENT_BUILD_TESTS OFF CACHE BOOL "" FORCE)

# ------------------------------------------------------------------------------------------------
# Initialize the Solution Project
project("ITC")

# ------------------------------------------------------------------------------------------------
# Required for Solution Folders
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# TODO: Enable for gcc and clang only
if(UNIX)
    # set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC -Wno-attributes")
    # set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wno-attributes")
    
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fPIC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
    
	# set(CMAKE_C_COMPILER gcc-10)
	# set(CMAKE_CXX_COMPILER g++-10)
endif()

if(NOT DEFINED CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# ------------------------------------------------------------------------------------------------
# Set Debug AND Release for Multi-Configuration Generators
if(CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES "Debug;RelWithDebInfo;Release" CACHE STRING "" FORCE)
else()
    set(CMAKE_CONFIGURATION_TYPES "${CMAKE_BUILD_TYPE}")
endif()

# ------------------------------------------------------------------------------------------------
# Set default string stuff to be unicode
add_definitions(-DUNICODE)
add_definitions(-D_UNICODE)

# ------------------------------------------------------------------------------------------------
# Set C++ Version requirement
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED true)
set(CMAKE_CXX_EXTENSIONS OFF)

# ------------------------------------------------------------------------------------------------
# Helper Functions
include("CMake/Macros.cmake")

add_subdirectory("extern")
add_subdirectory("src")

if(ITC_BUILD_TESTS)
    add_subdirectory("tests")
endif()





