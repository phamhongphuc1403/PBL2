#pragma once

#ifndef DATE_H
#define DATE_H

#include <string>
class Date{
private:
    int day, month, year;
public:
    Date(std::string);
    Date() {};
    void getCurrentDate();
};

#endif