#ifndef STRING_STREAM_H
#define STRING_STREAM_H

#include <string>

namespace stm32::trace {

class StringStream
{
public:
  std::string str();
  StringStream& operator << (const char* input);
  StringStream& operator << (std::string input);
  StringStream& operator << (unsigned int input);
private:
  std::string m_string;
};

} // namespace

#endif /* STRING_STREAM_H */
