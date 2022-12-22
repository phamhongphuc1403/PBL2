#pragma once

#ifndef CARLINKEDLIST_H
#define CARLINKEDLIST_H

#include "car.h"
#include <string>
class PassengerLinkedList;
class CarLinkedList {
private:
    Car* head;
public:
    CarLinkedList(std::string);
    friend std::ostream& operator << (std::ostream&, const CarLinkedList&);
    friend std::istream & operator >> (std::istream&, PassengerLinkedList&);
    void printAvailableCars(std::string, std::string);
    friend class AvailableCarsLinkedList;
    //friend std::istream& operator >> (std::istream&, PassengerLinkedList&);
    void writeFile(std::string);
    long long getPrice(std::string);
    bool findCar(std::string);
    void editCar(std::string);
    void printIncome(int);
};

#endif