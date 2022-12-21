#pragma once
#include <iostream>

class String
{
private:

	char* m_string;
	int m_size;

public:

	/*
	*@brief �����������
	*/
	String();

	/*
	*@brief ����������� � �����������
	*@param ������
	*@param ����������� ����� (������)
	*/
	String(const char* string_, int size);

	/*
	*@brief ����������� �����������
	*@param ����������� ������ �� ������ ���� "String"
	*/
	String(const String& obj);

	/*
	*@brief ����������
	*/
	~String();

	/*
	*@brief �������� ������
	*@param ������ �� ������ ���� "String"
	*/
	void Delete(String& obj);

	/*
	*@brief ���������, ������ �� ������
	*@return true ��� false
	*/
	bool IsEmpty();

	/*
	*@brief ���������� ������ ������
	*@return ����������� �����
	*/
	int Lenght();

	/*
	*@brief ���������� ��������� �� ��������� ������
	*@param ����������� �����
	*@return ��������� �� ������
	*/
	char& At(int position);

	/*
	*@brief ���������� ��������� �� ������ ������
	*@return ��������� �� ������ ������
	*/
	char& Front();

	/*
	*@brief ���������� ��������� �� ��������� ������
	*@return ��������� �� ��������� ������
	*/
	char& Back();

	/*
	*@brief ������� ������ (������ �������� �������� �������)
	*/
	void Clear();

	/*
	*@brief ��������� ������ �� ��������� �������
	*@param ������
	*@param ����������� �����
	*/
	void Insert(char symbol, int position);

	/*
	*@brief ������� ��������� ������ ��� ��������
	*@param ����������� ����� (������ ���������)
	*@param ����������� ����� (����� ���������)
	*/
	void Erase(int begin, int end);

	/*
	*@brief ��������� ������ � ����� ������
	*@param ������
	*/
	void Push_Back(char symbol);

	/*
	*@brief ������ ������ ������. ���� ������, �� ��������� �� ����� ����� ������, ����� �������
	*@param ����������� ����� (����� ������)
	*@param ������
	*/
	void Resize(int size_, char symbol);

	/*
	*@brief ������ ������ �������
	*@param C����� �� ������ ���� "String"
	*/
	void Swap(String& obj);

	/*
	*@brief ������������ �����
	*@param ����������� ������ �� ������ ���� "String"
	*/
	void Append(const String& obj);

	/*
	*@brief ���������� "��" ������
	*@return "��" ������
	*/
	String C_str();

	/*
	*@brief �������� ������
	*@param ����������� ������ �� ������ ���� "String"
	*/
	void Copy(const String& obj);

	/*
	*@brief ����� ������ � ��������� �������
	*@param ����������� ������ �� ������ ���� "String"
	*@param ����������� ����� (�������)
	*@return true ��� false
	*/
	bool Find(const String& obj, int position);

	/*
	*@brief ���������� ������ � ��������� ������� � ������ ����������� ��������
	*@param ����������� ����� (�������)
	*@param ����������� ����� (���������� ��������)
	*@return ���������
	*/
	String SubStr(int position, int amount);

	/*
	*@brief ��������� �����
	*@param ����������� ������ �� ������ ���� "String"
	*@return true ��� false
	*/
	bool Compare(const String& obj);

	/*
	*@brief ���������� ��������� ������
	*@param ������ �� ����� ������
	*@param ����������� ������ �� ������ ���� "String"
	*@return ������ �� ����� ������
	*/
	friend std::ostream& operator<<(std::ostream& out, const String& obj);

	/*
	*@brief ���������� ��������� �����
	*@param ������ �� ����� �����
	*@param ������ �� ������ ���� "String"
	*@return ������ �� ����� �����
	*/
	friend std::istream& operator>>(std::istream& in, String& obj);

	/*
	*@brief ���������� ��������� ������������
	*@param ����������� ������ �� ������ ���� "String"
	*@return ������ �� ������ ���� "String"
	*/
	String& operator=(const String& obj);

	/*
	*@brief ���������� ��������� +
	*@param ����������� ������ �� ������ ���� "String"
	*@return ������ ���� "String"
	*/
	String operator+(const String& obj);

	/*
	*@brief ���������� ��������� +=
	*@param ����������� ������ �� ������ ���� "String"
	*@return ������ �� ������ ���� "String"
	*/
	String& operator+=(const String& obj);

	/*
	*@brief ���������� ��������� ==
	*@param ����������� ������ �� ������ ���� "String"
	*@return true ��� false
	*/
	bool operator==(const String& obj);

	/*
	*@brief ���������� ��������� !=
	*@param ����������� ������ �� ������ ���� "String"
	*@return true ��� false
	*/
	bool operator!=(const String& obj);

	/*
	*@brief ���������� ��������� <
	*@param ����������� ������ �� ������ ���� "String"
	*@return true ��� false
	*/
	bool operator<(const String& obj);

	/*
	*@brief ���������� ��������� >
	*@param ����������� ������ �� ������ ���� "String"
	*@return true ��� false
	*/
	bool operator>(const String& obj);

	/*
	*@brief ���������� ��������� <=
	*@param ����������� ������ �� ������ ���� "String"
	*@return true ��� false
	*/
	bool operator<=(const String& obj);

	/*
	*@brief ���������� ��������� >=
	*@param ����������� ������ �� ������ ���� "String"
	*@return true ��� false
	*/
	bool operator>=(const String& obj);

	/*
	*@brief ���������� ��������� []
	*@param ����������� �����
	*@return ��������� �� ������
	*/
	char& operator[](int index);
};