#include "customer.h"

using namespace std;

Customer::Customer(std::string fullName, std::string phoneNumber, int bookedSeats, std::string destination, std::string carID, std::string departureDate, long long totalPrice)
	:fullName(fullName), phoneNumber(phoneNumber), bookedSeats(bookedSeats), destination(destination), 
	carID(carID), departureDate(departureDate), totalPrice(totalPrice) {
	this->next = NULL;
};
Customer::Customer(const Customer& customer) {
	fullName = customer.fullName;
	phoneNumber = customer.phoneNumber;
	bookedSeats = customer.bookedSeats;
	destination = customer.destination;
	carID = customer.carID;
	departureDate = customer.departureDate;
	totalPrice = customer.totalPrice;
	this->next = customer.next;
}
ostream& operator << (ostream& out, const Customer& customer) {
	out << "Ten: " << customer.fullName << ", so dien thoai: " << customer.phoneNumber << ", so ghe da dat: " << customer.bookedSeats
	<< ", diem den: " << customer.destination << ", bien so xe: " << customer.carID << ", ngay xuat phat: " << customer.departureDate 
	<< ", gia tien: " << customer.totalPrice << endl;
	return out;
}
