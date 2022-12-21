#pragma once
#include <iostream>
#include "String.h"

class StringException
{
	String m_error;

public:

	StringException(const char* error_);

	const String GetError();
};
