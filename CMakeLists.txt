cmake_minimum_required(VERSION 3.1)
project(yda)

# Configuring
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeTests")

# Adds SDL
Find_Package(SDL2 REQUIRED)
Find_Package(SDL2_image REQUIRED)

if ( NOT SDL2_FOUND )
   message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL2_FOUND )

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDLIMAGE_INCLUDE_DIR})

link_libraries (
   ${SDL2_LIBRARY}
   ${SDLIMAGE_LIBRARY}
)

subdirs(include src samples)