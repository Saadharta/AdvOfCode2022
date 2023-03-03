add_executable(${APP})
set_target_properties(${APP} PROPERTIES LINKER_LANGUAGE CXX)
set(extraFlags "-Wall -Wextra -Weffc++ -pedantic -pedantic-errors -std=c++11")
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} ${extraFlags})

target_compile_definitions(${APP}
    PRIVATE
        TOP_ELF_AMT=3
)

target_include_directories(${APP}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_sources(${APP}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/day1.cpp
)