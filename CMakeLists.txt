cmake_minimum_required(VERSION 3.1)
project(yda)

# Configuring
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/CMakeTests")

# install public api
SET( YDA_INCLUDE_DIR ../../include )


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

#add_subdirectory(src)
#add_subdirectory(include)

SET( PUBLIC_HEADERS
    ${YDA_INCLUDE_DIR}/YFileSystem.h
    ${YDA_INCLUDE_DIR}/YMain.h
    ${YDA_INCLUDE_DIR}/YObject.h
    ${YDA_INCLUDE_DIR}/YObjectManager.h
    ${YDA_INCLUDE_DIR}/YPoint.h
    ${YDA_INCLUDE_DIR}/YSprite.h
    ${YDA_INCLUDE_DIR}/YSpriteHeader.h
    ${YDA_INCLUDE_DIR}/YSpriteSheet.h
    ${YDA_INCLUDE_DIR}/YSTL.h
    ${YDA_INCLUDE_DIR}/YVector.h
    )

SOURCE_GROUP( "Public API" FILES ${PUBLIC_HEADERS} )    

