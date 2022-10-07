#include <iostream>
#include <fstream>
#include "car.h"
using namespace std;

string filename = "carInfo.txt";

Car::Car(std::string, std::string, std::string, int, int, int)
{
	filename = "carInfo.txt";
	ifstream s;
	s.open(filename);
	this->type = type;
	this->driver = driver;
	this->licensePlate = licensePlate;
	this->driverID = driverID;
	this->seats = seats;
	this->bookedSeats = bookedSeats;
	s.close();
}

void Car::Set()
{
	filename = "carInfo.txt";
	ifstream s;
	s.open(filename);
	cin >> type;
	s >> type;
	s.close();
}

void Car::Show()
{
	filename = "carInfo.txt";
	ofstream s;
	s.open(filename);
	s << type;
	s.close();
	cout << type;
}