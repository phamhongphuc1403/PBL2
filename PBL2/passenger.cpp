#include "passenger.h"

using namespace std;

Passenger::Passenger(string fullName, string phoneNumber, int bookedSeats, string destination, string carID, int departureTime, string departureDate, long long totalPrice)
	:fullName(fullName), phoneNumber(phoneNumber), bookedSeats(bookedSeats), destination(destination),
	carID(carID), departureTime(departureTime), departureDate(departureDate), totalPrice(totalPrice) {
	this->next = NULL;
};
Passenger::Passenger(const Passenger& customer) {
	fullName = customer.fullName;
	phoneNumber = customer.phoneNumber;
	bookedSeats = customer.bookedSeats;
	destination = customer.destination;
	carID = customer.carID;
	departureTime = customer.departureTime;
	departureDate = customer.departureDate;
	totalPrice = customer.totalPrice;
	this->next = customer.next;
}
ostream& operator << (ostream& out, const Passenger& customer) {
	out << setiosflags(ios::left) << setw(15) << customer.fullName << setiosflags(ios::left) << setw(15) << customer.phoneNumber << setiosflags(ios::left) << setw(10) << customer.bookedSeats
		<< setiosflags(ios::left) << setw(15) << customer.destination << setiosflags(ios::left) << setw(10) << customer.carID << setiosflags(ios::left) << setw(15) << customer.departureDate
		<< setiosflags(ios::left) << setw(5) << customer.departureTime << setiosflags(ios::left) << setw(13) << customer.totalPrice << endl;
	return out;
}
