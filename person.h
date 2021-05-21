#ifndef PERSON_H
#define PERSON_H


#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <windows.h>
using namespace std;

class person {
private:
	int age;
	string name, job;
public:
	person()
	{
		age = 0;
		name = "";
		job = "";
	}
	~person() {
		//do nothing
	}
	friend ostream& operator<<(ostream& out, const person& nume) {
		out << nume.name << " ";
		out << nume.age << " ";
		out << nume.job << " ";
		return out;
	}
	friend istream& operator>>(istream& in, person& nume) {
		in >> nume.name;
		in >> nume.age;
		in >> nume.job;
		return in;
	}
	string getName() { return name; }
	void set_person();
	void print_person();
};
#endif // !PERSON_H