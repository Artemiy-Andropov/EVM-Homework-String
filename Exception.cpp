#include <iostream>
#include "Exception.h"
#include "String.h"

StringException::StringException(const char* error_, int code_error_)
{
	int count = 0;
	for (; error_[count] != '\0'; count++);
	String answer(error_, count);
	m_error = answer;
	code_error = code_error_;
}

const String StringException::GetError()
{
	return m_error.C_str();
}

const int StringException::GetCodeError()
{
	return code_error;
}