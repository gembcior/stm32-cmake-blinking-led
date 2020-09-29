#ifndef HAL_CPU_H
#define HAL_CPU_H

namespace stm32::hal {

class HalCpu
{
public:
  void setup();
  void delay(uint32_t delay);
};

} // namespace

#endif /* HAL_CPU_H */
