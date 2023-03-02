
target_include_directories(${APP}
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/inc
)

target_sources(${APP}
    PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/src/day1.cpp
)

target_compile_definitions(${APP}
    PRIVATE
        TOP_ELF_AMT=3
)
