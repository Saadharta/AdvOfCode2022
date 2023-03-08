
cmake_minimum_required(VERSION 3.16)

project(AdventOfCode LANGUAGES CXX)

set(DAY_VARIANTS 1 2 3 4)
set(DAY 1 CACHE STRING "which Day to execute")
set_property(CACHE DAY PROPERTY STRINGS ${DAY_VARIANTS})

if(NOT ${DAY} IN_LIST DAY_VARIANTS)
    message(FATAL_ERROR "DAY must be one of ${DAY_VARIANTS}")
endif()

message("Day${DAY}")

set(APP day${DAY})

# I want to call the CMakeLists.txt from each day separately
add_subdirectory(Day${DAY})

set_target_properties(${APP} 
    PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}"
    )


    message("CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")