#pragma once

#ifndef PASSENGERLINKEDLIST_H
#define PASSENGERLINKEDLIST_H

#include "passenger.h"

class PassengerLinkedList {
private:
    Passenger* head;
public:
    PassengerLinkedList(std::string);
    friend std::ostream& operator << (std::ostream&, const PassengerLinkedList&);
    friend std::istream& operator >> (std::istream&, PassengerLinkedList&);
    void writeFile(std::string);
    void findPassenger(std::string);
};

#endif