function(add_common_target_properties TARGET_NAME)

target_compile_definitions(
    ${TARGET_NAME} PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    STM32F446xx
)

target_compile_options(
    ${TARGET_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g3>
    $<$<NOT:$<CONFIG:Debug>>:-g1>
    $<$<NOT:$<CONFIG:Debug>>:-Os>
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -fdata-sections
    -ffunction-sections
    $<$<COMPILE_LANGUAGE:CXX>:-fno-rtti>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>
    $<$<COMPILE_LANGUAGE:CXX>:-fno-threadsafe-statics>
    -Wall
    -Wextra
    -Wshadow
    -Wundef
    -fno-common
    -fstack-usage
)

target_link_libraries(
    ${TARGET_NAME} PRIVATE
)

target_link_directories(
    ${TARGET_NAME} PRIVATE
)

target_link_options(
    ${TARGET_NAME} PRIVATE
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
    -fdata-sections
    -ffunction-sections
    -Wl,--gc-sections
    -Wl,-Map=${TARGET_NAME}.map
)

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_20)
endfunction()