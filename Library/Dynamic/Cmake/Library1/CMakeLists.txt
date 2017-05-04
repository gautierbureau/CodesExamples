cmake_minimum_required (VERSION 3.0.2)

project(Library1)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set (CMAKE_SHARED_LINKER_FLAGS "-current_version 1.0 -compatibility_version 1.0")

add_definitions(-std=c++14)

add_library(library1 SHARED Foo.cpp Faa.cpp)

#target_link_libraries(library1 )