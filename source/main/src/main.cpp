#include "main.h"
#include "startup/startup.h"
#include "hal/hal_gpio.h"
#include "hal/hal_cpu.h"
#include "trace/uart_trace.h"
#include <cstdint>

using namespace stm32::hal;
using namespace stm32::trace;
using namespace stm32::startup;

int main(void)
{
  getHalCpu().setup();

  HalGpio& m_gpio    = getHalGpio();
  HalUsart& m_usart  = getHalUsart2();

  m_gpio.setup();
  m_usart.setup();

  while (1)
  {
    m_gpio.togglePin(Led);

    TRACE(TraceInfo) << "LED toogle!";

    getHalCpu().delay(200);
  }
}
