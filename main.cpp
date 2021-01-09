#include <iostream>
using namespace std;

class MyString
{
public:
	MyString()
	{
		str = nullptr;
	}
	MyString(char *str)
	{
		int length = strlen(str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = str[i];
		}
		this->str[length] = '\0'; 
	}
	~MyString() 
	{
		delete[] this->str;  
	}
	void Print()
	{
		cout << str;
	}
	MyString& operator=(const MyString& other)
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

	MyString(const MyString& other)
	{
		int length = strlen(other.str);
		this->str = new char[length + 1];
		for (int i = 0; i < length; i++)
		{
			this->str[i] = other.str[i];
		}
		this->str[length] = '\0';
	}

	MyString operator+(const MyString& other)
	{
		MyString temp;
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
private:
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