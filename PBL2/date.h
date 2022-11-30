#pragma once

#ifndef DATE_H
#define DATE_H

#include <string>
class Date{
private:
    int day, month, year;
public:
    void setDate(std::string);
    void getCurrentDate();
    friend std::ostream& operator << (std::ostream&, const Date&);
};

#endif