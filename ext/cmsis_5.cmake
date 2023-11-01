project("cmsis_5")
add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(
    ${PROJECT_NAME} INTERFACE
    CMSIS_5/CMSIS/Core/Include
)