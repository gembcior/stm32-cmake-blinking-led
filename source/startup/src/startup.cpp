#include "startup/startup.h"
#include "hal/hal_gpio.h"
#include "hal/hal_uart.h"
#include "cubemx/usart.h"

namespace stm32::startup {

HalCpu& getHalCpu()
{
  static HalCpu halCpu;
  return halCpu;
}

HalGpio& getHalGpio()
{
  static HalGpio halGpio;
  return halGpio;
}


HalUsart& getHalUsart2()
{
  static HalUsart halUsart(huart2);
  return halUsart;
}

} // namespace
