add_library(cmsis_device_f4 STATIC
    cmsis_device_f4/Source/Templates/gcc/startup_stm32f446xx.s
)

target_include_directories(
    cmsis_device_f4 INTERFACE
    cmsis_device_f4/Include
)