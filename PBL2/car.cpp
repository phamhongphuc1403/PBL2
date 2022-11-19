#include "car.h"
#include<array> 
using namespace std;

Car::Car(string carID, string capacity, string destination, string price, int departureTimeCount, int* departureTimeArray)
:carID(carID), capacity(stoi(capacity)), destination(destination), price(stoi(price)), departureTimeCount(departureTimeCount) {
	this->departureTime = new int[departureTimeCount];
	
	for (int i = 0; i < departureTimeCount; i++) {
		this->departureTime[i] = departureTimeArray[i];
	}
}

ostream& operator << (ostream& out, const Car& car) {
	out << car.carID << ", " << car.capacity << ", " << car.destination
		<< ", " << car.price << ", ";

	for (int i = 0; i < car.departureTimeCount - 1; i++) {
		out << car.departureTime[i] << ", ";
	}
	out << car.departureTime[car.departureTimeCount - 1] << endl;
	return out;
}


