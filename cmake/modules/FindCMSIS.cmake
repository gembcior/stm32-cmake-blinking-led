if(NOT STM32_CUBE)
    message(FATAL_ERROR "No STM32_CUBE specified")
endif()

if(NOT STM32_CHIP)
  message(FATAL_ERROR "No STM32_CHIP specified")
endif()

string(SUBSTRING ${STM32_CHIP} 5 2 CHIP_TYPE)
string(TOLOWER ${CHIP_TYPE} CHIP_TYPE_LOWER)

set(CMSIS_ARM_HEADERS
  arm_common_tables.h
  arm_const_structs.h
  arm_math.h
)

set(CMSIS_COMMON_HEADERS
  cmsis_armcc.h
  cmsis_gcc.h
  core_armv8mbl.h
  core_cm0plus.h
  core_cm33.h
  core_cm7.h
  mpu_armv7.h
  cmsis_armclang.h
  cmsis_iccarm.h
  core_armv8mml.h
  core_cm1.h
  core_cm3.h
  core_sc000.h
  mpu_armv8.h
  cmsis_compiler.h
  cmsis_version.h
  core_cm0.h
  core_cm23.h
  core_cm4.h
  core_sc300.h
  tz_context.h
)

if(CHIP_TYPE STREQUAL "F1")

  set(CMSIS_DEVICE_HEADERS stm32f1xx.h system_stm32f1xx.h)
  set(CMSIS_DEVICE_SOURCES system_stm32f1xx.c)

elseif(CHIP_TYPE STREQUAL "F2")

  set(CMSIS_DEVICE_HEADERS stm32f2xx.h system_stm32f2xx.h)
  set(CMSIS_DEVICE_SOURCES system_stm32f2xx.c)

elseif(CHIP_TYPE STREQUAL "F3")

  set(CMSIS_DEVICE_HEADERS stm32f3xx.h system_stm32f3xx.h)
  set(CMSIS_DEVICE_SOURCES system_stm32f3xx.c)

elseif(CHIP_TYPE STREQUAL "F4")

  set(CMSIS_DEVICE_HEADERS stm32f4xx.h system_stm32f4xx.h)
  set(CMSIS_DEVICE_SOURCES system_stm32f4xx.c)

elseif(CHIP_TYPE STREQUAL "F7")

  set(CMSIS_DEVICE_HEADERS stm32f7xx.h system_stm32f7xx.h)
  set(CMSIS_DEVICE_SOURCES system_stm32f7xx.c)

elseif(CHIP_TYPE STREQUAL "F0")

  set(CMSIS_DEVICE_HEADERS stm32f0xx.h system_stm32f0xx.h)
  set(CMSIS_DEVICE_SOURCES system_stm32f0xx.c)

elseif(CHIP_TYPE STREQUAL "L0")

  set(CMSIS_DEVICE_HEADERS stm32l0xx.h system_stm32l0xx.h)
  set(CMSIS_DEVICE_SOURCES system_stm32l0xx.c)

elseif(CHIP_TYPE STREQUAL "L1")

  set(CMSIS_DEVICE_HEADERS stm32l1xx.h system_stm32l1xx.h)
  set(CMSIS_DEVICE_SOURCES system_stm32l1xx.c)

elseif(CHIP_TYPE STREQUAL "L4")

  set(CMSIS_DEVICE_HEADERS stm32l4xx.h system_stm32l4xx.h)
  set(CMSIS_DEVICE_SOURCES system_stm32l4xx.c) 

endif()

find_path(CMSIS_ARM_INCLUDE_DIR ${CMSIS_ARM_HEADERS}
  PATH_SUFFIXES include stm32${CHIP_TYPE_LOWER} cmsis
  HINTS ${STM32_CUBE}/Drivers/CMSIS/DSP/Include
  CMAKE_FIND_ROOT_PATH_BOTH
)

find_path(CMSIS_COMMON_INCLUDE_DIR ${CMSIS_COMMON_HEADERS}
  PATH_SUFFIXES include stm32${CHIP_TYPE_LOWER} cmsis
  HINTS ${STM32_CUBE}/Drivers/CMSIS/Include
  CMAKE_FIND_ROOT_PATH_BOTH
)

find_path(CMSIS_DEVICE_INCLUDE_DIR ${CMSIS_DEVICE_HEADERS}
  PATH_SUFFIXES include stm32${CHIP_TYPE_LOWER} cmsis
  HINTS ${STM32_CUBE}/Drivers/CMSIS/Device/ST/STM32${CHIP_TYPE}xx/Include
  CMAKE_FIND_ROOT_PATH_BOTH
)

set(CMSIS_INCLUDE_DIRS
  ${CMSIS_DEVICE_INCLUDE_DIR}
  ${CMSIS_COMMON_INCLUDE_DIR}
  ${CMSIS_ARM_INCLUDE_DIR}
)

foreach(file ${CMSIS_DEVICE_SOURCES})
  find_file(CMSIS_SOURCE ${file}
    PATH_SUFFIXES src stm32${CHIP_TYPE_LOWER} cmsis
    HINTS ${STM32_CUBE}/Drivers/CMSIS/Device/ST/STM32${CHIP_TYPE}xx/Source/Templates/
    CMAKE_FIND_ROOT_PATH_BOTH
  )
  list(APPEND CMSIS_SOURCES ${CMSIS_SOURCE})
  unset(CMSIS_SOURCE CACHE)
endforeach()

include(FindPackageHandleStandardArgs)

find_package_handle_standard_args(CMSIS DEFAULT_MSG CMSIS_INCLUDE_DIRS CMSIS_SOURCES)
