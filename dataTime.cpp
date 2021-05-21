#include "dataTime.h"

void dataTime::setDate(int a, int b, int c)
{
	if (a <= 31 && a > 0)
		day = a;
	else
	{
		cout << "Enter a valid day!";
	};
	if (b <= 12 && b > 0)
		month = b;
	else
	{
		cout << "Enter a valid month!";
	};
	if (c <= 2020 && c > 1900)
		year = c;
	else
	{
		cout << "Enter a valid year!";
	};
}

void dataTime::printDate()
{
	cout << day << "/" << month << "/" << year;
}

