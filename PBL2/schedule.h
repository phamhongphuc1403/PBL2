#pragma once

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "node.h"

class Schedule {
protected:
	std::string carID, departmentDate;
	int departmentTime, bookedSeats;
	Schedule* next;
public:
	friend class ScheduleLinkedList;
	friend class CarLinkedList;
	Schedule(std::string, std::string, std::string, std::string);
	Schedule();
};
#endif