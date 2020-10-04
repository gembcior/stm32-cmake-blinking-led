include(Utils)

add_executable(main)

target_sources(main
  PRIVATE
    src/main.cpp
)

target_include_directories(main
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/inc
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

target_link_libraries(main
  PRIVATE
    crt
    startup
    hal
    trace
)

set_property(TARGET main PROPERTY LINK_INTERFACE_MULTIPLICITY 3)
set_property(TARGET main PROPERTY SUFFIX .elf)

stm32_target_size(main)
stm32_target_listing(main)
stm32_target_install(main)

link_compile_commands_file(main)
