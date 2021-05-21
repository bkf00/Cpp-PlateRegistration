#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <windows.h>

#include "dataTime.h"
#include "person.h"
using namespace std;

class vehicle :public dataTime, public person
{
private:
	float engineVolume;
	int horsePower;
	string category;
	string brand;
	string fuel;
	string color;
	string plateNumber;
	person owner;
	dataTime regDate;
	dataTime lastRev;
public:
	vehicle() {
		engineVolume = 0;
		horsePower = 0;
		category = "";
		brand = "";
		fuel = "";
		plateNumber = "";
	}
	~vehicle() {
		//do nothing
	}
	float getVolume() { return engineVolume; }
	int getHP() { return horsePower; }
	string getCategory() { return category; }
	string getBrand() { return brand; }
	string getFuel() { return fuel; }
	string getColor() { return color; }
	string getPlate() { return plateNumber; }
	person getOwner() { return owner; }
	dataTime getRegDate() { return regDate; }
	dataTime getRevDate() { return lastRev; }

	void setOwner(person ownerN) { owner = ownerN; }
	void setCategory(string categoryN) { category = categoryN; }
	void setBrand(string brandN) { brand = brandN; }
	void setVolume(float volumeN) { engineVolume = volumeN; }
	void setHP(int hpN) { horsePower = hpN; }
	void setFuel(string fuelN) { fuel = fuelN; }
	void setColor(string colorN) { color = colorN; }
	void setPlate(string plateN) { plateNumber = plateN; }
	void setRegDate(dataTime regDateN) { regDate = regDateN; }
	void setRevDate(dataTime revDateN) { lastRev = revDateN; }

	vehicle read_register(fstream&);
	bool operator<(const vehicle) const;
	void add_vehicle();
	void print_vehicle();
};
#endif // !VEHICLE_H