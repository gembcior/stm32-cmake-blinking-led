#include "cubemx/main.h"

extern "C" {
  void NMI_Handler(void) __attribute__ ((interrupt ("IRQ")));
  void HardFault_Handler(void) __attribute__ ((interrupt ("IRQ")));
  void MemManage_Handler(void) __attribute__ ((interrupt ("IRQ")));
  void BusFault_Handler(void) __attribute__ ((interrupt ("IRQ")));
  void UsageFault_Handler(void) __attribute__ ((interrupt ("IRQ")));
  void SVC_Handler(void) __attribute__ ((interrupt ("IRQ")));
  void DebugMon_Handler(void) __attribute__ ((interrupt ("IRQ")));
  void PendSV_Handler(void) __attribute__ ((interrupt ("IRQ")));
  void SysTick_Handler(void) __attribute__ ((interrupt ("IRQ")));
}

void NMI_Handler(void)
{
}


void HardFault_Handler(void)
{
  while (1)
  {
  }
}


void MemManage_Handler(void)
{
  while (1)
  {
  }
}


void BusFault_Handler(void)
{
  while (1)
  {
  }
}


void UsageFault_Handler(void)
{
  while (1)
  {
  }
}


void SVC_Handler(void)
{
}


void DebugMon_Handler(void)
{
}


void PendSV_Handler(void)
{
}


void SysTick_Handler(void)
{
  HAL_IncTick();
}
