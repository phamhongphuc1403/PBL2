#include "customer.h"

using namespace std;

Customer::Customer(std::string fullName, std::string phoneNumber, std::string bookedSeats, std::string destination, std::string carID, std::string bookingDate)
	:fullName(fullName), phoneNumber(phoneNumber), bookedSeats(stoi(bookedSeats)), destination(destination), carID(carID), bookingDate(bookingDate) {
	this->next = NULL;
};
Customer::Customer(const Customer& customer) {
	fullName = customer.fullName;
	phoneNumber = customer.phoneNumber;
	bookedSeats = customer.bookedSeats;
	destination = customer.destination;
	carID = customer.carID;
	bookingDate = customer.bookingDate;
	this->next = customer.next;
}
ostream& operator << (ostream& out, const Customer& customer) {
	out << customer.fullName << ", " << customer.phoneNumber << ", " << customer.bookedSeats 
	<< ", " << customer.destination << ", " << customer.carID << ", " << customer.bookingDate << endl;
	return out;
}
