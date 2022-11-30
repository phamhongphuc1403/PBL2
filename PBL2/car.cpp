#include "car.h"
using namespace std;

Car::Car(string carID, string capacity, string destination, string price, int departureTimeCount, int* departureTimeArray)
:carID(carID), capacity(stoi(capacity)), destination(destination), price(stoi(price)), departureTimeCount(departureTimeCount) {
	this->departureTime = new int[departureTimeCount];
	for (int i = 0; i < departureTimeCount; i++) {
		this->departureTime[i] = departureTimeArray[i];
	}
}

ostream& operator << (ostream& out, const Car& car) {
	out << "Bien so xe: " << car.carID << ", so cho ngoi: " << car.capacity << ", diem den: " << car.destination
		<< ", gia tien: " << car.price << ", Gio xuat phat trong ngay: ";

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
