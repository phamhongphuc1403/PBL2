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
	AvailableCar* next;
public:
	AvailableCar(std::string, int, std::string, int, int, long long);
	friend class AvailableCarsLinkedList;
	friend class ScheduleLinkedList;
	friend std::ostream& operator << (std::ostream&, const AvailableCarsLinkedList&);
	friend std::ostream& operator << (std::ostream&, const AvailableCar&);
	std::string getCarID();
	int getTime();

};
#endif