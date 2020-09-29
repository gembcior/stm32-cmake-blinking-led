#include "cubemx/main.h"
#include "hal/hal_cpu.h"

namespace stm32::hal {

void HalCpu::setup()
{
  HAL_Init();
  SystemClock_Config();
}

void HalCpu::delay(uint32_t delay)
{
  HAL_Delay(delay);
}


} // namespace
