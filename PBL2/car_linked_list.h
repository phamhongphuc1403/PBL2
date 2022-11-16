#pragma once

#ifndef CARLINKEDLIST_H
#define CARLINKEDLIST_H

#include "car.h"
#include <string>

class CarLinkedList {
private:
    Car* head;
public:
    CarLinkedList(std::string);
    friend ostream& operator << (ostream&, const CarLinkedList&);
    //friend std::istream& operator >> (std::istream&, CustomerLinkedList&);
    //void writeFile(std::string);
};

#endif