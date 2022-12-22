#pragma once

#ifndef AVAILABLECARSLINKEDLIST_H
#define AVAILABLECARSLINKEDLIST_H

#include "available_car.h"

class AvailableCarsLinkedList {
private:
	int numOfCars;
	AvailableCar* head;
public:
	AvailableCarsLinkedList(std::string, std::string, int);
	friend std::ostream& operator << (std::ostream&, AvailableCarsLinkedList&);
	AvailableCar getNode(int);
	int getNumOfCars();
};
#endif