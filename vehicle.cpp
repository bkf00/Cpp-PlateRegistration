#include "vehicle.h"

void vehicle::add_vehicle() {
	int regDay, regMonth, regYear;
	int revDay, revMonth, revYear;
	cout << "Enter owner data: " << endl;
	owner.set_person();
	cout << "Enter your vehicle data below:" << endl;
	cout << "Category (A,B,C,D,...): ";
	cin >> category;
	cout << "Brand: ";
	cin >> brand;
	cout << "Engine volume: ";
	cin >> engineVolume;
	cout << "Horse power: ";
	cin >> horsePower;
	cout << "Fuel type: ";
	cin >> fuel;
	cout << "Color: ";
	cin >> color;
	cout << "Plate number:";
	cin >> plateNumber;
	cout << "Registration date: " << endl;
	cout << "Day of registration: ";
	cin >> regDay;
	cout << "Month of registration: ";
	cin >> regMonth;
	cout << "Year of registration: ";
	cin >> regYear;
	regDate.setDate(regDay, regMonth, regYear);
	cout << "Tehnical revision date: " << endl;
	cout << "Day of the last revision: ";
	cin >> revDay;
	cout << "Month of the last revision: ";
	cin >> revMonth;
	cout << "Year of the last revision: ";
	cin >> revYear;
	lastRev.setDate(revDay, revMonth, revYear);


};

void vehicle::print_vehicle() {
	cout << endl;
	cout << "Car information: " << endl;
	cout << "Owner: "; owner.print_person();
	cout << "Category :" << category << endl;
	cout << "Brand: " << brand << endl;
	cout << "Engine volume: " << engineVolume << endl;
	cout << "Horse power: " << horsePower << endl;
	cout << "Fuel type: " << fuel << endl;
	cout << "Color: " << color << endl;
	cout << "Plate number:" << plateNumber;
	cout << endl << "Registration date: ";
	regDate.printDate();
	cout << endl << "Last revision date: ";
	lastRev.printDate();
	cout << endl;

}
vehicle vehicle::read_register(fstream& citire) {

	vehicle cars;
	person newOwner;
	float newVolume;
	int newHP;
	string newCat, newBrand, newFuel, newColor, newPlate;
	dataTime newRegDate, newRevDate;

	citire >> newOwner;
	citire >> newCat;
	citire >> newBrand;
	citire >> newVolume;
	citire >> newHP;
	citire >> newFuel;
	citire >> newColor;
	citire >> newPlate;
	citire >> newRegDate;
	citire >> newRevDate;

	cars.setOwner(newOwner);
	cars.setCategory(newCat);
	cars.setBrand(newBrand);
	cars.setVolume(newVolume);
	cars.setHP(newHP);
	cars.setFuel(newFuel);
	cars.setColor(newColor);
	cars.setPlate(newPlate);
	cars.setRegDate(newRegDate);
	cars.setRevDate(newRevDate);

	return cars;
}

bool vehicle::operator<(const vehicle c) const
{
	return category < c.category;
}

