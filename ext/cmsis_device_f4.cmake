add_library(cmsis_device_f4 INTERFACE
    cmsis_device_f4/Include/stm32f446xx.h
    cmsis_device_f4/Include/stm32f4xx.h
    cmsis_device_f4/Include/system_stm32f4xx.h
)

target_include_directories(
    cmsis_device_f4 INTERFACE
    cmsis_device_f4/Include
)