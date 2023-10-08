cmake_minimum_required(VERSION 3.23)

project("STM32FirstSteps" C CXX ASM)

include(cmake/add_common_target_properties.cmake)
add_subdirectory(Core)
add_subdirectory(ext)
add_subdirectory(lib/cpphalf4)
