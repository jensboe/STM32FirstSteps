add_library(stm32f4xx_hal_driver)

target_include_directories(
    stm32f4xx_hal_driver PUBLIC
    ../Core/Inc
    stm32f4xx_hal_driver/Inc
    stm32f4xx_hal_driver/Inc/Legacy
    ../Drivers/CMSIS/Include
)
target_sources(stm32f4xx_hal_driver PUBLIC
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_cortex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_dma_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_dma.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_exti.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash_ramfunc.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_flash.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_gpio.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_pcd_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_pcd.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_pwr_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_pwr.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_rcc_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_rcc.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_tim_ex.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_tim.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal_uart.c
    stm32f4xx_hal_driver/Src/stm32f4xx_hal.c
    stm32f4xx_hal_driver/Src/stm32f4xx_ll_usb.c
)
target_link_libraries(stm32f4xx_hal_driver PUBLIC
    cmsis_device_f4
)
add_common_target_properties(stm32f4xx_hal_driver)