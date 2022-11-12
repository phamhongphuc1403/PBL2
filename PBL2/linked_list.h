#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "node.h"
#include <string>
//#include <iostream>

class LinkedList {
protected:
    Node* head;
public:
    LinkedList(std::string);
    /*LinkedList(int size, double arr[]) {
        if (size > 0) {
            head = new Node(arr[0]);
            if (size <= 1) {
                tail = NULL;
            }
            else {
                tail = new Node(arr[size - 1]);
            }
            Node* tempNode = head;
            for (int i = 1; i < size - 1; i++) {
                Node* newNode = new Node(arr[i]);
                tempNode->next = newNode;
                tempNode = tempNode->next;
            }
            tempNode->next = tail;
        }
        else {
            head = NULL;
            tail = NULL;
        }

    }
    LinkedList(const LinkedList& linkedList) {
        head = new Node(linkedList.head->n);
        tail = new Node(linkedList.tail->n);

        Node* tempNode1 = head;
        Node* tempNode2 = linkedList.head;
        while (tempNode2->next != NULL) {
            Node* newNode = new Node(tempNode2->next->n);
            tempNode1->next = newNode;
            tempNode1 = tempNode1->next;
            tempNode2 = tempNode2->next;
        }
    }
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
    void out() {
        if (head != NULL) {
            Node* node = head;
            while (node != NULL)
            {
                cout << node->n << ' ';
                node = node->next;
            }
        }
    }
    friend void operator << (ostream&, const Set&);*/
};

#endif