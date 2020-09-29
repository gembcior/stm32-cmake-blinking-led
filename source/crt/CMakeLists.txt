cmake_minimum_required(VERSION 3.15)

add_library(crt STATIC)

target_sources(crt
  PRIVATE
    startup.s
)

target_link_libraries(crt
  PUBLIC
    irq
  PRIVATE
    "-T ${CMAKE_CURRENT_SOURCE_DIR}/linker_script.ld"
)

set_target_properties(crt PROPERTIES
  INTERFACE_LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/linker_script.ld
)
