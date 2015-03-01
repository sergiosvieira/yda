subdirs(gfx)
include_directories(${yda_SOURCE_DIR}/include)
link_directories(${yda_SOURCE_DIR}/src)
file(GLOB SOURCES "*.cpp")
file(GLOB PNGS "gfx/*.png")
add_executable(Jump ${SOURCES})
target_link_libraries(Jump yda)
#install(DIRECTORY gfx DESTINATION jump/gfx
#        PATTERN "./gfx/*.png"
#        PERMISSIONS OWNER_EXECUTE OWNER_WRITE OWNER_READ
#                    GROUP_EXECUTE GROUP_READ)
#get_target_property(EXEC_LOC Jump LOCATION)
add_custom_command(TARGET Jump
				   POST_BUILD
				   COMMAND ${CMAKE_COMMAND},
				   ARGS -E copy ${CMAKE_INSTALL_PREFIX} gfx)