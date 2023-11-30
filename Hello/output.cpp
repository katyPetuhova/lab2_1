#pragma once
#include "SIGN.h"
ostream& operator<<(ostream& os, const SIGN& object)
{
	os << object.name << "   " << object.zodiak << "   ";
	for (int j = 0; j < 3; j++)
	{
		if (object.birthday[j] < 10)
		{
			os << "0";
		}
		if (j == 2)
		{
			os << object.birthday[j] << endl;
		}
		else
		{
			os << object.birthday[j] << '.';
		}

	}
	return os;
}