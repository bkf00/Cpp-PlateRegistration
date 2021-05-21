#include "person.h"

void person::set_person() {
	cout << "Name: ";
	cin >> name;
	cout << "Age: ";
	cin >> age;
	cout << "Job: ";
	cin >> job;
};

void person::print_person() {
	cout << name << ", " << age << ", " << job << endl;
}
