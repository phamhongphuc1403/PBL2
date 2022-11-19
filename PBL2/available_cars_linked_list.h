#pragma once

#ifndef AVAILABLECARSLINKEDLIST_H
#define AVAILABLECARSLINKEDLIST_H

#include "available_cars.h"

class AvailableCarsLinkedList {
	AvailableCars* head;
public:
	AvailableCarsLinkedList(int, std::string, int, std::string, int);
};
#endif