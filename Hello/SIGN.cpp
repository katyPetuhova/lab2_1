#pragma once
#include "SIGN.h"

	void SIGN:: setterName(string name) { this->name = name; }
	void SIGN:: setterZodiak(string zodiak) { this->zodiak = zodiak; }
	void SIGN:: setterBirthday(int birthday, int i) { this->birthday[i] = birthday; }

	string SIGN:: getterName() { return name; }
	string SIGN:: getterZodiak() { return zodiak; }
	int SIGN:: getterBirthday(int i) { return birthday[i]; }

	SIGN:: SIGN()
	{
		/*cout << "calling a constructor SIGN()\n";
		system("pause");
		system("cls");*/
	}

	SIGN SIGN:: operator = (const SIGN& other)
	{
		name = other.name;
		zodiak = other.zodiak;
		for (int j = 0; j < 3; j++)
		{
			birthday[j] = other.birthday[j];
		}

		return *this;
	}

	SIGN::~SIGN ()
	{
		/*cout << "calling a destructor SIGN()\n";
		system("pause");
		system("cls");*/
	}
