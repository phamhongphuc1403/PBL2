#pragma once

#ifndef AVAILABLECARS_H
#define AVAILABLECARS_H

#include "car.h"
#include "schedule.h"
#include "node.h"

class AvailableCarsLinkedList;

class AvailableCar: public Car, public Schedule {
private:
	int order;
	std::string departureDate;
	AvailableCar* next;
public:
	AvailableCar(std::string, int, std::string, int, int);
	friend class AvailableCarsLinkedList;
	friend std::ostream& operator << (std::ostream&, const AvailableCarsLinkedList&);
	friend std::ostream& operator << (std::ostream&, const AvailableCar&);
};
#endif