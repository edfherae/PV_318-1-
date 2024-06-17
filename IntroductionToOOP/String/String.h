#pragma once
#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "\n--------------------------------------------------------\n"

class String
{
	int	size;	//������ ������ � ������
	char* str;	//����� ������ � ������������ ������
public:
	const char* get_str()const;
	char* get_str();
	int get_size()const;

	//			Constructors:

	explicit String(int size = 80); //explicit ������ ������ ������
	String(const char str[]);
	String(const String& other);
	~String();

	//				Operators:

	String& operator=(const String& other);

	//				Methods:

	void print()const;
};

std::ostream& operator<<(std::ostream& os, const String& obj);
String operator+(const String& left, const String& right);