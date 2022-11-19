#pragma once

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "node.h"

class Schedule {
protected:
	std::string carID, departureDate;
	int departureTime, bookedSeats;
	Schedule* next;
public:
	friend class ScheduleLinkedList;
	friend class AvailableCarsLinkedList;

	Schedule(std::string, std::string, std::string, std::string);
	Schedule() {};
};
#endif