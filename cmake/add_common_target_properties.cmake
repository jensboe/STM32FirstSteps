function(add_common_target_properties TARGET_NAME)

target_compile_definitions(
    ${TARGET_NAME} PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    STM32F446xx
)

target_compile_options(
    ${TARGET_NAME} PRIVATE
    $<$<CONFIG:Debug>:-g3>
    $<$<NOT:$<CONFIG:Debug>>:-g0>
    $<$<NOT:$<CONFIG:Debug>>:-Os>
    -mcpu=cortex-m4
    -mfpu=fpv4-sp-d16
    -mfloat-abi=hard
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
)

target_compile_features(${TARGET_NAME} PUBLIC cxx_std_20)
endfunction()