cmake_minimum_required(VERSION 3.23)

project("STM32FirstSteps")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


include(cmake/add_common_target_properties.cmake)
include(cmake/git_version.cmake)
add_subdirectory(apps)
add_subdirectory(tests)
add_subdirectory(ext)
add_subdirectory(lib/cpphalf4)
