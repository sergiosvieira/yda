include_directories(${yda_SOURCE_DIR}/include)
link_directories(${yda_SOURCE_DIR}/src)
add_executable(Penguin main.cpp)
target_link_libraries(Penguin yda)