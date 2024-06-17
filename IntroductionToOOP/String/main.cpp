//String
#include "String.h"

//#define CONSTRUCTORS_CHECK
#define CAT_CHECK

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