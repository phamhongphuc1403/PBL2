#pragma once

#ifndef CAR_H
#define CAR_H



#include "node.h"
//class CustomerLinkedList;

class Car : public Node {
private:
	std::string carID, capacity, destination, price;
	int* departureTime;
	Car* next;
public:
	Car(std::string, std::string, std::string, std::string, int, int*);
	friend class CarLinkedList;
	friend std::ostream& operator << (std::ostream&, const Car&);
	friend std::ostream& operator << (std::ostream&, const CarLinkedList&);
};
#endif