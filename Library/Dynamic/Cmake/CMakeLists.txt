cmake_minimum_required (VERSION 3.0.2)

project(main)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INSTALL_PREFIX ..)

set(CMAKE_VERBOSE_MAKEFILE TRUE)

set(LIBRARY1_INCLUDE_DIR /home/bureaugau/Codes/CodeExamples/Library/Dynamic/Cmake/Library1)
set(LIBRARY1_DIR /home/bureaugau/Codes/CodeExamples/Library/Dynamic/Cmake/Library1/build/lib)

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${LIBRARY1_INCLUDE_DIR})

link_directories(${LIBRARY1_DIR})

add_definitions(-std=c++14 -fPIC)

add_executable(main main.cpp)
target_link_libraries(main library1)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/bin/main
  DESTINATION .
  RENAME ${CMAKE_PROJECT_NAME}-program)
