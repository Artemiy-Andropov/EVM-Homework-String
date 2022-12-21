#pragma once
#include <iostream>

class String
{
private:

	char* m_string;
	int m_size;

public:

	/*
	*@brief Конструктор
	*/
	String();

	/*
	*@brief Конструктор с параметрами
	*@param Строка
	*@param Натуральное число (Размер)
	*/
	String(const char* string_, int size);

	/*
	*@brief Конструктор копирования
	*@param Константная ссылка на объект типа "String"
	*/
	String(const String& obj);

	/*
	*@brief Деструктор
	*/
	~String();

	/*
	*@brief Удаление строки
	*@param Ссылка на объект типа "String"
	*/
	void Delete(String& obj);

	/*
	*@brief Проверяет, пустая ли строка
	*@return true или false
	*/
	bool IsEmpty();

	/*
	*@brief Возвращает размер строки
	*@return Натуральное число
	*/
	int Lenght();

	/*
	*@brief Возвращает указатель на выбранный символ
	*@param Натуральное число
	*@return Указатель на символ
	*/
	char& At(int position);

	/*
	*@brief Возвращает указатель на первый символ
	*@return Указатель на первый символ
	*/
	char& Front();

	/*
	*@brief Возвращает указатель на последний символ
	*@return Указатель на последний символ
	*/
	char& Back();

	/*
	*@brief Очищает строку (Вместо символов помещает пробелы)
	*/
	void Clear();

	/*
	*@brief Вставляет символ на выбранную позицию
	*@param Символ
	*@param Натуральное число
	*/
	void Insert(char symbol, int position);

	/*
	*@brief Удаляет выбранный символ или диапозон
	*@param Натуральное число (Начало диапозона)
	*@param Натуральное число (Конец диапозона)
	*/
	void Erase(int begin, int end);

	/*
	*@brief Вставляет символ в конец строки
	*@param Символ
	*/
	void Push_Back(char symbol);

	/*
	*@brief Меняет размер строки. Если больше, то вставляет на новые места символ, иначе удаляет
	*@param Натуральное число (Новый размер)
	*@param Символ
	*/
	void Resize(int size_, char symbol);

	/*
	*@brief Меняет строки местами
	*@param Cсылка на объект типа "String"
	*/
	void Swap(String& obj);

	/*
	*@brief Конкатенация строк
	*@param Константная ссылка на объект типа "String"
	*/
	void Append(const String& obj);

	/*
	*@brief Возвращает "Си" строку
	*@return "Си" строка
	*/
	String C_str();

	/*
	*@brief Копирует строку
	*@param Константная ссылка на объект типа "String"
	*/
	void Copy(const String& obj);

	/*
	*@brief Поиск строки с выбранной позиции
	*@param Константная ссылка на объект типа "String"
	*@param Натуральное число (Позиция)
	*@return true или false
	*/
	bool Find(const String& obj, int position);

	/*
	*@brief Генерирует строку с выбранной позиции и нужным количеством символов
	*@param Натуральное число (Позиция)
	*@param Натуральное число (Количество символов)
	*@return Подстрока
	*/
	String SubStr(int position, int amount);

	/*
	*@brief Сравнение строк
	*@param Константная ссылка на объект типа "String"
	*@return true или false
	*/
	bool Compare(const String& obj);

	/*
	*@brief Перегрузка оператора вывода
	*@param Ссылка на поток вывода
	*@param Константная ссылка на объект типа "String"
	*@return Ссылка на поток вывода
	*/
	friend std::ostream& operator<<(std::ostream& out, const String& obj);

	/*
	*@brief Перегрузка оператора ввода
	*@param Ссылка на поток ввода
	*@param Ссылка на объект типа "String"
	*@return Ссылка на поток ввода
	*/
	friend std::istream& operator>>(std::istream& in, String& obj);

	/*
	*@brief Перегрузка оператора присваивания
	*@param Константная ссылка на объект типа "String"
	*@return Ссылка на объект типа "String"
	*/
	String& operator=(const String& obj);

	/*
	*@brief Перегрузка оператора +
	*@param Константная ссылка на объект типа "String"
	*@return Объект типа "String"
	*/
	String operator+(const String& obj);

	/*
	*@brief Перегрузка оператора +=
	*@param Константная ссылка на объект типа "String"
	*@return Ссылка на объект типа "String"
	*/
	String& operator+=(const String& obj);

	/*
	*@brief Перегрузка оператора ==
	*@param Константная ссылка на объект типа "String"
	*@return true или false
	*/
	bool operator==(const String& obj);

	/*
	*@brief Перегрузка оператора !=
	*@param Константная ссылка на объект типа "String"
	*@return true или false
	*/
	bool operator!=(const String& obj);

	/*
	*@brief Перегрузка оператора <
	*@param Константная ссылка на объект типа "String"
	*@return true или false
	*/
	bool operator<(const String& obj);

	/*
	*@brief Перегрузка оператора >
	*@param Константная ссылка на объект типа "String"
	*@return true или false
	*/
	bool operator>(const String& obj);

	/*
	*@brief Перегрузка оператора <=
	*@param Константная ссылка на объект типа "String"
	*@return true или false
	*/
	bool operator<=(const String& obj);

	/*
	*@brief Перегрузка оператора >=
	*@param Константная ссылка на объект типа "String"
	*@return true или false
	*/
	bool operator>=(const String& obj);

	/*
	*@brief Перегрузка оператора []
	*@param Натуральное число
	*@return Указатель на символ
	*/
	char& operator[](int index);
};