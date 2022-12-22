#include "available_car.h"

using namespace std;

AvailableCar::AvailableCar(string carID, int departureTime, string departureDate, int bookedSeats, int capacity, long long price) {
	this->Schedule::carID = carID;
	this->Schedule::departureTime = departureTime;
	this->Schedule::departureDate = departureDate;
	this->bookedSeats = bookedSeats;
	this->capacity = capacity;
	this->price = price;
	this->next = NULL;
}

ostream& operator << (ostream& out, const AvailableCar& availableCar) {
	out << setiosflags(ios::left) << setw(10) << availableCar.order << setiosflags(ios::left) << setw(15) << availableCar.Schedule::carID
		<< setiosflags(ios::left) << setw(20) << availableCar.Schedule::departureTime << setiosflags(ios::left) << setw(2) << availableCar.bookedSeats << '/' << setiosflags(ios::left) << setw(20) << availableCar.capacity << availableCar.price << endl;
	return out;
}

string AvailableCar::getCarID() {
	return this->Schedule::carID;
}
int AvailableCar::getTime() {
	return this->Schedule::departureTime;
}