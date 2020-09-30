add_library(crt INTERFACE)

target_sources(crt
  INTERFACE
    startup.s
)

target_link_libraries(crt
  INTERFACE
    irq
    "-T ${CMAKE_CURRENT_SOURCE_DIR}/linker_script.ld"
)

set_target_properties(crt PROPERTIES
  INTERFACE_LINK_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/linker_script.ld
)
