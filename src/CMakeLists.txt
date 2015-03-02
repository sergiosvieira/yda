include_directories(${yda_SOURCE_DIR}/include)
file(GLOB SOURCES "*.cpp")

add_library(yda ${SOURCES} ${HEADERS} ${CMAKE_BINARY_DIR}/include/YPlatform.h)