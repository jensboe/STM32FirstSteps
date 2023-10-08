add_library(cmsis_device_f4 STATIC
    cmsis_device_f4/Source/Templates/gcc/startup_stm32f446xx.s
    cmsis_device_f4/Source/Templates/system_stm32f4xx.c
)

target_include_directories(
    cmsis_device_f4 PUBLIC
    cmsis_device_f4/Include
)
target_link_libraries(cmsis_device_f4 PUBLIC
    cmsis_5
)

add_common_target_properties(cmsis_device_f4)