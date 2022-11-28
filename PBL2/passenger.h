#pragma once

#ifndef PASSENGER_H
#define PASSENGER_H



#include "node.h"
using namespace std;
class PassengerLinkedList;

class Passenger: public Node {
private:
	std::string fullName, phoneNumber, carID, destination, departureDate;
	int bookedSeats, departureTime;
	long long totalPrice;
	Passenger* next;
public:
	Passenger(std::string, std::string, int, std::string, std::string, int, std::string, long long);
	Passenger(const Passenger&);
	friend class PassengerLinkedList;
	friend std::ostream& operator << (std::ostream& , const Passenger&);
	friend std::ostream& operator << (std::ostream&, const PassengerLinkedList&);
	friend std::istream& operator >> (std::istream&, PassengerLinkedList&);
};
#endif