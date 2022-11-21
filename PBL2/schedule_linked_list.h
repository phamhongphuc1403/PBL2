	#pragma once
#ifndef SCHEDULE_LINKED_LIST_H
#define SCHEDULE_LINKED_LIST_H
#include "schedule.h"

class CustomerLinkedList;
class AvailableCar;
class ScheduleLinkedList {
private:
	Schedule* head;
public:
	ScheduleLinkedList(std::string);
	friend std::istream& operator >> (std::istream&, CustomerLinkedList&);
	friend class AvailableCarsLinkedList;
	void addNode(AvailableCar, int);
	void writeFile(std::string);
};
#endif