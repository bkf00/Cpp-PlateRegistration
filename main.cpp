

#include "dataTime.h"
#include "person.h"
#include "vehicle.h"
#include "password.h"
using namespace std;

int login() {
	char password[80], my_password[20];
	int no_attempt, ok;
	FILE* pass;

	fopen_s(&pass, "PASS.TXT", "r");
	if (pass != NULL) {
		fscanf_s(pass, "%s", my_password, 20);
		decode_pass(my_password);
		fclose(pass);
	}
	else
	{
		cout << "\nError opening file";
		cin.get();
		exit(0);
	}
	no_attempt = 0;
	ok = 0;
	do {
		system("cls");
		cout << "Enter pasword: ";
		read_pass(password);
		if (strcmp(password, my_password) == 0)
		{
			ok = 1;
			break;
		}
		no_attempt++;
	} while (no_attempt < 3);
	if (ok == 0)
	{
		cout << "\n\n INCORRECT PASSWORD !";
		cin.get();
		return 0;
	}

	cout << "\n\n~~~~~~~~~~~~~~~~~~ Password correct, Welcome ! ~~~~~~~~~~~~~~~~~~\n\n";
}

void print_register(vehicle cars) {
	fstream scriere;
	scriere.open("REGISTER.TXT", ios::app);
	if (scriere.is_open())
	{

		scriere << cars.getOwner();
		scriere << cars.getCategory() << " ";
		scriere << cars.getBrand() << " ";
		scriere << cars.getVolume() << " ";
		scriere << cars.getHP() << " ";
		scriere << cars.getFuel() << " ";
		scriere << cars.getColor() << " ";
		scriere << cars.getPlate() << " ";
		scriere << cars.getRegDate() << " ";
		scriere << cars.getRevDate() << "\n";
		scriere.close();
	}
	else
	{
		cout << "Unable to open file";
		exit(1);
	}




}

void register_car() {
	vehicle newCar;
	newCar.add_vehicle();
	print_register(newCar);
	cout << endl << endl << "Registered car: ";
	newCar.print_vehicle();

}

bool search_plate(string plate, int car_pos, vehicle CARS[]) 
{
	int ok = 0;
	for (int j = 0; j < car_pos; j++)
	{
		if (plate == CARS[j].getPlate())
		{
			ok = 1;
			CARS[j].print_vehicle();
		}
	}
	if (ok == 0)
	{
		cout << "-------------------------------------------------------\n";
		cout << "                 Plate not registered! \n";
		cout << "-------------------------------------------------------\n\n";
	}
	return ok;
}

void search_owner(string owner, int car_pos, vehicle CARS[]) {
	int ok = 0;
	for (int j = 0; j < car_pos; j++)
	{
		if (owner == CARS[j].getOwner().getName())
		{
			CARS[j].print_vehicle();
			ok = 1;
		}
	}
	if (ok == 0)
	{
		cout << "-------------------------------------------------------\n";
		cout << "           This person does not own any cars! \n";
		cout << "-------------------------------------------------------\n\n";
	}
}

void change_feature(string plate_string) {
	ifstream fin;
	fstream temp;
	string line;
	size_t found;
	vehicle cars;
	person newOwner;
	float newVolume;
	int newHP;
	string newCat, newBrand, newFuel, newColor, newPlate;
	dataTime newRegDate, newRevDate;

	temp.open("temp.txt");
	fin.open("REGISTER.TXT");

	while (getline(fin, line))
	{
		found = line.find(plate_string);

		if (found != string::npos)
		{
			fin >> newOwner;
			fin >> newCat;
			fin >> newBrand;
			fin >> newVolume;
			fin >> newHP;
			fin >> newFuel;
			fin >> newColor;
			fin >> newPlate;
			fin >> newRegDate;
			fin >> newRevDate;

			cout << "Enter the new HP of the car:";
			cin >> newHP;
			cout << "Enter the new color of the car:";
			cin >> newColor;

			line.replace(0, line.length(), "");

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

			temp << cars.getOwner() << " ";
			temp << cars.getCategory() << " ";
			temp << cars.getBrand() << " ";
			temp << cars.getVolume() << " ";
			temp << cars.getHP() << " ";
			temp << cars.getFuel() << " ";
			temp << cars.getColor() << " ";
			temp << cars.getPlate() << " ";
			temp << cars.getRegDate() << " ";
			temp << cars.getRevDate() << endl;
			cars.print_vehicle();

			}
		temp << line << endl;
	}
	temp.close();
	fin.close();
	remove("REGISTER.TXT");
	rename("temp.txt", "REGISTER.TXT");
}

void maintenance_date(string plate_string) {
	ifstream fin;
	fstream scriere;
	ofstream temp;
	string line;
	size_t found;
	vehicle cars;
	person newOwner;
	float newVolume;
	int newHP, revDay, revMonth, revYear;
	string newCat, newBrand, newFuel, newColor, newPlate;
	dataTime newRegDate, newRevDate;

	temp.open("temp.txt");
	fin.open("REGISTER.TXT");

	while (getline(fin, line))
	{
		found = line.find(plate_string);

		if (found != string::npos)
		{
			fin >> newOwner;
			fin >> newCat;
			fin >> newBrand;
			fin >> newVolume;
			fin >> newHP;
			fin >> newFuel;
			fin >> newColor;
			fin >> newPlate;
			fin >> newRegDate;
			fin >> newRevDate;

			cout << "Tehnical revision date: " << endl;
			cout << "Day of the last revision: ";
			cin >> revDay;
			cout << "Month of the last revision: ";
			cin >> revMonth;
			cout << "Year of the last revision: ";
			cin >> revYear;
			newRevDate.setDate(revDay, revMonth, revYear);

			line.replace(0, line.length(), "");

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

			temp << cars.getOwner();
			temp << cars.getCategory() << " ";
			temp << cars.getBrand() << " ";
			temp << cars.getVolume() << " ";
			temp << cars.getHP() << " ";
			temp << cars.getFuel() << " ";
			temp << cars.getColor() << " ";
			temp << cars.getPlate() << " ";
			temp << cars.getRegDate() << " ";
			temp << cars.getRevDate();
			cars.print_vehicle();
		}
		temp << line << endl;
	}
	temp.close();
	fin.close();
	remove("REGISTER.TXT");
	rename("temp.txt", "REGISTER.TXT");
}

void remove_records(string plate_string) {
	ifstream fin;
	ofstream temp;
	string line;
	size_t found;

	temp.open("temp.txt");
	fin.open("REGISTER.TXT");

	while (getline(fin, line))
	{
		found = line.find(plate_string);

		if (found != string::npos)
			line.replace(0, line.length(), "");
		else
			temp << line << endl;
	}
	temp.close();
	fin.close();
	remove("REGISTER.TXT");
	rename("temp.txt", "REGISTER.TXT");
}

void car_reg_after(int car_pos, vehicle CARS[])
{
	int day, month, year, ok = 0;

	cout << "Day of registration: ";
	cin >> day;
	cout << "Month of registration: ";
	cin >> month;
	cout << "Year of registration: ";
	cin >> year;
	cout << "-------------------------------------------------------\n\n";
	cout << "       Registered cars after "<< day << " / " << month << " / " << year << endl;
	cout << "-------------------------------------------------------\n\n";

	for (int j = 0; j < car_pos; j++)
	{
		if (year <= CARS[j].getRegDate().getYear())
		{
			if (month <= CARS[j].getRegDate().getMonth())
			{
				if (day < CARS[j].getRegDate().getDay())
				{
					ok = 1;
					CARS[j].print_vehicle();
				}
			}
		}
	}
	if (ok == 0)
	{
		cout << "-------------------------------------------------------\n";
		cout << "              No cars after this date\n";
		cout << "-------------------------------------------------------\n\n";
	}
}

void car_check_before(int car_pos, vehicle CARS[]) {
	int day, month, year, ok = 0;

	cout << "Day of revision: ";
	cin >> day;
	cout << "Month of revision: ";
	cin >> month;
	cout << "Year of revision: ";
	cin >> year;
	cout << "-------------------------------------------------------\n\n";
	cout << "        Techincal revision before " << day << " / " << month << " / " << year << endl;
	cout << "-------------------------------------------------------\n\n";

	for (int j = 0; j < car_pos; j++)
	{
		if (year >= CARS[j].getRevDate().getYear())
		{
			if (month >= CARS[j].getRevDate().getMonth())
			{
				if (day > CARS[j].getRevDate().getDay())
				{
					ok = 1;
					CARS[j].print_vehicle();
				}
			}
		}
	}
	if (ok == 0)
	{
		cout << "-------------------------------------------------------\n";
		cout << "              No cars after this date\n";
		cout << "-------------------------------------------------------\n\n";
	}
}

void sort_type(int car_pos, vehicle CARS[])
{
	cout << "-------------------------------------------------------\n";
	cout << "               Car sorting by category\n";
	cout << "-------------------------------------------------------\n";
	
	std::sort(CARS, CARS + car_pos);
	for (int j = 0; j < car_pos; j++)
		CARS[j].print_vehicle();

	cout << "-------------------------------------------------------\n";
	cout << "               Car sorting ended\n";
	cout << "-------------------------------------------------------\n\n";
}

void help() {
	cout << "-------------------------------------------------------\n";
	cout << "               Guide for the program!\n";
	cout << "-------------------------------------------------------\n\n";
	cout << "This program is used for the registration of vehicles in Police accounts. ";
	cout << "For each car, diferent data is stored: \nOwener's name, age, job; \nCategory; \nBrand; \nEngine volume; \nEngine horse power; \nFuel type; \nColor; \nPlate serial; \nDate of registration; \nLast technical revision.\n";
	cout << "\nThe user can do the following: \n1. Register a car; \n2. Change car features; \n3. Search car by plate number; \n4. Search car by owner; \n5. Update the car maintenance date; \n6. Remove records; \n7. Display cars registered after a date; \n8. Show cars which latest revision is before a certain date; \n9. Sort cars by vehicle type; \n";
	cout << "-------------------------------------------------------\n";
	cout << "              Check out the guide above!\n";
	cout << "-------------------------------------------------------\n\n";
}

void menu(int car_pos, vehicle CARS[]) {
	int a;
	string owner, plate_number;
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~Menu select~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout << " [1] Register a car \n";
	cout << " [2] Change car features \n";
	cout << " [3] Search car by plate number \n";
	cout << " [4] Search car by owner \n";
	cout << " [5] Car maintenance date \n";
	cout << " [6] Remove records \n";
	cout << " [7] Display cars registered after a date \n";
	cout << " [8] Show cars whose latest revision is before a certain date \n";
	cout << " [9] Sort cars by vehicle type \n";
	cout << "[10] Help \n";
	cout << "[11] Exit \n";
	cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n" << endl << endl;
	cout << "Type in the corresponding number: ";
	cin >> a;
	switch (a)
	{
	case 1:
		cout << "Check plate:";
		cin >> plate_number;
		if (search_plate(plate_number, car_pos, CARS) == 1)
		{
			cout << "-------------------------------------------------------\n";
			cout << "    The vehicle above is already using this plate!\n";
			cout << "-------------------------------------------------------\n\n";
		}
		else {
			register_car();
		}
		menu(car_pos, CARS);
		break;
	case 2:
		cout << "Enter the plate number for the car: ";
		cin >> plate_number;
		change_feature(plate_number);
		cout << "-------------------------------------------------------\n";
		cout << "           The car was changed with success! \n";
		cout << "-------------------------------------------------------\n\n";
		menu(car_pos, CARS);
		break;
	case 3:
		cout << "Search car after plate:";
		cin >> plate_number;
		search_plate(plate_number, car_pos, CARS);
		menu(car_pos, CARS);
		break;
	case 4:
		cout << "Search car after owner:";
		cin >> owner;
		search_owner(owner, car_pos, CARS);
		menu(car_pos, CARS);
		break;
	case 5:
		cout << "Enter the plate number for the car: ";
		cin >> plate_number;
		maintenance_date(plate_number);
		cout << "-------------------------------------------------------\n";
		cout << "       The revision date was updated with succes! \n";
		cout << "-------------------------------------------------------\n\n";
		menu(car_pos, CARS);
		break;
	case 6:
		cout << "remove car by plate number:";
		cin >> plate_number;
		remove_records(plate_number);
		cout << "-------------------------------------------------------\n";
		cout << "          The car was removed with success!\n";
		cout << "-------------------------------------------------------\n\n";
		menu(car_pos, CARS);
		break;
	case 7:
		car_reg_after(car_pos, CARS);
		menu(car_pos, CARS);
		break;
	case 8:
		car_check_before(car_pos - 1, CARS);
		menu(car_pos, CARS);
		break;
	case 9:
		sort_type(car_pos - 1, CARS);
		menu(car_pos, CARS);
		break;
	case 10:
		help();
		menu(car_pos, CARS);
		break;
	case 11:
		exit(0);
	default:
		break;
	}
}

int main()
{
	HANDLE  hConsole;								//next 3 lines, surprise
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 992);

	login();

	fstream citire;
	citire.open("REGISTER.TXT");
	vehicle CARS[100];
	int car_pos = 0;

	while (!citire.eof())
	{
		CARS[car_pos] = CARS[car_pos].read_register(citire);
		car_pos++;
	}
	citire.close();

	menu(car_pos, CARS);

	return 0;
}