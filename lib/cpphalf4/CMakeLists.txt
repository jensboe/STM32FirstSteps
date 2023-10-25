add_library(cpphalf4 STATIC)



target_include_directories(
    cpphalf4 PUBLIC
    inc
)
target_include_directories(
    cpphalf4 PRIVATE
    registers
)
target_sources(
    cpphalf4 PRIVATE
    src/stm32f446.cpp
    src/stm32f4.cpp
)
add_common_target_properties(cpphalf4)

target_link_libraries(cpphalf4 PUBLIC
    cmsis_device_f4
    cmsis_5
    SI::SI
)
