add_library(cpphalf4 INTERFACE)



target_include_directories(
    cpphalf4 INTERFACE
    inc
)

target_link_libraries(cpphalf4 INTERFACE
    cmsis_device_f4
    cmsis_5
    SI::SI
)
