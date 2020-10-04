cmake_minimum_required(VERSION 3.16)
project(stm32-cmake-blinking-led)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/defaults/stm32_cache.cmake)
include(ExternalProject)

ExternalProject_Add(stm32
  PREFIX            stm32
  SOURCE_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/source"
  TEST_COMMAND      ""
  STEP_TARGETS      configure install
  BUILD_ALWAYS      TRUE
  CMAKE_ARGS        -C ${CMAKE_CURRENT_SOURCE_DIR}/cmake/defaults/stm32_cache.cmake
)

ExternalProject_Get_Property(stm32 BINARY_DIR)

ExternalProject_Add_Step(stm32 flash
  COMMAND ${STM32_CUBE_PROGRAMMER} -c port=SWD -w ${BINARY_DIR}/bin/main.elf
  COMMENT "Flashing application to the device"
  DEPENDS ${BINARY_DIR}/bin/main.elf
  ALWAYS TRUE
  EXCLUDE_FROM_MAIN TRUE
)

ExternalProject_Add_StepTargets(stm32 flash)
