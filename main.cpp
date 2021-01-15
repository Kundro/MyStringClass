#include <iostream>
using namespace std;

class MyString
{
public:
	MyString()  // конструктор - без параметров
	{
		str = nullptr;
	}
	MyString(char *str)  // конструктор с параметрами, которому необходимо передать страку, которую он будет хранить
	{
		int length = strlen(str); // функция strlen получает кол-во символов в строке, которую мы передаем в обьект
		
		// выделяем память для динамического массива где будет хранится наша строка
		// +1 символ, т.к. нужно местро под терминирующий ноль
		this->str = new char[length + 1];

		// копируем символы строки в массив нашего класса
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}

		// закрываем строку терминирующим нулём
		this->str[length] = '\0'; 
	}
	~MyString() // деструктор
	{
		delete[] this->str;    // отвечает за освобождение ресурсов занятых объектом (вызывается при уничтожении объекта класса)
	}
	void Print()
	{
		cout << str;
	}
	MyString& operator=(const MyString& other) // перегруженный оператор присваивания 
	{
		if (this->str != nullptr)
		{
			delete[]this->str;
		}
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';

		return *this;
	}

	MyString(const MyString& other) // конструктор копирования, необходим для создания точной копии объекта класса
									// но в другой области памяти
	{
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	MyString operator+(const MyString& other) // перегруженный оператор сложения (для конкатенации строк)
	{
		MyString temp; // создаем новый пустой обьект где будем хранить рез-т конкатенации строк и который будет результатом работы
		int thisLength = strlen(this->str);
		int otherLength = strlen(other.str);

		temp.str = new char[thisLength + otherLength + 1];
		int i = 0;
		for  ( ; i < thisLength; i++)
		{
			temp.str[i] = this->str[i];
		}
		for (int j = 0; j < otherLength; j++,i++)
		{
			temp.str[i] = other.str[j];
		}
		temp.str[thisLength + otherLength] = '\0';
		return temp;
	}

	int Length() {

	}

private: // указатель на массив char, хранит символы, которые мы передали в наш объект 
	char* str;
};  


int main()
{
	char test[80] = "Hello ";
	char test2[80] = "World";
	MyString str(test);   // НЕ могу инициализировать класс MyString таким образом - MyString a("Hello"); ??????
	MyString str2(test2);
	str.Print();
	cout << endl << "--------------"<<endl;
	MyString result;
	result = str + str2;
	result.Print();
	return 0;
}