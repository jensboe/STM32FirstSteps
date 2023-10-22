add_library(cpphalf4 STATIC)



target_include_directories(
    cpphalf4 PUBLIC
    inc
)
target_sources(
    cpphalf4 PUBLIC
    src/stm32f446.cpp
)

target_link_libraries(cpphalf4 PUBLIC
    cmsis_device_f4
    cmsis_5
    SI::SI
)
