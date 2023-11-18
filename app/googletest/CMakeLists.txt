cmake_minimum_required(VERSION 3.23)
project("testkeks"
VERSION 0.0.1
)
enable_testing()

add_executable(testkeks)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

target_sources(
    testkeks PRIVATE
    src/main.cpp
)

target_link_libraries(
    testkeks
    GTest::gtest_main
)
