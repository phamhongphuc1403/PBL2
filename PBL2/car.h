#pragma once

#ifndef CAR_H
#define CAR_H



#include "node.h"
class CarLinkedList;

class Car : public Node {
protected:
	std::string carID, destination;
	int* departureTime;
	int departureTimeCount, capacity;
	long long price;
	Car* next;
public:
	Car(std::string, std::string, std::string, std::string, int, int*);
	Car() {};
	void getPrice(std::string);
	friend class CarLinkedList;
	friend class AvailableCarsLinkedList;

	friend std::ostream& operator << (std::ostream&, const Car&);
	friend std::ostream& operator << (std::ostream&, const CarLinkedList&);
};
#endif