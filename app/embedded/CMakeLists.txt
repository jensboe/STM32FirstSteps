cmake_minimum_required(VERSION 3.23)
project("embedded"
VERSION 0.0.1
)
add_executable(embedded)

add_library(project_options INTERFACE)

target_sources(embedded  PRIVATE
    src/main.cpp
    board/board.cpp
)
target_include_directories(embedded PRIVATE
    board
)

target_link_libraries(embedded PUBLIC
    modm
    modm_options
)
add_subdirectory(modm)