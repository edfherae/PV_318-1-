﻿//String
#include<iostream>
using namespace std;

class String
{
	int	size;	//Размер строки в Байтах
	char* str;	//Адрес строки в динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}
	//			Constructors:
	String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}

void main()
{
	setlocale(LC_ALL, "");
	//String str;
	//str.print();

	String str1 = "Hello";
	String str2 = "World";
	cout << str1 << endl;
	cout << str2 << endl;

	//String str3 = str1 + str2;
	//cout << str3 << endl;	//HelloWorld
}