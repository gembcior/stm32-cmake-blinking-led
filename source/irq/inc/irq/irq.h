#ifndef IRQ_H
#define IRQ_H

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

#endif /* IRQ_H */
