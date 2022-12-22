#pragma once

#ifndef CAR_H
#define CAR_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

class CarLinkedList;

class Car {
protected:
	std::string carID, destination;
	int* departureTime;
	int departureTimeCount, capacity;
	long long price;
	Car* next;
public:
	Car(std::string, std::string, std::string, std::string, int, int*);
	Car() {};
	friend class CarLinkedList;
	friend class AvailableCarsLinkedList;
	friend std::ostream& operator << (std::ostream&, const Car&);
	friend std::ostream& operator << (std::ostream&, const CarLinkedList&);
	void setDestination(std::string);
	void setPrice(long long);
	void setDepartureTime(int, int*);
};
#endif