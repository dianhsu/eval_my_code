cmake_minimum_required(VERSION 2.5)
project(judger C)

#set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/output)

set(CMAKE_C_FLAGS "-g -Wall -Werror -O3 -std=c99 -pie -fPIC")

# make judger lib
file(GLOB SOURCE "src/*.c" "src/rules/*.c")
add_executable(eval_my_code ${SOURCE})
target_link_libraries(eval_my_code pthread seccomp)


install(TARGETS eval_my_code
	PERMISSIONS OWNER_EXECUTE OWNER_READ GROUP_EXECUTE GROUP_READ WORLD_EXECUTE WORLD_READ
	RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
