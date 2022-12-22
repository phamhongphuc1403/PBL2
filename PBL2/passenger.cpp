#include "passenger.h"

using namespace std;

Passenger::Passenger(string fullName, string phoneNumber, string bookingDate, int bookedSeats, string destination, string carID, int departureTime, string departureDate, long long totalPrice)
	:fullName(fullName), phoneNumber(phoneNumber), bookedSeats(bookedSeats), destination(destination),
	carID(carID), departureTime(departureTime), totalPrice(totalPrice) {
	this->departureDate = departureDate;
	if (bookingDate == "") {
		this->bookingDate.setCurrentDate();
	}
	else {
		this->bookingDate = bookingDate;
	}
	this->next = NULL;
};
Passenger::Passenger(const Passenger& customer) {
	fullName = customer.fullName;
	phoneNumber = customer.phoneNumber;
	bookingDate = customer.bookingDate;
	bookedSeats = customer.bookedSeats;
	destination = customer.destination;
	carID = customer.carID;
	departureTime = customer.departureTime;
	departureDate = customer.departureDate;
	totalPrice = customer.totalPrice;
	this->next = customer.next;
}
ostream& operator << (ostream& out, Passenger& customer) {
	out << setiosflags(ios::left) << setw(25) << customer.fullName << setiosflags(ios::left) << setw(20) << customer.phoneNumber << setiosflags(ios::left) << setw(20) << customer.bookingDate.toString() << setiosflags(ios::left) << setw(10) << customer.bookedSeats
		<< setiosflags(ios::left) << setw(15) << customer.destination << setiosflags(ios::left) << setw(20) << customer.carID << setiosflags(ios::left) << setw(20) << customer.departureDate.toString()
		<< setiosflags(ios::left) << setw(10) << customer.departureTime << setiosflags(ios::left) << customer.totalPrice << endl;
	return out;
}
