#ifndef HAL_GPIO_H
#define HAL_GPIO_H

#include <cstdint>
#include "cubemx/main.h"

namespace stm32::hal {

enum class PinNumber
{
  Pin0  = 0x0001,
  Pin1  = 0x0002,
  Pin2  = 0x0004,
  Pin3  = 0x0008,
  Pin4  = 0x0010,
  Pin5  = 0x0020,
  Pin6  = 0x0040,
  Pin7  = 0x0080,
  Pin8  = 0x0100,
  Pin9  = 0x0200,
  Pin10 = 0x0400,
  Pin11 = 0x0800,
  Pin12 = 0x1000,
  Pin13 = 0x2000,
  Pin14 = 0x4000,
  Pin15 = 0x8000
};

enum class PortType
{
  PortA = 0,
  PortB = 1,
  PortC = 2,
  PortD = 3,
  PortE = 4,
  PortH = 5
};

struct GpioPin {
  PortType port;
  PinNumber pin;
};

class HalGpio
{
public:
  HalGpio();

  void setup();
  void setPin(PortType port, PinNumber pin, bool state);
  void setPin(GpioPin gpioPin, bool state);
  bool getPin(PortType port, PinNumber pin);
  bool getPin(GpioPin gpioPin);
  void togglePin(PortType port, PinNumber pin);
  void togglePin(GpioPin gpioPin);
  void setPort(PortType port, uint16_t value);
  uint16_t getPort(PortType port);

private:
  GPIO_TypeDef* decodePort(PortType port);
};

} // namespace

#endif /* HAL_GPIO_H */
