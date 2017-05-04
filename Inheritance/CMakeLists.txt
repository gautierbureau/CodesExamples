cmake_minimum_required (VERSION 3.0.2)

project(mmorpg)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_INSTALL_PREFIX ..)

#set(CMAKE_VERBOSE_MAKEFILE TRUE)

add_definitions(-std=c++11)

add_executable(program main.cpp Personnage.cpp Guerrier.cpp)

install(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/bin/program
  DESTINATION .
  RENAME ${CMAKE_PROJECT_NAME}-program)
