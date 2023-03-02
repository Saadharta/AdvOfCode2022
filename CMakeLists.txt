
cmake_minimum_required(VERSION 3.16)
project(AdventOfCode)

set(APP advent_of_code)

set(DAY_VARIANTS 1)
set(DAY 1 CACHE STRING "which Day to execute")
set_property(CACHE DAY PROPERTY STRINGS ${DAY_VARIANTS})

message("variant set to ${DAY}")
if(NOT ${DAY} IN_LIST DAY_VARIANTS)
    message(FATAL_ERROR "DAY must be one of ${DAY_VARIANTS}")
endif()

add_executable(${APP})

# I want to call the CMakeLists.txt from each day separately
if("${DAY}" STREQUAL "1")
    add_subdirectory(Day1)
endif()
