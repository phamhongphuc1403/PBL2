#include "available_cars_linked_list.h"
#include "schedule_linked_list.h"
#include "car_linked_list.h"

using namespace std;

AvailableCarsLinkedList::AvailableCarsLinkedList(string destination, string departureDate, int bookingSeats) {
	ScheduleLinkedList scheduleList("schedule.txt");
	Schedule* scheduleNode = scheduleList.head;
	CarLinkedList carList("car.txt");
	Car* carNode = carList.head;
	int order = 0, bookedSeats = 0;
	bool isFull = false;

	while (carNode != NULL) {
		if (carNode->destination == destination) {
			for (int i = 0; i < carNode->departureTimeCount; i++) {
				isFull = false;
				bookedSeats = 0;
				while (scheduleNode != NULL) {
					if (scheduleNode->carID == carNode->carID &&
						scheduleNode->departureTime == carNode->departureTime[i] &&
						scheduleNode->departureDate == departureDate) {
						bookedSeats = scheduleNode->bookedSeats;

						if (scheduleNode->bookedSeats + bookingSeats > carNode->capacity) {
							isFull = true;
							break;
						}
					}
					scheduleNode = scheduleNode->next;
				}
				if (!isFull) {
					AvailableCar *newNode = new AvailableCar(carNode->carID, carNode->departureTime[i], departureDate, bookedSeats, carNode->capacity , carNode->price);
					if (head == NULL) {
						head = newNode;
					} else {
						if (head->Schedule::departureTime > newNode->Schedule::departureTime) {
							newNode->next = head;
							head = newNode;
						} else {
							AvailableCar* tempNode = head;
							while (tempNode != NULL) {
								if (tempNode->next == NULL) {
									tempNode->next = newNode;
									break;
								} else if (tempNode->next->Schedule::departureTime > newNode->Schedule::departureTime) {
									newNode->next = tempNode->next;
									tempNode->next = newNode;
									break;
								} else {
									tempNode = tempNode->next;
								}
							}
						}
					}
				}
				scheduleNode = scheduleList.head;
			}
		}
		carNode = carNode->next;
	}
}

ostream& operator << (ostream& out, const AvailableCarsLinkedList& availableCarsLinkedList) {
	int order = 0;
	AvailableCar *carNode = availableCarsLinkedList.head;
	while (carNode != NULL) {
		carNode->order = ++order;
		out << *carNode;
		carNode = carNode->next;
	}
	return out;
}

AvailableCar AvailableCarsLinkedList::getNode(int choice) {
	AvailableCar *tempNode = head;
	while (tempNode->order != choice && tempNode != NULL) {
		tempNode = tempNode->next;
	}
	return *tempNode;
}