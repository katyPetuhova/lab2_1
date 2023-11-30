#pragma once
#include "Array_sign.h"

	int Array_sign:: getterN() { return n; }

	Array_sign::Array_sign()
	{
		/*cout << "calling a constructor Array_sign()\n";
		system("pause");
		system("cls");*/
		n = 0;
		arr = new SIGN[n];
	}

	Array_sign::Array_sign(const Array_sign& other)
	{
		/*cout << "calling a constructor copy Array_sign()\n";
		system("pause");
		system("cls");*/
		n = other.n;
		arr = new SIGN[n];
		for (int j = 0; j < n; j++)
		{
			arr[j] = other.arr[j];
		}
	}

	void Array_sign:: Add()
	{
		Array_sign buf(*this);
		delete[]arr;
		n++;
		arr = new SIGN[n];
		for (int j = 0; j < n - 1; j++)
		{
			arr[j] = buf.arr[j];
		}
		cin >> arr[n - 1];
	}

	void Array_sign::Delete(int k)
	{
		Array_sign buf(*this);
		delete[]arr;
		n--;
		arr = new SIGN[n];
		for (int j = 0; j < k - 1; j++)
		{
			arr[j] = buf.arr[j];
		}
		for (int j = k - 1; j < n; j++)
		{
			arr[j] = buf.arr[j + 1];
		}
	}

	void Array_sign::Sort()
	{
		SIGN buf;
		for (int i = 0; i < n - 1; i++)
		{
			for (int j = 0; j < n - i - 1; j++)
			{
				if (arr[j].getterBirthday(3) > arr[j + 1].getterBirthday(3))
				{
					buf = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = buf;
				}
				if ((arr[j].getterBirthday(3) == arr[j + 1].getterBirthday(3)) && (arr[j].getterBirthday(2) > arr[j + 1].getterBirthday(2)))
				{
					buf = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = buf;
				}
				if ((arr[j].getterBirthday(3) == arr[j + 1].getterBirthday(3)) && (arr[j].getterBirthday(2) == arr[j + 1].getterBirthday(2)) && (arr[j].getterBirthday(1) > arr[j + 1].getterBirthday(1)))
				{
					buf = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = buf;
				}
			}
		}

	}

	void Array_sign::Search(string surname)
	{

		int flag_error = 0;
		int flag_search;
		int j;
		string str;
		int count = 1;
		for (int i = 0; i < n; i++)
		{
			flag_search = 0;
			j = 0;
			str = arr[i].getterName();
			while ((str[j] != ' ') && (j <= surname.size()))
			{
				if (str[j] != surname[j])
				{
					flag_search = 1;
				}
				j++;
			}
			if (flag_search == 0)
			{
				flag_error = 1;
				cout << count << ".  ";
				cout << arr[i];
				count++;
			}
		}
		if (flag_error == 0)
		{
			throw "There is no information about this person";
		}
	}

	void Array_sign::Redak(int k)
	{
		cin >> arr[k - 1];
	}

	void Array_sign::show()
	{
		for (int j = 0; j < n; j++)
		{
			cout << j + 1 << ".   ";
			cout << arr[j];
		}
	}

	Array_sign::~Array_sign()
	{
		/*cout << "calling a destructor Array_sign()\n";
		system("pause");
		system("cls");*/
		delete[]arr;
	}