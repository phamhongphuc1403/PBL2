#include "car.h"

using namespace std;

Car::Car(string carID, string capacity, string destination, string price, int departureTimeCount, int* departureTimeArray)
:carID(carID), capacity(capacity), destination(destination), price(price) {
	this->departureTime = new int[departureTimeCount];
	for (int i = 0; i < departureTimeCount; i++) {
		this->departureTime[i] = departureTimeArray[i];
	}
	cout << endl;
}

