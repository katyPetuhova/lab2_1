#include "Array_sign.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, "russian");
	Array_sign one;
	string str;
	int k;
	HANDLE hStdout;
	WORD foregroundColor; // color of string constants
	WORD foregroundColor1; // character color
	WORD backgroundColor; // background color
	WORD textAttribute; // text attribute - color
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	foregroundColor = FOREGROUND_INTENSITY |
		FOREGROUND_BLUE |
		FOREGROUND_RED;
	foregroundColor1 = FOREGROUND_INTENSITY |
		FOREGROUND_BLUE |
		FOREGROUND_GREEN |
		FOREGROUND_RED;
	backgroundColor = 0;
	SetConsoleTextAttribute(hStdout, foregroundColor1 | backgroundColor);
	char c, c1;
	int flag = 1;
	const char* oper[] =
	{
	"Меню:",
	" 1 – Adding an information",
	" 2 – Search for information",
	" 3 – Removing an information",
	" 4 – Displaying a list on the screen",
	" 5 – Sorting information",
	" 6 – Editing an information",
	" 7 - Exit the program",
	};
	int count = 1;
	while (flag != 0)
	{
		for (int i = 0; i < 8; i++)
		{
			if (count == i)
			{
				textAttribute = foregroundColor | backgroundColor;
				SetConsoleTextAttribute(hStdout, textAttribute);
				cout << oper[i] << endl;
			}
			else
			{
				SetConsoleTextAttribute(hStdout, foregroundColor1 |
					backgroundColor);
				cout << oper[i] << endl;
			}
		}
		c = _getch();
		if (c == 's')
		{
			system("cls");
				count++;
		}
		if (c == 'w')
		{
			system("cls");
			count--;
		}
		if (count == 0)
		{
			count = 7;
		}
		if (count == 8)
		{
			count = 1;
		}
		if (c == ' ')
		{
			if (count == 1)
			{
				system("cls");
				one.Add();
				cout << "0-Вернутся в меню: ";
				c1 = _getch();
				if (c1 == '0')
				{
					system("cls");
				}
				count = 1;
			}
			if (count == 2)
			{
				system("cls");
				cout << "Enter last name: ";
				getline(cin, str);
				try
				{
					one.Search(str);
				}
				catch (const char* error_message)
				{
					cout << error_message << endl;
				}
				cout << "0-Вернутся в меню: ";
				c1 = _getch();
				if (c1 == '0')
				{
					system("cls");
				}
				count = 1;
			}
			if (count == 3)
			{
				system("cls");
				one.show();
				cout << "Enter the number of the object to be deleted: ";
				getline(cin, str);
				k = stoi(str);
				one.Delete(k);
				system("cls");
				one.show();
				cout << "0-Вернутся в меню: ";
				c1 = _getch();
				if (c1 == '0')
				{
					system("cls");
				}
				count = 1;
			}
			if (count == 4)
			{
				system("cls");
				one.show();
				cout << "0-Вернутся в меню: ";
				c1 = _getch();
				if (c1 == '0')
				{
					system("cls");
				}
				count = 1;
			}
			if (count == 5)
			{
				system("cls");
				one.Sort();
				one.show();
				cout << "0-Вернутся в меню: ";
				c1 = _getch();
				if (c1 == '0')
				{
					system("cls");
				}
				count = 1;
			}
			if (count == 6)
			{
				system("cls");
				one.show();
				cout << "Enter the edit object number: ";
				getline(cin, str);
				k = stoi(str);
				system("cls");
				one.Redak(k);
				system("cls");
				one.show();
				cout << "0-Вернутся в меню: ";
				c1 = _getch();
				if (c1 == '0')
				{
					system("cls");
				}
				count = 1;
			}
			if (count == 7)
			{
				SetConsoleTextAttribute(hStdout, foregroundColor1 |backgroundColor);
				system("cls");
				flag = 0;
				break;
			}
		}
	}
	return 0;
}
