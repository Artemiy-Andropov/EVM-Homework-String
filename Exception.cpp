#include <iostream>
#include "Exception.h"
#include "String.h"

StringException::StringException(const char* error_)
{
	int count = 0;
	for (; error_[count] != '\0'; count++);
	String answer(error_, count);
	m_error = answer;
}

const String StringException::GetError()
{
	return m_error.C_str();
}