#pragma once

#ifndef CUSTOMNER_H
#define CUSTOMER_H

#include "info.h"
#include "date.h"

class Customer : public Info {
private:
	int numberOfTickets;
	Date bookingDate;
	std::string bookingCarID, destination;
public:
	virtual void readFile(std::ifstream&);
	virtual void writeFile(std::ofstream&);
	virtual void printFile();
	virtual void get();
};
#endif