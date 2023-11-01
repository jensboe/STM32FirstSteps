cmake_minimum_required(VERSION 3.23)

project("STM32FirstSteps")
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)


string(CONCAT CLANG_TIDY_CHECKS
    "*,"
    "-abseil-*,"
    "-altera-*,"
    "-android-*,"
    "-fuchsia-*,"
    "-google-*,"
    "-llvm*,"
    "-modernize-use-trailing-return-type,"
    "-zircon-*,"
    "readability-else-after-return,"
    "-readability-static-accessed-through-instance,"
    "-readability-avoid-const-params-in-decls,"
    "-cppcoreguidelines-non-private-member-variables-in-classes,"
    "-misc-non-private-member-variables-in-classes,"
)

set(CMAKE_CXX_CLANG_TIDY clang-tidy
    -header-filter=.;
    -checks=${CLANG_TIDY_CHECKS})

include(cmake/add_common_target_properties.cmake)
include(cmake/git_version.cmake)
add_subdirectory(apps)
add_subdirectory(tests)
add_subdirectory(ext)
add_subdirectory(lib/cpphalf4)
