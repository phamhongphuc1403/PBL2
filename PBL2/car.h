#pragma once

#ifndef CAR_H
#define CAR_H



#include "node.h"
class CarLinkedList;

class Car : public Node {
protected:
	std::string carID, destination;
	int* departureTime, departureTimeCount, capacity, price;
	Car* next;
public:
	Car(std::string, std::string, std::string, std::string, int, int*);
	friend class CarLinkedList;
	friend std::ostream& operator << (std::ostream&, const Car&);
	friend std::ostream& operator << (std::ostream&, const CarLinkedList&);
	void printCar(int, int, std::string, int);
};
#endif