#ifndef HAL_STARTUP_H
#define HAL_STARTUP_H

#include "hal/hal_gpio.h"
#include "hal/hal_uart.h"
#include "hal/hal_cpu.h"

using namespace stm32::hal;

namespace stm32::startup {

HalCpu& getHalCpu();
HalGpio& getHalGpio();
HalUsart& getHalUsart2();

} // namespace

#endif /* HAL_STARTUP_H */
