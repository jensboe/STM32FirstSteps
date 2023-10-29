cmake_minimum_required(VERSION 3.23)
project("STM32FirstSteps" C CXX ASM)

add_executable(playground)

target_sources(
    playground PRIVATE
    Src/main.cpp
    Src/stm32f4xx_it.c
    Src/syscalls.c
    Src/sysmem.c
)
target_include_directories(
    playground PRIVATE
    Inc
)
target_link_libraries(playground PUBLIC
    cpphalf4
    SI::SI
)
add_common_target_properties(playground)

target_link_options(
    playground PRIVATE
    -T
    ${CMAKE_SOURCE_DIR}/STM32F446ZETX_FLASH.ld
)

add_custom_command(
    TARGET playground POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:playground>
)

add_custom_command(
    TARGET playground POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex
    $<TARGET_FILE:playground> playground.hex
)

add_custom_command(
    TARGET playground POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary
    $<TARGET_FILE:playground> playground.bin
)
# add_custom_command(
#     TARGET playground POST_BUILD
#     COMMAND ${CMAKE_NM} --print-size --size-sort -r --radix=d
#     $<TARGET_FILE:playground>
# )