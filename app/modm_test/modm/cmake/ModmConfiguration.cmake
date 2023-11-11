# Copyright (c) 2021, Jacob S. Andersen
# Copyright (c) 2021, 2023, Niklas Hauser
#
# This file is part of the modm project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.

# This file was autogenerated by the modm cmake builder. Do not modify!

find_program(PYTHON3_EXECUTABLE python3 REQUIRED)

# This function will prevent in-source builds
function(assure_out_of_source_builds)
  # make sure the user doesn't play dirty with symlinks
  get_filename_component(srcdir "${CMAKE_SOURCE_DIR}" REALPATH)
  get_filename_component(bindir "${CMAKE_BINARY_DIR}" REALPATH)

  # disallow in-source builds
  if("${srcdir}" STREQUAL "${bindir}")
    message("######################################################")
    message("Warning: in-source builds are disabled")
    message("Please create a separate build directory and run cmake from there")
    message("######################################################")
    message(FATAL_ERROR "Quitting configuration")
  endif()
endfunction()

assure_out_of_source_builds()

if(NOT MODM_BMP_PORT)
  set(MODM_BMP_PORT
    auto
    CACHE STRING "Set BMP debug port." FORCE)
endif()

if(NOT MODM_ITM_FCPU)
  set(MODM_ITM_FCPU
    0
    CACHE STRING "Set ITM fcpu." FORCE)
endif()

if(NOT MODM_RTT_CHANNEL)
  set(MODM_RTT_CHANNEL
    0
    CACHE STRING "Set RTT channel." FORCE)
endif()

if(NOT MODM_DBG_UI)
  message(STATUS "Setting debug ui to 'tui' as none was specified.")
  set(MODM_DBG_UI
      tui
      CACHE STRING "Choose debug ui type." FORCE)
  set_property(
    CACHE MODM_DBG_UI
    PROPERTY STRINGS
            "tui"
            "gdbgui")
endif()

if(NOT MODM_GCC_PATH AND NOT DEFINED ENV{GCC_PATH})
  find_program(MODM_GCC_PATH NAMES ${CMAKE_C_COMPILER})
  get_filename_component(MODM_GCC_PATH ${MODM_GCC_PATH} REALPATH)
  get_filename_component(MODM_GCC_PATH ${MODM_GCC_PATH} DIRECTORY)
  get_filename_component(MODM_GCC_PATH ${MODM_GCC_PATH} DIRECTORY)
  message(WARNING "Enviroment variable GCC_PATH not set.\nDefaults to: ${MODM_GCC_PATH}")
  set(MODM_GCC_PATH
    ${MODM_GCC_PATH}
    CACHE STRING "Path to gcc root directory" FORCE)
endif()
if(DEFINED ENV{GCC_PATH})
  set(MODM_GCC_PATH
    $ENV{GCC_PATH}
    CACHE STRING "Path to gcc root directory" FORCE)
endif()

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "Setting build type to 'MinSizeRel' as none was specified.")
  set(CMAKE_BUILD_TYPE
      MinSizeRel
      CACHE STRING "Choose the type of build." FORCE)
  # Set the possible values of build type for cmake-gui, ccmake
  set_property(
    CACHE CMAKE_BUILD_TYPE
    PROPERTY STRINGS
             "Debug"
             "Release"
             "MinSizeRel")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  add_compile_options(-fdiagnostics-color=always)
else()
  message(STATUS "No colored compiler diagnostic set for '${CMAKE_CXX_COMPILER_ID}' compiler.")
endif()

function(modm_target_config_create target target_arch target_options target_warnings)
  set(CPPDEFINES
    STM32F4
  )

  set(CPPDEFINES_RELEASE
  )

  set(CPPDEFINES_DEBUG
    MODM_DEBUG_BUILD
  )


  set(CCFLAGS
    -fdata-sections
    -ffile-prefix-map=${MODM_GCC_PATH}=.
    -ffunction-sections
    -finline-limit=10000
    -fno-builtin-printf
    -fshort-wchar
    -funsigned-bitfields
    -funsigned-char
    -fwrapv
    -g3
    -gdwarf-3
  )

  set(CCFLAGS_RELEASE
  )

  set(CCFLAGS_DEBUG
    -fno-move-loop-invariants
    -fno-split-wide-types
    -fno-tree-loop-optimize
  )


  set(CFLAGS
    -std=gnu2x
  )

  set(CFLAGS_RELEASE
  )

  set(CFLAGS_DEBUG
  )


  set(CXXFLAGS
    -fno-exceptions
    -fno-rtti
    -fno-unwind-tables
    -fno-use-cxa-atexit
    -fstrict-enums
    -std=c++23
  )

  set(CXXFLAGS_RELEASE
  )

  set(CXXFLAGS_DEBUG
  )


  set(ASFLAGS
    -g3
    -gdwarf-3
  )

  set(ASFLAGS_RELEASE
  )

  set(ASFLAGS_DEBUG
  )


  set(ARCHFLAGS
    -mcpu=cortex-m4
    -mfloat-abi=hard
    -mfpu=fpv4-sp-d16
    -mthumb
  )

  set(ARCHFLAGS_RELEASE
  )

  set(ARCHFLAGS_DEBUG
  )


  set(LINKFLAGS
    --specs=nano.specs
    --specs=nosys.specs
    -L${PROJECT_SOURCE_DIR}
    -nostartfiles
    -Tmodm/link/linkerscript.ld
    -Wl,--build-id=sha1
    -Wl,--fatal-warnings
    -Wl,--gc-sections
    -Wl,--no-warn-rwx-segment
    -Wl,--no-wchar-size-warning
    -Wl,--relax
    -Wl,-Map,${PROJECT_NAME}.map,--cref
  )

  set(LINKFLAGS_RELEASE
  )

  set(LINKFLAGS_DEBUG
  )


  set(CWARN
    -Wbad-function-cast
    -Wimplicit
    -Wredundant-decls
    -Wstrict-prototypes
  )

  set(CWARN_RELEASE
  )

  set(CWARN_DEBUG
  )


  set(CCWARN
    -W
    -Wall
    -Wdouble-promotion
    -Wduplicated-cond
    -Werror=format
    -Werror=maybe-uninitialized
    -Werror=overflow
    -Werror=sign-compare
    -Wextra
    -Wlogical-op
    -Wno-redundant-decls
    -Wpointer-arith
    -Wundef
  )

  set(CCWARN_RELEASE
  )

  set(CCWARN_DEBUG
  )


  set(CXXWARN
    -Wno-volatile
    -Woverloaded-virtual
  )

  set(CXXWARN_RELEASE
  )

  set(CXXWARN_DEBUG
  )



  target_compile_definitions(${target_options} INTERFACE
    ${CPPDEFINES}
    $<$<CONFIG:MinSizeRel>:${CPPDEFINES_RELEASE}>
    $<$<CONFIG:Release>:${CPPDEFINES_RELEASE}>
    $<$<CONFIG:Debug>:${CPPDEFINES_DEBUG}>)

  target_compile_options(${target_arch} INTERFACE
    ${ARCHFLAGS}
    $<$<CONFIG:MinSizeRel>:${ARCHFLAGS_RELEASE}>
    $<$<CONFIG:Release>:${ARCHFLAGS_RELEASE}>
    $<$<CONFIG:Debug>:${ARCHFLAGS_DEBUG}>)

  target_compile_options(${target_options} INTERFACE
    ${CCFLAGS}
    $<$<COMPILE_LANGUAGE:CXX>:$<$<CONFIG:MinSizeRel>:${CCFLAGS_RELEASE} ${CXXFLAGS} ${CXXFLAGS_RELEASE}>>
    $<$<COMPILE_LANGUAGE:CXX>:$<$<CONFIG:Release>:${CCFLAGS_RELEASE} ${CXXFLAGS} ${CXXFLAGS_RELEASE}>>
    $<$<COMPILE_LANGUAGE:CXX>:$<$<CONFIG:Debug>:${CCFLAGS_DEBUG} ${CXXFLAGS} ${CXXFLAGS_DEBUG}>>

    $<$<COMPILE_LANGUAGE:C>:$<$<CONFIG:MinSizeRel>:${CCFLAGS_RELEASE} ${CFLAGS} ${CFLAGS_RELEASE}>>
    $<$<COMPILE_LANGUAGE:C>:$<$<CONFIG:Release>:${CCFLAGS_RELEASE} ${CFLAGS} ${CFLAGS_RELEASE}>>
    $<$<COMPILE_LANGUAGE:C>:$<$<CONFIG:Debug>:${CCFLAGS_DEBUG} ${CFLAGS} ${CFLAGS_DEBUG}>>

    $<$<COMPILE_LANGUAGE:ASM>:$<$<CONFIG:MinSizeRel>:${CCFLAGS_RELEASE} ${ASMFLAGS} ${ASMFLAGS_RELEASE}>>
    $<$<COMPILE_LANGUAGE:ASM>:$<$<CONFIG:Release>:${CCFLAGS_RELEASE} ${ASMFLAGS} ${ASMFLAGS_RELEASE}>>
    $<$<COMPILE_LANGUAGE:ASM>:$<$<CONFIG:Debug>:${CCFLAGS_DEBUG} ${ASMFLAGS} ${ASMFLAGS_DEBUG}>>)

  target_compile_options(${target_warnings} INTERFACE
    ${CCWARN}
    $<$<COMPILE_LANGUAGE:CXX>:$<$<CONFIG:MinSizeRel>:${CCWARN_RELEASE} ${CXXWARN} ${CXXWARN_RELEASE}>>
    $<$<COMPILE_LANGUAGE:CXX>:$<$<CONFIG:Release>:${CCWARN_RELEASE} ${CXXWARN} ${CXXWARN_RELEASE}>>
    $<$<COMPILE_LANGUAGE:CXX>:$<$<CONFIG:Debug>:${CCWARN_DEBUG} ${CXXWARN} ${CXXWARN_DEBUG}>>

    $<$<COMPILE_LANGUAGE:C>:$<$<CONFIG:MinSizeRel>:${CCWARN_RELEASE} ${CWARN} ${CWARN_RELEASE}>>
    $<$<COMPILE_LANGUAGE:C>:$<$<CONFIG:Release>:${CCWARN_RELEASE} ${CWARN} ${CWARN_RELEASE}>>
    $<$<COMPILE_LANGUAGE:C>:$<$<CONFIG:Debug>:${CCWARN_DEBUG} ${CWARN} ${CWARN_DEBUG}>>)

  target_link_options(${target} INTERFACE
    ${LINKFLAGS} ${ARCHFLAGS}
    $<$<CONFIG:MinSizeRel>:${LINKFLAGS_RELEASE} ${ARCHFLAGS_RELEASE}>
    $<$<CONFIG:Release>:${LINKFLAGS_RELEASE} ${ARCHFLAGS_RELEASE}>
    $<$<CONFIG:Debug>:${LINKFLAGS_DEBUG} ${ARCHFLAGS_DEBUG}>)
endfunction()

function(modm_targets_create project_name)
  set_target_properties(${project_name}
    PROPERTIES SUFFIX ".elf")

  add_custom_command(TARGET ${project_name}
    POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -Obinary ${project_name}.elf ${project_name}.bin
    COMMAND ${CMAKE_OBJCOPY} -Oihex ${project_name}.elf ${project_name}.hex)

  add_custom_command(TARGET ${project_name}
    POST_BUILD
    COMMAND PYTHONPATH=${PROJECT_SOURCE_DIR}/modm ${PYTHON3_EXECUTABLE} -m modm_tools.size ${project_name}.elf \"[{'name': 'flash', 'access': 'rx', 'start': 134217728, 'size': 524288}, {'name': 'sram1', 'access': 'rwx', 'start': 536870912, 'size': 131072}]\")
  add_custom_target(size DEPENDS ${project_name}.elf)
  add_custom_command(TARGET size
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.size ${PROJECT_BINARY_DIR}/src/${project_name}.elf \"[{'name': 'flash', 'access': 'rx', 'start': 134217728, 'size': 524288}, {'name': 'sram1', 'access': 'rwx', 'start': 536870912, 'size': 131072}]\"
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(program DEPENDS ${project_name}.elf)
  add_custom_command(TARGET program
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.openocd -f modm/openocd.cfg
        ${PROJECT_BINARY_DIR}/src/${project_name}.elf
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(program-bmp DEPENDS ${project_name}.elf)
  add_custom_command(TARGET program-bmp
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.bmp -p ${MODM_BMP_PORT}
        ${PROJECT_BINARY_DIR}/src/${project_name}.elf
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(program-jlink DEPENDS ${project_name}.elf)
  add_custom_command(TARGET program-jlink
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.jlink -device stm32f446ze
        ${PROJECT_BINARY_DIR}/src/${project_name}.elf
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(debug DEPENDS ${project_name}.elf)
  add_custom_command(TARGET debug
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.gdb -x modm/gdbinit -x modm/openocd_gdbinit
        --elf ${PROJECT_BINARY_DIR}/src/${project_name}.elf --ui=${MODM_DBG_UI}
        openocd -f modm/openocd.cfg
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(debug-bmp DEPENDS ${project_name}.elf)
  add_custom_command(TARGET debug-bmp
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.gdb -x modm/gdbinit -x modm/openocd_bmp
        --elf ${PROJECT_BINARY_DIR}/src/${project_name}.elf --ui=${MODM_DBG_UI}
        bmp -p ${MODM_BMP_PORT}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(debug-jlink DEPENDS ${project_name}.elf)
  add_custom_command(TARGET debug-jlink
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.gdb -x modm/gdbinit -x modm/openocd_jlink
        --elf ${PROJECT_BINARY_DIR}/src/${project_name}.elf --ui=${MODM_DBG_UI}
        jlink -device stm32f446ze
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(debug-coredump DEPENDS ${project_name}.elf)
  add_custom_command(TARGET debug-coredump
    USES_TERMINAL
    COMMAND	PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.gdb -x modm/gdbinit
        --elf ${PROJECT_BINARY_DIR}/src/${project_name}.elf --ui=${MODM_DBG_UI}
        crashdebug
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(coredump)
  add_custom_command(TARGET coredump
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.gdb -x modm/gdbinit
        -ex "modm_coredump" -ex "modm_build_id" -ex "quit"
        openocd -f modm/openocd.cfg
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(coredump-bmp)
  add_custom_command(TARGET coredump-bmp
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.gdb -x modm/gdbinit
        -ex "modm_coredump" -ex "modm_build_id" -ex "quit"
        bmp -p ${MODM_BMP_PORT}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(coredump-jlink)
  add_custom_command(TARGET coredump-jlink
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.gdb -x modm/gdbinit
        -ex "modm_coredump" -ex "modm_build_id" -ex "quit"
        jlink -device stm32f446ze
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(reset)
  add_custom_command(TARGET reset
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.openocd -f modm/openocd.cfg --reset
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(reset-bmp)
  add_custom_command(TARGET reset-bmp
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.bmp -p ${MODM_BMP_PORT} --reset
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(reset-jlink)
  add_custom_command(TARGET reset-jlink
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.jlink -device stm32f446ze --reset
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(log-itm)
  add_custom_command(TARGET log-itm
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.itm openocd -f modm/openocd.cfg --fcpu ${MODM_ITM_FCPU}
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(log-itm-jlink)
  add_custom_command(TARGET log-itm-jlink
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.itm jlink -device stm32f446ze
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(log-rtt)
  add_custom_command(TARGET log-rtt
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.rtt --channel ${MODM_RTT_CHANNEL} openocd -f modm/openocd.cfg
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

  add_custom_target(log-rtt-jlink)
  add_custom_command(TARGET log-rtt-jlink
    USES_TERMINAL
    COMMAND PYTHONPATH=modm ${PYTHON3_EXECUTABLE} -m modm_tools.rtt --channel ${MODM_RTT_CHANNEL} jlink -device stm32f446ze
    WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})
endfunction()
