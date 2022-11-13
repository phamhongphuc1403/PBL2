#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "customer.h"
#include <string>

class CustomerLinkedList {
private:
    Customer* head;
public:
    CustomerLinkedList(std::string);
    friend std::ostream& operator << (std::ostream&, const CustomerLinkedList&);
    friend std::istream& operator >> (std::istream&, CustomerLinkedList&);
    void writeFile();
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
    }

    friend void operator << (ostream&, const Set&);*/
};

#endif