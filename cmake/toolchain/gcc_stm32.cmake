set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
set(CMAKE_C_COMPILER "${STM32_TOOLCHAIN}/bin/arm-none-eabi-gcc")
set(CMAKE_CXX_COMPILER "${STM32_TOOLCHAIN}/bin/arm-none-eabi-g++")
set(CMAKE_ASM_COMPILER "${STM32_TOOLCHAIN}/bin/arm-none-eabi-gcc")

set(CMAKE_C_FLAGS_DEBUG "-Og -g3")
set(CMAKE_CXX_FLAGS_DEBUG "-Og -g3")
set(CMAKE_ASM_FLAGS_DEBUG "-Og -g3")

set(CMAKE_C_FLAGS_RELEASE "-O2 -g3")
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -g3")
set(CMAKE_ASM_FLAGS_RELEASE "-O2 -g3")

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

add_compile_definitions(${STM32_CHIP})
add_compile_definitions(${STM32_CHIP_FAMILY})

string(CONCAT C_FLAGS
  "-mcpu=cortex-m3 "
  "-mfpu=fpv4-sp-d16 "
  "-mfloat-abi=soft "
  "-mabi=aapcs "
  "-mthumb "
  "-std=gnu11 "
  "-fno-builtin "
  "-Wall "
  "-Werror "
  "-Wfatal-errors "
  "-ffunction-sections "
  "-fdata-sections "
  "-fno-exceptions "
  "-fstack-usage "
  "--specs=nano.specs "
  "-fomit-frame-pointer "
  "-fno-unroll-loops "
  "-ffast-math "
  "-ftree-vectorize "
)

string(CONCAT CXX_FLAGS
  "-mcpu=cortex-m3 "
  "-mfpu=fpv4-sp-d16 "
  "-mfloat-abi=soft "
  "-mabi=aapcs "
  "-mthumb "
  "-fno-builtin "
  "-Wall "
  "-Werror "
  "-Wfatal-errors "
  "-ffunction-sections "
  "-fdata-sections "
  "-fno-exceptions "
  "-fno-rtti "
  "-fno-threadsafe-statics "
  "-fno-use-cxa-atexit "
  "-fstack-usage "
  "--specs=nano.specs "
  "-fomit-frame-pointer "
  "-fno-unroll-loops "
  "-ffast-math "
  "-ftree-vectorize "
)

string(CONCAT ASM_FLAGS
  "-mcpu=cortex-m3 "
  "-mfpu=fpv4-sp-d16 "
  "-mfloat-abi=soft "
  "-mabi=aapcs "
  "-mthumb "
  "-x assembler-with-cpp "
  "--specs=nano.specs "
)

string(CONCAT LINKER_FLAGS
  "-mcpu=cortex-m3 "
  "-mfpu=fpv4-sp-d16 "
  "-mfloat-abi=soft "
  "-mabi=aapcs "
  "-mthumb "
  "-Wl,--gc-sections "
  "-Wl,-lc,-lm "
  "-static "
  "--specs=nosys.specs "
)

set(CMAKE_C_FLAGS_INIT ${C_FLAGS})
set(CMAKE_CXX_FLAGS_INIT ${CXX_FLAGS})
set(CMAKE_ASM_FLAGS_INIT ${ASM_FLAGS})
set(CMAKE_EXE_LINKER_FLAGS_INIT ${LINKER_FLAGS})
set(CMAKE_MODULE_LINKER_FLAGS_INIT ${LINKER_FLAGS})
set(CMAKE_SHARED_LINKER_FLAGS_INIT ${LINKER_FLAGS})
