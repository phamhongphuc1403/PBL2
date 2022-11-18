#pragma once

#ifndef AVAILABLECARS_H
#define AVAILABLECARS_H

#include "car.h"
#include "schedule.h"
#include "node.h"
class AvailableCars: public Car, Schedule {
public:
	AvailableCars(std::string, int, std::string, int);
};
#endif