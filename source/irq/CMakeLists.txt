cmake_minimum_required(VERSION 3.15)

add_library(irq STATIC)

target_sources(irq
  PRIVATE
    src/irq.cpp
)

target_include_directories(irq
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/inc
  PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(irq
  PRIVATE
    cubemx
)
