#pragma once

#ifndef CUSTOMERLINKEDLIST_H
#define CUSTOMERLINKEDLIST_H

#include "customer.h"
#include <string>

class CustomerLinkedList {
private:
    Customer* head;
public:
    CustomerLinkedList(std::string);
    friend std::ostream& operator << (std::ostream&, const CustomerLinkedList&);
    friend std::istream& operator >> (std::istream&, CustomerLinkedList&);
    void writeFile(std::string);
    /*
    void addTail(double n) {
        Node* node = new Node(n);
        if (head == NULL) {
            head = node;
        }
        else {
            tail->next = node;
        }
        tail = node;
    };*/
};

#endif