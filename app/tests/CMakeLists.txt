cmake_minimum_required(VERSION 3.23)

project("testing"
VERSION 0.0.1
)

add_executable(testing)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

target_sources(
  testing PRIVATE
    src/example.cpp
)

target_link_libraries(
  testing
    GTest::gtest_main
)
gtest_discover_tests(testing)