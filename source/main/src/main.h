#ifndef IMAIN_H
#define IMAIN_H

#include <cstdint>
#include "hal/hal_gpio.h"

namespace stm32::hal {

constexpr GpioPin Led     = {.port = PortType::PortB, .pin = PinNumber::Pin3};

} // namespace

#endif /* IMAIN_H */
