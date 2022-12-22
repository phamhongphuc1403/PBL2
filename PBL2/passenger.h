#pragma once

#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "date.h"
class PassengerLinkedList;

class Passenger {
private:
	std::string fullName, phoneNumber, carID, destination;
	Date departureDate, bookingDate;
	int bookedSeats, departureTime;
	long long totalPrice;
	Passenger* next;
public:
	Passenger(std::string, std::string, std::string, int, std::string, std::string, int, std::string, long long);
	Passenger(const Passenger&);
	friend class PassengerLinkedList;
	friend std::ostream& operator << (std::ostream& , Passenger&);
	friend std::ostream& operator << (std::ostream&, const PassengerLinkedList&);
	friend std::istream& operator >> (std::istream&, PassengerLinkedList&);
};
#endif