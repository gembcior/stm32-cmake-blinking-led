cmake_minimum_required(VERSION 3.15)
project(stm32-cmake-blinking-led)

include(ExternalProject)

ExternalProject_Add(stm32
  PREFIX            stm32
  SOURCE_DIR        "${CMAKE_CURRENT_SOURCE_DIR}/source"
  TEST_COMMAND      ""
  STEP_TARGETS      configure install
  BUILD_ALWAYS      TRUE
  CMAKE_ARGS        -C ${CMAKE_CURRENT_SOURCE_DIR}/cmake/defaults/stm32_cache.cmake
)
