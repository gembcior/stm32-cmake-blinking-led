#include "trace/trace.h"

namespace stm32::trace {

StringStream& Trace::get(TraceVerbosity verbosity)
{
  m_stream << getVerbosityString(verbosity);
  m_stream << ": ";
  return m_stream;
}


std::string Trace::getVerbosityString(TraceVerbosity verbosity)
{
  static const char* const verbosityString[] = {
    "F",
    "E",
    "W",
    "I",
    "D",
  };

  return verbosityString[verbosity];
}

} // namespace
