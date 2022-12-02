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
	//cout << ". bien so xe: " << Schedule::carID
	//	<< ", gio xuat phat: " << Schedule::departureTime << ", so luong ve da dat: "
	//	<< bookedSeats << '/' << capacity << ", gia tien: " << price << endl;
}

ostream& operator << (ostream& out, const AvailableCar& availableCar) {
	out << availableCar.order << ". bien so xe: " << availableCar.Schedule::carID
		<< ", gio xuat phat: " << availableCar.Schedule::departureTime << ", so luong ve da dat: " 
		<< availableCar.bookedSeats << '/' << availableCar.capacity << ", gia tien: " << availableCar.price << endl;
	return out;
}

string AvailableCar::getCarID() {
	return this->Schedule::carID;
}
int AvailableCar::getTime() {
	return this->Schedule::departureTime;
}