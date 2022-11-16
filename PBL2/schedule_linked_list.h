#pragma once
#ifndef SCHEDULE_LINKED_LIST_H
#define SCHEDULE_LINKED_LIST_H
#include "schedule.h"

class ScheduleLinkedList {
private:
	Schedule* head;
public:
	ScheduleLinkedList(std::string);
	friend std::istream& operator >> (std::istream&, CustomerLinkedList&);
};
#endif