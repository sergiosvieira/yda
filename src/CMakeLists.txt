include_directories(${yda_SOURCE_DIR}/include)
file(GLOB SOURCES "*.cpp")
add_library(yda ${SOURCES})
