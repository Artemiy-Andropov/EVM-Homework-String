#include <iostream>
#include "String.h"
#include "Exception.h"

String::String()
{
	m_string = nullptr;
	m_size = 0;
}

String::String(const char* string_, int size)
{
	if (size <= 0)
	{
		m_size = 0;
		m_string = nullptr;
	}

	m_size = size;
	m_string = new char[m_size];

	for (int i = 0; i < size; i++)
		m_string[i] = string_[i];
}

String::String(const String& obj)
{
	if (obj.m_size == 0)
	{
		m_size = 0;
		m_string = nullptr;
		return;
	}

	m_size = obj.m_size;
	m_string = new char[m_size];

	for (int i = 0; i < m_size; i++)
		m_string[i] = obj.m_string[i];
}

void String::Delete(String& obj)
{
	if (obj.m_string != nullptr)
		delete[]obj.m_string;
	obj.m_size = 0;
}

String::~String()
{
	Delete(*this);
}

bool String::IsEmpty()
{
	return m_size == 0;
}

int String::Lenght()
{
	return m_size;
}

char& String::At(int position)
{
	if (position >= m_size || position < 0)
		throw StringException("Error. Invalid input. This position is not in the string.");

	return m_string[position];
}

char& String::Front()
{
	return m_string[0];
}

char& String::Back()
{
	return m_string[m_size - 1];
}

void String::Clear()
{
	for (int i = 0; i < m_size; i++)
		m_string[i] = ' ';
}

void String::Insert(char symbol, int position)
{
	if (position > m_size || position < 0)
		throw StringException("Error. Invalid input. This position is not in the string.");

	char* copy = new char[m_size];
	for (int i = 0; i < m_size; i++)
		copy[i] = m_string[i];

	delete[]m_string;
	m_size++;
	m_string = new char[m_size];

	for (int i = 0; i < position; i++)
		m_string[i] = copy[i];

	m_string[position] = symbol;

	for (int i = position + 1; i < m_size; i++)
		m_string[i] = copy[i - 1];

	delete[]copy;
}

void String::Erase(int begin, int end)
{
	if (begin < 0)
		begin = 0;
	if (end > m_size)
		end = m_size;

	if ((end - begin + 1) >= m_size)
	{
		Delete(*this);
		return;
	}

	int count = 0;
	char* copy = new char[m_size];

	for (int i = 0; i < m_size; i++)
	{
		if (i >= begin && i <= end)
			continue;
		copy[count] = m_string[i];
		count++;
	}

	delete[]m_string;
	m_string = new char[count];
	m_size = count;

	for (int i = 0; i < count; i++)
		m_string[i] = copy[i];

	delete[]copy;
}

void String::Push_Back(char symbol)
{
	if (m_size > 0)
	{
		char* copy = new char[m_size];
		for (int i = 0; i < m_size; i++)
			copy[i] = m_string[i];

		delete[]m_string;
		m_size++;
		m_string = new char[m_size];

		for (int i = 0; i < m_size - 1; i++)
			m_string[i] = copy[i];

		m_string[m_size - 1] = symbol;
		delete[]copy;
	}
	else
	{
		m_size++;
		m_string = new char[m_size];
		m_string[0] = symbol;
	}
}

void String::Resize(int size_, char symbol)
{
	if (size_ <= 0)
	{
		Delete(*this);
		return;
	}
	if (m_size == size_)
		return;

	if (m_size > 0)
	{
		char* copy = new char[m_size];
		for (int i = 0; i < m_size; i++)
			copy[i] = m_string[i];

		delete[]m_string;
		m_string = new char[size_];
		if (m_size >= size_)
		{
			m_size = size_;
			for (int i = 0; i < size_; i++)
				m_string[i] = copy[i];
		}
		else
		{
			for(int i = 0; i < m_size; i++)
				m_string[i] = copy[i];

			for (int i = m_size; i < size_; i++)
				m_string[i] = symbol;

			m_size = size_;
		}
		delete[]copy;
	}
	else
	{
		m_size = size_;
		m_string = new char[m_size];
		for (int i = 0; i < size_; i++)
			m_string[i] = symbol;
	}
}

void String::Swap(String& obj)
{
	String copy(obj);
	obj = *this;
	*this = copy;
}

void String::Append(const String& obj)
{
	*this += obj;
}

String String::C_str()
{
	char* copy = new char[m_size+1];
	for (int i = 0; i < m_size; i++)
		copy[i] = m_string[i];

	copy[m_size] = 0;
	String c_str(copy, m_size + 1);
	delete[]copy;

	return c_str;
}

void String::Copy(const String& obj)
{
	*this = obj;
}

bool String::Find(const String& obj, int position)
{
	if (position > m_size || position < 0)
		throw StringException("Error. Invalid input. This position is not in the string.");

	int count = 0;

	for (int i = position; i < m_size; i++)
	{
		if (m_string[i] == obj.m_string[i])
			count++;
		else
			count = 0;
		if (count == obj.m_size)
			return true;
	}
	return false;

}

String String::SubStr(int position, int amount)
{
	if (position > m_size || position < 0)
		throw StringException("Error. Invalid input. This position is not in the string.");

	int end = position + amount;
	if (end > m_size)
		end = m_size;

	String answer;

	answer.Resize(end - position, ' ');

	for (int i = position; i < end; i++)
		answer[i-position] = m_string[i];

	return answer;
}

bool String::Compare(const String& obj)
{
	return (*this == obj);
}

std::ostream& operator<<(std::ostream& out, const String& obj)
{
	for (int i = 0; i < obj.m_size; i++)
		out << obj.m_string[i];
	return out;
}

std::istream& operator>>(std::istream& in, String& obj)
{
	try
	{
		int count = 0;
		int size_ = 100;
		char* string_ = new char[size_];
		char symbol;
		while (1)
		{
			if (in.peek() == 32)
			{
				string_[count] = ' ';
				count++;
			}

			in >> symbol;
			if (in.fail())
			{
				delete[]string_;
				throw StringException("Error. Invalid character supplied.");
			}

			string_[count] = symbol;
			count++;
			if (count == size_)
			{
				size_ = size_ * 2;
				char* copy = new char[count];

				for (int i = 0; i < count; i++)
					copy[i] = string_[i];

				delete[]string_;
				string_ = new char[size_];

				for (int i = 0; i < count; i++)
					string_[i] = copy[i];
				delete[]copy;
			}
			if (in.peek() == '\n')
			{
				obj.m_size = count;
				obj.m_string = new char[count];
				for (int i = 0; i < count; i++)
					obj.m_string[i] = string_[i];
				delete[]string_;
				return in;
			}
		}
	}
	catch (StringException& exception_)
	{
		std::cerr << "An exception occurred at string (" << exception_.GetError() << ")" << std::endl;
		in.setstate(std::ios::failbit);
		return in;
	}
}

String& String::operator=(const String& obj)
{
	if (obj.m_size == 0)
	{
		m_string = nullptr;
		m_size = 0;
		return *this;
	}

	if (!this->IsEmpty())
		delete[]m_string;

	m_size = obj.m_size;
	m_string = new char[m_size];

	for (int i = 0; i < m_size; i++)
		m_string[i] = obj.m_string[i];

	return *this;
}

String String::operator+(const String& obj)
{
	int size_ = m_size + obj.m_size;
	if (size_ == 0)
	{
		String answer_1;
		return answer_1;
	}

	char* merger = new char[size_];
	
	for (int i = 0; i < m_size; i++)
		merger[i] = m_string[i];

	for (int i = 0; i < obj.m_size; i++)
		merger[i + m_size] = obj.m_string[i];

	String answer(merger, size_);

	delete[]merger;
	return answer;
}

String& String::operator+=(const String& obj)
{
	int size_ = m_size + obj.m_size;
	if (size_ == 0)
		return *this;

	char* copy = new char[m_size];

	for (int i = 0; i < m_size; i++)
		copy[i] = m_string[i];

	if (!this->IsEmpty())
		delete[]m_string;
	m_string = new char[size_];

	for (int i = 0; i < m_size; i++)
		m_string[i] = copy[i];

	for (int i = 0; i < obj.m_size; i++)
		m_string[i + m_size] = obj.m_string[i];

	m_size = size_;

	delete[]copy;
	return *this;
}

bool String::operator==(const String& obj)
{
	if (m_size != obj.m_size)
		return false;

	if (m_size == 0)
		return true;

	for (int i = 0; i < m_size; i++)
	{
		if (m_string[i] != obj.m_string[i])
			return false;
	}
	return true;
}

bool String::operator!=(const String& obj)
{
	return !(*this == obj);
}

bool String::operator<(const String& obj)
{
	if (m_size != obj.m_size)
	{
		if (m_size < obj.m_size)
			return true;
		else
			return false;
	}

	if (m_size == 0)
		return false;

	for (int i = 0; i < m_size; i++)
	{
		if (m_string[i] != obj.m_string[i])
		{
			if (m_string[i] < obj.m_string[i])
				return true;
			else
				return false;
		}
	}
	return false;
}

bool String::operator>(const String& obj)
{
	return !(*this < obj) && !(*this == obj);
}

bool String::operator<=(const String& obj)
{
	return !(*this > obj);
}

bool String::operator>=(const String& obj)
{
	return !(*this < obj);
}

char& String::operator[](int index)
{
	if (index >= m_size || index < 0)
		throw StringException("Error. Invalid input. This position is not in the string.");

	return m_string[index];
}