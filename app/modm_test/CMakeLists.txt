cmake_minimum_required(VERSION 3.23)
project("modm_test"
VERSION 0.0.1
)
add_executable(modm_test)

add_library(project_options INTERFACE)

target_sources(
    modm_test PRIVATE
    src/main.cpp
    board/board.cpp
)
target_include_directories(modm_test PRIVATE
    board
)

target_link_libraries(modm_test PUBLIC
    modm
    modm_options
)
add_subdirectory(modm)