add_library(irq INTERFACE)

target_sources(irq
  INTERFACE
    src/irq.cpp
)

target_link_libraries(irq
  INTERFACE
    cubemx
)
