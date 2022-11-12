#pragma once

#ifndef DATE_H
#define DATE_H

#include <iostream>

class Date {
private:
	int day, month, year;
public:
	friend std::istream operator >> (std::istream&, Date& date);
};
#endif