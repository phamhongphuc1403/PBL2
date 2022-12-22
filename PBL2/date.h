#pragma once

#ifndef DATE_H
#define DATE_H

#include <string>
class Date{
private:
    int day, month, year;
public:
    Date() {};
    Date(std::string);
    void setDate(std::string);
    void setCurrentDate();
    friend std::ostream& operator << (std::ostream&, const Date&);
    void operator = (std::string);
    bool operator == (const Date&);
    bool operator >= (const Date&);

    std::string toString();
    int getMonth();
    bool isValid();
};

#endif