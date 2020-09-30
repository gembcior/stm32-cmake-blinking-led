#include "cubemx/main.h"
#include "cubemx/gpio.h"
#include "hal/hal_gpio.h"

namespace stm32::hal {

HalGpio::HalGpio() {}


void HalGpio::setup()
{
  MX_GPIO_Init();
}


void HalGpio::setPin(PortType port, PinNumber pin, bool state)
{
  GPIO_TypeDef* m_port;
  m_port = decodePort(port);

  HAL_GPIO_WritePin(m_port,
                    static_cast<uint16_t>(pin),
                    static_cast<GPIO_PinState>(state));
}


void HalGpio::setPin(GpioPin gpioPin, bool state)
{
  GPIO_TypeDef* m_port;
  m_port = decodePort(gpioPin.port);

  HAL_GPIO_WritePin(m_port,
                    static_cast<uint16_t>(gpioPin.pin),
                    static_cast<GPIO_PinState>(state));
}


bool HalGpio::getPin(PortType port, PinNumber pin)
{
  bool pinState;
  GPIO_TypeDef* m_port;

  m_port = decodePort(port);
  pinState = static_cast<bool>(HAL_GPIO_ReadPin(m_port, static_cast<uint16_t>(pin)));

  return pinState;
}


bool HalGpio::getPin(GpioPin gpioPin)
{
  bool pinState;
  GPIO_TypeDef* m_port;

  m_port = decodePort(gpioPin.port);
  pinState = static_cast<bool>(HAL_GPIO_ReadPin(m_port, static_cast<uint16_t>(gpioPin.pin)));

  return pinState;
}


void HalGpio::togglePin(PortType port, PinNumber pin)
{
  GPIO_TypeDef* m_port;

  m_port = decodePort(port);

  HAL_GPIO_TogglePin(m_port, static_cast<uint16_t>(pin));
}


void HalGpio::togglePin(GpioPin gpioPin)
{
  GPIO_TypeDef* m_port;

  m_port = decodePort(gpioPin.port);

  HAL_GPIO_TogglePin(m_port, static_cast<uint16_t>(gpioPin.pin));
}


void HalGpio::setPort(PortType port, uint16_t value)
{
  GPIO_TypeDef* m_port;

  m_port = decodePort(port);
  m_port->BSRR = value;
}


uint16_t HalGpio::getPort(PortType port)
{
  GPIO_TypeDef* m_port;
  uint16_t port_value;

  m_port = decodePort(port);
  port_value = m_port->IDR;

  return port_value;;
}


GPIO_TypeDef* HalGpio::decodePort(PortType port)
{
  GPIO_TypeDef* port_t = 0;

  switch(port)
  {
    case PortType::PortA :
      port_t = GPIOA;
      break;
    case PortType::PortB :
      port_t = GPIOB;
      break;
    case PortType::PortC :
      port_t = GPIOC;
      break;
    case PortType::PortH :
      port_t = GPIOH;
      break;
  }

  return port_t;
}

} // namespace
