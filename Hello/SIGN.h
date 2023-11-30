#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
#include <locale.h>
#include <conio.h>

using namespace std;

class SIGN
{
	string name;
	string zodiak;
	int birthday[3];

public:
	void setterName(string name);
	void setterZodiak(string zodiak);
	void setterBirthday(int birthday, int i);

	string getterName();
	string getterZodiak();
	int getterBirthday(int i);

	SIGN();
	SIGN operator = (const SIGN& other);

	~SIGN();

	friend ostream& operator<<(ostream& os, const SIGN& object);
	friend istream& operator>>(istream& is, SIGN& object);

};