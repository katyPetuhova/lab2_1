#pragma once
#include "SIGN.h"
istream& operator>> (istream& is, SIGN& object)
{
	string str;
	cout << "Name: ";
	getline(cin, str);
	//is >> str;
	object.setterName(str);
	cout << "Zodiak: ";
	getline(cin, str);
	//is >> str;
	object.setterZodiak(str);
	cout << "Birthday: ";
	getline(cin, str);
	//is >> str;
	int i = 0;
	int k = 0;
	int data;
	string str1;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			data = stoi(str1);
			object.setterBirthday(data, k);
			k++;
			str1.clear();
		}
		else
		{
			str1 += str[i];
		}
		i++;
	}
	data = stoi(str1);
	object.setterBirthday(data, k);
	return is;
}