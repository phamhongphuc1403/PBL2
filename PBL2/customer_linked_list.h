#pragma once

#ifndef CUSTOMERLINKEDLIST_H
#define CUSTOMERLINKEDLIST_H

#include "customer.h"

class CustomerLinkedList {
private:
    Customer* head;
public:
    CustomerLinkedList(std::string);
    friend std::ostream& operator << (std::ostream&, const CustomerLinkedList&);
    friend std::istream& operator >> (std::istream&, CustomerLinkedList&);
    void writeFile(std::string);
};

#endif