#include "car.h"
using namespace std;

Car::Car(string carID, string capacity, string destination, string price, int departureTimeCount, int* departureTimeArray)
:carID(carID), capacity(stoi(capacity)), destination(destination), price(stoi(price)), departureTimeCount(departureTimeCount) {
	this->departureTime = new int[departureTimeCount];
	for (int i = 0; i < departureTimeCount; i++) {
		this->departureTime[i] = departureTimeArray[i];
	}
	this->next = NULL;
}

ostream& operator << (ostream& out, const Car& car) {
	out << setiosflags(ios::left) << setw(15) << car.carID << setiosflags(ios::left) << setw(15) << car.capacity << setiosflags(ios::left) << setw(15) << car.destination
		<< setiosflags(ios::left) << setw(15) << car.price;

	for (int i = 0; i < car.departureTimeCount - 1; i++) {
		out << car.departureTime[i] << "h, ";
	}
	out << car.departureTime[car.departureTimeCount - 1] << "h" << endl;
	return out;
}

void Car::setDestination(string destination){
	this->destination = destination;
}

void Car::setPrice(long long price) {
	this->price = price;
}

void Car::setDepartureTime(int departureTimeCount, int *departureTimeArray) {
	this->departureTimeCount = departureTimeCount;
	delete[] this->departureTime;
	this->departureTime = new int[departureTimeCount];
	for (int i = 0; i < departureTimeCount; i++) {
		this->departureTime[i] = departureTimeArray[i];
	}
}
