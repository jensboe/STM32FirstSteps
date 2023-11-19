if(CMAKE_CROSSCOMPILING)

add_subdirectory(embedded)
else()
add_subdirectory(tests)
endif()