#include "available_car.h"

using namespace std;

AvailableCar::AvailableCar(int order, string carID, int departureTime, string departureDate, int capacity):Car(), Schedule() {
	this->order = order;
	this->Car::carID = carID;
	this->Schedule::departureTime = departureTime;
	this->departureDate = departureDate;
	this->capacity = capacity;
	this->next = NULL;
}

ostream& operator << (ostream& out, const AvailableCar& availableCar) {
	out << "stt: " << availableCar.order << ", bien so xe: " << availableCar.Car::carID 
		<< ", gio xuat phat: " << availableCar.Schedule::departureTime << ", so luong ve dat : " 
		<< availableCar.bookedSeats << '/' << availableCar.capacity << endl;
	return out;
}