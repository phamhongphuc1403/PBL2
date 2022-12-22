#pragma once

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include "date.h"

class Schedule {
protected:
	std::string carID;
	Date departureDate;
	int departureTime, bookedSeats;
	Schedule* next;
public:
	friend class ScheduleLinkedList;
	friend class AvailableCarsLinkedList;
	friend class CarLinkedList;
	Schedule(std::string, int, std::string, int);
	Schedule() {};
};
#endif