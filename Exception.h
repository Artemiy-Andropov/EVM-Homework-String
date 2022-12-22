#pragma once
#include <iostream>
#include "String.h"

class StringException
{
	String m_error;
	int code_error;

public:

	StringException(const char* error_, int code_error_);

	const String GetError();

	const int GetCodeError();
};
