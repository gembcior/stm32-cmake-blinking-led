#ifndef IMAIN_H
#define IMAIN_H

#include <cstdint>
#include "hal/hal_gpio.h"

namespace stm32::hal {

constexpr GpioPin Button  = {.port = PortType::PortC, .pin = PinNumber::Pin13};
constexpr GpioPin Led     = {.port = PortType::PortA, .pin = PinNumber::Pin5};

} // namespace

#endif /* IMAIN_H */
