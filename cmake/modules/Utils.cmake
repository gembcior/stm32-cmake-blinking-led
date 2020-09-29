set(ARM_SIZE "${STM32_TOOLCHAIN}/bin/arm-none-eabi-size")
set(ARM_OBJDUMP "${STM32_TOOLCHAIN}/bin/arm-none-eabi-objdump")


function(STM32_TARGET_LISTING TARGET)
  get_target_property(TARGET_SUFFIX ${TARGET} SUFFIX)
  add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND
    ${ARM_OBJDUMP} -h -D ${TARGET}${TARGET_SUFFIX} > ${TARGET}.lst
  )
endfunction()


function(STM32_TARGET_SIZE TARGET)
  get_target_property(TARGET_SUFFIX ${TARGET} SUFFIX)
  add_custom_command(TARGET ${TARGET} POST_BUILD COMMAND
    ${ARM_SIZE} ${TARGET}${TARGET_SUFFIX}
  )
endfunction()


function(STM32_TARGET_INSTALL TARGET)
  install(TARGETS ${TARGET}
    DESTINATION bin ${CMAKE_INSTALL_BINDIR}
  )

  install(FILES ${CMAKE_CURRENT_BINARY_DIR}/main.lst
    DESTINATION bin ${CMAKE_INSTALL_BINDIR}
  )
endfunction()


# For Vim YouCompleteMe plugin purpose
# Create symbolic link to compile_commands.json
function(LINK_COMPILE_COMMANDS_FILE TARGET)
  add_custom_command(TARGET ${TARGET}
    POST_BUILD
    COMMAND find ${CMAKE_BINARY_DIR} -type f -name "compile_commands.json" -exec ln -sf {} ${CMAKE_SOURCE_DIR} "\;"
  )
endfunction()
