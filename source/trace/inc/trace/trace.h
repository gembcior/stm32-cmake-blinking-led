#ifndef TRACE_H
#define TRACE_H

#include <string>
#include "string_stream.h"

namespace stm32::trace {

enum TraceVerbosity {
  TraceFatal,
  TraceError,
  TraceWarning,
  TraceInfo,
  TraceDebug,
};


class Trace
{
public:
   StringStream& get(TraceVerbosity verbosity = TraceInfo);

protected:
   StringStream m_stream;

private:
   std::string getVerbosityString(TraceVerbosity verbosity);
};

} // namespace

#endif /* TRACE_H */
