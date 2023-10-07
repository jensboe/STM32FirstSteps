cmake_minimum_required(VERSION 3.20)


project("STM32FirstSteps" C CXX ASM)

add_executable(CORE)

target_sources(
    CORE PRIVATE
    Src/main.c
    Src/stm32f4xx_hal_msp.c
    Src/stm32f4xx_it.c
    Src/syscalls.c
    Src/sysmem.c
    Src/system_stm32f4xx.c
    Startup/startup_stm32f446zetx.s
)
target_include_directories(
    CORE PRIVATE
    Inc
)
target_link_libraries(CORE PRIVATE HAL)
add_common_target_properties(CORE)

target_link_options(
    CORE PRIVATE
    -T
    ${CMAKE_SOURCE_DIR}/STM32F446ZETX_FLASH.ld
)

add_custom_command(
    TARGET CORE POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:CORE>
)

add_custom_command(
    TARGET CORE POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex
    $<TARGET_FILE:CORE> CORE.hex
)

add_custom_command(
    TARGET CORE POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary
    $<TARGET_FILE:CORE> CORE.bin
)