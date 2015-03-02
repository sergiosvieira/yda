subdirs(gfx)

file(GLOB GFX ${CMAKE_CURRENT_SOURCE_DIR}/gfx/*.png)

file(COPY ${GFX} 
	 DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/gfx/)

include_directories(${yda_SOURCE_DIR}/include)
link_directories(${yda_SOURCE_DIR}/src)
file(GLOB SOURCES "*.cpp")
add_executable(Penguin main.cpp ${SOURCES})
target_link_libraries(Penguin yda)