#include "cubemx/main.h"
#include "cubemx/usart.h"
#include "hal/hal_uart.h"

namespace stm32::hal {

HalUsart::HalUsart(UART_HandleTypeDef& uart) : m_uart(uart)
{
}


void HalUsart::setup()
{
  MX_USART2_UART_Init();
}


void HalUsart::transmit(const uint8_t *data, uint16_t size)
{
  HAL_UART_Transmit(&m_uart, const_cast<uint8_t*>(data), size, 10000);
}


void HalUsart::receive()
{
}

} // namespace
