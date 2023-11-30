#pragma once
#include "SIGN.h"
class Array_sign
{
	SIGN* arr;
	int n;

public:

	int getterN();

	Array_sign();
	Array_sign(const Array_sign& other);
	void Add();
	void Delete(int k);
	void Sort();
	void Search(string surname);
	void Redak(int k);
	void show();
	~Array_sign();
};