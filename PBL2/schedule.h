#pragma once

#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "node.h"

class Schedule {
private:
	std::string carID, departmentDate;
	int departmentTime, bookedSeats;
	Schedule* next;
public:
	friend class ScheduleLinkedList;
	Schedule(std::string, std::string, std::string, std::string);
};
#endif