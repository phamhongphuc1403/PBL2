#pragma once

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include "info.h"

class Node {
private:
    Info info;
    Node* next;

public:
    Node(Info info) {
        this->info = info;
        next = NULL;
    };
    //Node(const Node& node) {
    //    n = node.n;
    //    next = NULL;
    //}
    friend class LinkedList;
    //fr/*iend class set;
    //fri*/end void operator << (std::ostream&, const Set&);

};

#endif