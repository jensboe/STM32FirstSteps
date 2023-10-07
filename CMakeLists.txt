cmake_minimum_required(VERSION 3.20)

project("STM32FirstSteps" C CXX ASM)

include(cmake/add_common_target_properties.cmake)
add_subdirectory(Core)

add_library(HAL)

target_include_directories(
    HAL PUBLIC
    Core/Inc
    ext/stm32f4xx_hal_driver/Inc
    ext/stm32f4xx_hal_driver/Inc/Legacy
    Drivers/CMSIS/Device/ST/STM32F4xx/Include
    Drivers/CMSIS/Include
)
target_sources(HAL PUBLIC
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_cortex.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_dma_ex.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_dma.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_exti.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash_ex.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash_ramfunc.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_gpio.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_pcd_ex.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_pcd.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_pwr_ex.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_pwr.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_rcc_ex.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_rcc.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_tim_ex.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_tim.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal_uart.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_hal.c
    ext/stm32f4xx_hal_driver/Src/stm32f4xx_ll_usb.c
)
add_common_target_properties(HAL)