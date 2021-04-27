cmake_minimum_required(VERSION 3.16)
project(weight C)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)

set(CMAKE_C_FLAGS "-g -Wall -Werror -O3 -std=c11 -pie -fPIC")

# make weight lib
file(GLOB SOURCE "src/*.c")
add_executable(weight ${SOURCE})
target_link_libraries(weight pthread)


install(TARGETS weight
	PERMISSIONS OWNER_EXECUTE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
