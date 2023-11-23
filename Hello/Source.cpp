#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;
//one commit
class SIGN
{
	string name;
	string zodiak;
	int birthday[3];

public:
	void setterName(string name) { this->name = name; }
	void setterZodiak(string zodiak) { this->zodiak = zodiak; }
	void setterBirthday(int birthday, int i) { this->birthday[i] = birthday; }

	string getterName() { return name; }
	string getterZodiak() { return zodiak; }
	int getterBirthday(int i) { return birthday[i]; }

	SIGN()
	{
		cout << "calling a constructor SIGN()\n";
		system("pause");
		system("cls");
	}

	SIGN operator = (const SIGN& other)
	{
		name = other.name;
		zodiak = other.zodiak;
		for (int j = 0; j < 3; j++)
		{
			birthday[j] = other.birthday[j];
		}

		return *this;
	}

	void Input_consl()
	{
		string str;
		cout << "Name: ";
		getline(cin, str);
		setterName(str);
		cout << "Zodiak: ";
		getline(cin, str);
		setterZodiak(str);
		cout << "Birthday: ";
		getline(cin, str);
		int i = 0;
		int n = 0;
		int data;
		string str1;
		while (str[i] != '\0')
		{
			if (str[i] == '.')
			{
				data = stoi(str1);
				setterBirthday(data, n);
				n++;
				str1.clear();
			}
			else
			{
				str1 += str[i];
			}
			i++;
		}
		data = stoi(str1);
		setterBirthday(data, n);
	}

	~SIGN()
	{
		cout << "calling a destructor SIGN()\n";
		system("pause");
		system("cls");
	}

	void show()
	{
		cout << name << "   " << zodiak << "   ";
		for (int j = 0; j < 3; j++)
		{
			if (j == 2)
			{
				cout << birthday[j] << endl;
			}
			else
			{
				cout << birthday[j] << '.';
			}

		}
	}
};

class Array_sign
{
	SIGN* arr;
	int n;

public:

	int getterN() { return n; }

	Array_sign()
	{
		cout << "calling a constructor Array_sign()\n";
		system("pause");
		system("cls");
		n = 0;
		arr = new SIGN[n];
	}

	Array_sign(const Array_sign& other)
	{
		cout << "calling a constructor copy Array_sign()\n";
		system("pause");
		system("cls");
		n = other.n;
		arr = new SIGN[n];
		for (int j = 0; j < n; j++)
		{
			arr[j] = other.arr[j];
		}
	}

	Array_sign operator++ (int a)
	{
		Array_sign buf(*this);
		delete[]arr;
		n++;
		arr = new SIGN[n];
		for (int j = 0; j < n - 1; j++)
		{
			arr[j] = buf.arr[j];
		}
		arr[n - 1].Input_consl();

		return *this;
	}

	void show()
	{
		for (int j = 0; j < n; j++)
		{
			cout << j + 1 << ".   ";
			arr[j].show();
		}
	}

	~Array_sign()
	{
		cout << "calling a destructor Array_sign()\n";
		system("pause");
		system("cls");
		delete[]arr;
	}
};

int main()
{
	Array_sign one;
	one++;
	one.show();
	return 0;
}
