# THIS FILE IS AUTOMATICALLY GENERATED. DO NOT EDIT.
# BASED ON c:\Users\jensb\STM32CubeIDE\workspace_1.12.0\STM32FirstSteps

function(add_st_target_properties TARGET_NAME)

target_compile_definitions(
    ${TARGET_NAME} PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    USE_HAL_DRIVER
    STM32F446xx
)

target_include_directories(
    ${TARGET_NAME} PRIVATE
    ${PROJECT_SOURCE_DIR}/Core\\Inc
    ${PROJECT_SOURCE_DIR}/Drivers\\STM32F4xx_HAL_Driver\\Inc
    ${PROJECT_SOURCE_DIR}/Drivers\\STM32F4xx_HAL_Driver\\Inc\\Legacy
    ${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Device\\ST\\STM32F4xx\\Include
    ${PROJECT_SOURCE_DIR}/Drivers\\CMSIS\\Include
)

target_compile_options(
    ${TARGET_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g3>
    $<$<NOT:$<CONFIG:Debug>>:-g0>
    $<$<NOT:$<CONFIG:Debug>>:-Os>
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
)

target_link_libraries(
    ${TARGET_NAME} PRIVATE
)

target_link_directories(
    ${TARGET_NAME} PRIVATE
)

target_link_options(
    ${TARGET_NAME} PRIVATE
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -T
    ${PROJECT_SOURCE_DIR}/STM32F446ZETX_FLASH.ld
)

target_sources(
    ${TARGET_NAME} PRIVATE
    "Core\\Src\\main.c"
    "Core\\Src\\stm32f4xx_hal_msp.c"
    "Core\\Src\\stm32f4xx_it.c"
    "Core\\Src\\syscalls.c"
    "Core\\Src\\sysmem.c"
    "Core\\Src\\system_stm32f4xx.c"
    "Core\\Startup\\startup_stm32f446zetx.s"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_cortex.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_dma_ex.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_dma.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_exti.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_flash_ex.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_flash_ramfunc.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_flash.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_gpio.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_pcd_ex.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_pcd.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_pwr_ex.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_pwr.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_rcc_ex.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_rcc.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_tim_ex.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_tim.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal_uart.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_hal.c"
    "Drivers\\STM32F4xx_HAL_Driver\\Src\\stm32f4xx_ll_usb.c"
)

add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_SIZE} $<TARGET_FILE:${TARGET_NAME}>
)

add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex
    $<TARGET_FILE:${TARGET_NAME}> ${TARGET_NAME}.hex
)

add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O binary
    $<TARGET_FILE:${TARGET_NAME}> ${TARGET_NAME}.bin
)

endfunction()