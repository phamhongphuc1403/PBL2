	#pragma once
#ifndef SCHEDULE_LINKED_LIST_H
#define SCHEDULE_LINKED_LIST_H
#include "schedule.h"

class PassengerLinkedList;
class AvailableCar;
class Car;

class ScheduleLinkedList {
private:
	Schedule* head;
public:
	ScheduleLinkedList(std::string);
	friend std::istream& operator >> (std::istream&, PassengerLinkedList&);
	friend class AvailableCarsLinkedList;
	void addNode(AvailableCar, int);
	void writeFile(std::string);
	//void reschedule(Car);
};
#endif