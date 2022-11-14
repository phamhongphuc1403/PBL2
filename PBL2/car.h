#pragma once

#ifndef CAR_H
#define CAR_H



#include "node.h"
using namespace std;
//class CustomerLinkedList;

class Car : public Node {
private:
	std::string carID, capacity, destination, price;
	std::string* departureTime;
	Car* next;
public:
	
};
#endif