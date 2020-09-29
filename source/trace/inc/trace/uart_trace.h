#ifndef UART_TRACE_H
#define UART_TRACE_H

#include "trace.h"

#define TRACE(x) UartTrace().get(x)

namespace stm32::trace {

class UartTrace: public Trace
{
public:
  virtual ~UartTrace();

};

} // namespace

#endif /* UART_TRACE_H */
