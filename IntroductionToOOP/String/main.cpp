//String
#include<iostream>
using namespace std;
#define tab "\t"
#define delimiter "\n--------------------------------------------------------\n"

class String
{
	int	size;	//Размер строки в Байтах
	char* str;	//Адрес строки в динамической памяти
public:
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}
	int get_size()const
	{
		return size;
	}

	//			Constructors:

	explicit String(int size = 80) : size(size), str(new char[size] {})
	{
		//this->size = size;
		//this->str = new char[size] {};
		cout << "DefaultConstructor:\t" << this << endl;
	}
	String(const char str[]) : String(strlen(str) + 1)
	{
		//this->size = strlen(str) + 1;
		//this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other) : String(other.str)
	{
		//Deep copy
		//this->size = other.size;
		//this->str = new char[size] {};
		//for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t\t" << this << endl;
	}
	//String(String&&) = delete;
	~String()
	{
		delete[] this->str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//				Operators:

	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}

	//				Methods:

	void print()const
	{
		cout << "Obj:\t" << this << tab;
		cout << "Size:\t" << size << tab;
		cout << "AddrStr:\t" << &str << tab;
		cout << "Str:\t" << str << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	//explicit конструктор вызывается круглыми скобками, не через оператор присваивания
	String buffer(left.get_size() + right.get_size() - 1); //from int to String
	for (int i = 0; i < left.get_size(); i++)
		buffer.get_str()[i] = left.get_str()[i]; //для константного вызывается константный, для неконстантного - неконстантный
	for (int i = 0; i < right.get_size(); i++)
		buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	//buffer.print();
	return buffer;
}	

#define CONSTRUCTORS_CHECK
//#define CAT_CHECK

int main()
{
	setlocale(LC_ALL, "");

#ifdef CAT_CHECK
	//String str;
//str.print();

	String str1 = "Hello";
	String str2 = "World";
	//str1.print();
	//str2.print();

	cout << delimiter << endl;

	//String str3 = str1 + str2; //CopyConstructor //в 22 MoveConstructor
	String str3;
	str1 = str1;
	str3 = str1 + " " + str2; //CopyAssignment
	str3.print();
	//cout << str3 << endl;	//HelloWorld  
#endif // CAT_CHECK

#ifdef CONSTRUCTORS_CHECK
	String str1; //Default constructor
	str1.print();

	String str2(8); //1ArgConstructor
	str2.print();

	String str3 = "Hello"; //1ArgConstructor
	str3.print();
	
	String str4(); //Здесь НЕ вызывается конструктор и НЕ создается объект,
				   //в этом выражении объявляется функция Str4,
				   //которая ничего не принимает и возвращает объект класса String
	//str4.print();

	String str5{}; //Явный вызов конструктора по умолчанию
	str5.print();

	String str6{ str3 }; //Передача в конструктор по фигурным
	str6.print();
#endif // CONSTRUCTORS_CHECK

}