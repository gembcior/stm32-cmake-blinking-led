#include "trace/string_stream.h"


namespace stm32::trace {

StringStream& StringStream::operator << (const char* input)
{
  m_string += input;
  return *this;
}


StringStream& StringStream::operator << (std::string input)
{
  m_string += input;
  return *this;
}


StringStream& StringStream::operator << (unsigned int input)
{
  char temp_string[8];
  itoa(input, temp_string, 16);
  m_string += "0x";
  m_string += temp_string;
  return *this;
}

std::string StringStream::str()
{
  return m_string;
}

} // namespace
