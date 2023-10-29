cmake_minimum_required(VERSION 3.23)
project("playground"
    VERSION 0.0.1
)

add_executable(${PROJECT_NAME})

configure_file(buildinfo.hpp.in buildinfo.hpp)

target_sources(
    ${PROJECT_NAME} PRIVATE
    src/main.cpp
    src/stm32f4xx_it.c
    src/syscalls.c
    src/sysmem.c
)
target_include_directories(
    ${PROJECT_NAME} PRIVATE
    inc
    "${PROJECT_BINARY_DIR}"
)
target_link_libraries(${PROJECT_NAME} PUBLIC
    cpphalf4
    SI::SI
)
add_common_target_properties(${PROJECT_NAME})

target_link_options(
    ${PROJECT_NAME} PRIVATE
    -T
    ${CMAKE_SOURCE_DIR}/STM32F446ZETX_FLASH.ld
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${PROJECT_NAME}>
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex
    $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.hex
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary
    $<TARGET_FILE:${PROJECT_NAME}> ${PROJECT_NAME}.bin
)
# add_custom_command(
#     TARGET playground POST_BUILD
#     COMMAND ${CMAKE_NM} --print-size --size-sort -r --radix=d
#     $<TARGET_FILE:playground>
# )