#ifndef DATATIME_H
#define DATATIME_H


#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <windows.h>
using namespace std;

class dataTime
{
private:
	int day, month, year;
public:
	dataTime() {
		day = 0;
		month = 0;
		year = 0;
	}
	~dataTime() {

	}
	friend ostream& operator<<(ostream& out, const dataTime& timp) {
		out << timp.day << " ";
		out << timp.month << " ";
		out << timp.year;
		return out;
	}
	friend istream& operator>>(istream& in, dataTime& timp) {
		in >> timp.day;
		in >> timp.month;
		in >> timp.year;
		return in;
	}
	int getDay() { return day; }
	int getMonth() { return month; }
	int getYear() { return year; }
	void setDate(int, int, int);
	void printDate();
};
#endif // !DATATIME_H