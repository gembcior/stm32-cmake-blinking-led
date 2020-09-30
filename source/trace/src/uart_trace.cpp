#include "trace/uart_trace.h"
#include "startup/startup.h"

namespace stm32::trace {

UartTrace::~UartTrace()
{
  m_stream << "\r\n";
  startup::getHalUsart2().transmit(reinterpret_cast<const uint8_t*>(m_stream.str().c_str()),
                                  static_cast<uint16_t>(m_stream.str().length()));
}

} // namespace
