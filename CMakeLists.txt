cmake_minimum_required(VERSION 3.5)
project(sampleCommand)

# OSX specific flags
if(APPLE)
    set(CMAKE_MACOSX_RPATH 1)
endif()

# Add path to Chad Vernons FindMaya.cmake modules
# https://github.com/chadmv/cgcmake
SET(AUTODESK_DIR /Applications/Autodesk)
set(CMAKE_MODULE_PATH ${AUTODESK_DIR}/Resources/CMake)

# Source files
set(SOURCE_FILES "sampleCommand.cc")

# Output folder
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_LIST_DIR}/lib)

# Find Maya and declar variables:
#   MAYA_FOUND          Defined if a Maya installation has been detected
#   MAYA_EXECUTABLE     Path to Maya's executable
#   MAYA_<lib>_FOUND    Defined if <lib> has been found
#   MAYA_<lib>_LIBRARY  Path to <lib> library
#   MAYA_INCLUDE_DIR    Path to the devkit's include directories
#   MAYA_LIBRARIES      All the Maya libraries
find_package(Maya REQUIRED)

# Build options
include_directories(${MAYA_INCLUDE_DIR})
link_directories(${MAYA_LIBRARY_DIR})
add_library(${PROJECT_NAME} SHARED ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${MAYA_LIBRARIES})
MAYA_PLUGIN(${PROJECT_NAME})