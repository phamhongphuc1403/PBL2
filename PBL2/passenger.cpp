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
	out << "Ten: " << customer.fullName << ", so dien thoai: " << customer.phoneNumber << ", so ghe da dat: " << customer.bookedSeats
	<< ", diem den: " << customer.destination << ", bien so xe: " << customer.carID << ", ngay xuat phat: " << customer.departureDate 
	<< ", gio: " << customer.departureTime << ", gia tien: " << customer.totalPrice << endl;
	return out;
}
