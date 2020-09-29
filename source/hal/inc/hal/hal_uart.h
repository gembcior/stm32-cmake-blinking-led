#ifndef HAL_USART_H
#define HAL_USART_H

#include <cstdint>

namespace stm32::hal {

class HalUsart
{
public:
  HalUsart(UART_HandleTypeDef& uart);

  void setup();
  void transmit(const uint8_t *data, uint16_t size);
  void transmitIt();
  void transmitDma(const uint8_t *data, uint16_t size);
  void receive();
  void receiveIt();
  void receiveDma();

private:
  UART_HandleTypeDef& m_uart;
};

} // namespace

#endif /* HAL_USART_H */
