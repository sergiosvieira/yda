cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

project(yda)

# Adds SDL
Find_Package(SDL2 REQUIRED)
Find_Package(SDL2_image REQUIRED)

if ( NOT SDL2_FOUND )
   message ( FATAL_ERROR "SDL not found!" )
endif ( NOT SDL2_FOUND )

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDLIMAGE_INCLUDE_DIR})

link_libraries (
   ${SDL_LIBRARY}
   ${SDLIMAGE_LIBRARY}
   SDLmain # Sadly not included in SDL_LIBRARY variable
)

subdirs(src)
