cmake_minimum_required(VERSION 3.23)
project("modm_test"
VERSION 0.0.1
)

add_executable(${PROJECT_NAME})

target_sources(
    ${PROJECT_NAME} PRIVATE
    src/main.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
    modm
)
add_subdirectory(modm)