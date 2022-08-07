cmake_minimum_required(VERSION 3.15)
project(hellocmake LANGUAGES C)

find_program(CCACHE_PROGRAM ccache)
if (CCACHE_PROGRAM)
    message(STATUS "Found CCache: ${CCACHE_PROGRAM}")
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ${CCACHE_PROGRAM})
    set_property(GLOBAL PROPERTY RULE_LAUNCH_LINK ${CCACHE_PROGRAM})
else()
    message(FATAL_ERROR  "not Found CCache")
endif()

add_executable(main main.c)


add_custom_target(run COMMAND $<TARGET_FILE:main>)

set(CMAKE_EDIT_COMMAND "/usr/bin/ccmake")
if (CMAKE_EDIT_COMMAND)
    add_custom_target(configure COMMAND ${CMAKE_EDIT_COMMAND} -B ${CMAKE_BINARY_DIR})
else()
    message(FATAL_ERROR "not CMAKE_EDIT_COMMAND")
endif()
