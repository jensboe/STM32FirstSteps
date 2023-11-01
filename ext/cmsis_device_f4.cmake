project("cmsis_device_f4" C ASM)
add_library(${PROJECT_NAME} STATIC
    cmsis_device_f4/Source/Templates/gcc/startup_stm32f446xx.s
    cmsis_device_f4/Source/Templates/system_stm32f4xx.c
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    cmsis_device_f4/Include
)
target_link_libraries(${PROJECT_NAME} PUBLIC
    cmsis_5
)

add_common_target_properties(${PROJECT_NAME})