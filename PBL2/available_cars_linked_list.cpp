#include "available_cars_linked_list.h"
#include "schedule_linked_list.h"
#include "car_linked_list.h"

using namespace std;

AvailableCarsLinkedList::AvailableCarsLinkedList(string destination, string departureDate) {
	ScheduleLinkedList scheduleList("schedule.txt");
	Schedule* scheduleNode = scheduleList.head;
	CarLinkedList carList("car.txt");
	Car* carNode = carList.head;
	int order = 0, capacity = 0;
	bool isFull = false;

	while (carNode != NULL) {
		if (carNode->destination == destination) {
			for (int i = 0; i < carNode->departureTimeCount; i++) {
				isFull = false;
				capacity = 0;
				while (scheduleNode != NULL) {
					if (scheduleNode->carID == carNode->carID &&
						scheduleNode->departureTime == carNode->departureTime[i] &&
						scheduleNode->departureDate == departureDate) {
						capacity = scheduleNode->bookedSeats;
						if (scheduleNode->bookedSeats >= carNode->capacity) {
							//cout << "cho ngoi " << scheduleNode->bookedSeats << endl;
							isFull = true;
							break;
						}
					}
					scheduleNode = scheduleNode->next;
				}
				if (!isFull) {
					if (head == NULL) {
						head = new AvailableCar(++order, carNode->carID, carNode->departureTime[i], departureDate, capacity);
					}
					else {
						AvailableCar* tempNode = head;
						while (tempNode->next != NULL) {
							tempNode = tempNode->next;
						}
						tempNode->next = new AvailableCar(++order, carNode->carID, carNode->departureTime[i], departureDate, capacity);
					}
				}
				scheduleNode = scheduleList.head;
			}
		}
		carNode = carNode->next;
	}
}

ostream& operator << (ostream& out, const AvailableCarsLinkedList& availableCarsLinkedList) {
	AvailableCar *carNode = availableCarsLinkedList.head;
	while (carNode != NULL) {
		out << *carNode;
		carNode = carNode->next;
	}
	return out;
}