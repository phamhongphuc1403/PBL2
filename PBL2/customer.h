#pragma once

#ifndef CUSTOMER_H
#define CUSTOMER_H



#include "node.h"
using namespace std;
class CustomerLinkedList;

class Customer: public Node {
private:
	std::string fullName, phoneNumber, bookedSeats;
	std::string carID, destination, bookingDate;
	Customer* next;
public:
	Customer(std::string, std::string, std::string, std::string, std::string, std::string);
	Customer(const Customer&);
	friend class CustomerLinkedList;
	friend std::ostream& operator << (std::ostream& , const Customer&);
	friend std::ostream& operator << (std::ostream&, const CustomerLinkedList&);
	friend std::istream& operator >> (std::istream&, CustomerLinkedList&);
};
#endif