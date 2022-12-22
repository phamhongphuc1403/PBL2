#include "schedule_linked_list.h"
#include "schedule.h"
#include "available_car.h"
using namespace std;

ScheduleLinkedList::ScheduleLinkedList(string fileName) {
	ifstream input(fileName);
	string carID, departureDate, departureTime, bookedSeats;

	while (!input.eof()) {
		getline(input, carID, ',');
		input.seekg(1, ios::cur);
		getline(input, departureTime, ',');
		input.seekg(1, ios::cur);
		getline(input, departureDate, ',');
		input.seekg(1, ios::cur);
		getline(input, bookedSeats, '\n');

		Schedule *newNode = new Schedule(carID, stoi(departureTime), departureDate, stoi(bookedSeats));
		if (head == NULL) {
			head = newNode;
		}
		else {
			Schedule* tempNode = head;
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
		}
	}
	input.close();
}

void ScheduleLinkedList::addNode(AvailableCar availableCar, int bookingSeats) {
	Schedule* newNode = &availableCar; //upcast
	if (head == NULL) {
		head = newNode;
	} else {
		Schedule* tempNode = head;
		while (tempNode->next != NULL) {
			if (tempNode->carID == newNode->carID && tempNode->departureTime == newNode->departureTime &&
				tempNode->departureDate == newNode->departureDate) {
				tempNode->bookedSeats += bookingSeats;
				break;
			} else {
				tempNode = tempNode->next;
			}
		}
		if (tempNode->next == NULL) {
			if (tempNode->carID == newNode->carID && tempNode->departureTime == newNode->departureTime &&
				tempNode->departureDate == newNode->departureDate) {
				tempNode->bookedSeats += bookingSeats;
			}
			else {
				newNode->Schedule::bookedSeats = bookingSeats;
				tempNode->next = newNode;
			}
		}
	}
	writeFile("schedule.txt");
}

void ScheduleLinkedList::writeFile(string fileName) {
	fstream output;
	output.open(fileName, ios::out);
	Schedule* scheduleNode = head;
	while (scheduleNode->next != NULL) {
		output << scheduleNode->carID << ", " << scheduleNode->departureTime << ", " << scheduleNode->departureDate.toString()
			<< ", "  << scheduleNode->bookedSeats << endl;
		scheduleNode = scheduleNode->next;
	}
	output << scheduleNode->carID << ", " << scheduleNode->departureTime << ", " << scheduleNode->departureDate.toString()
		<< ", " << scheduleNode->bookedSeats;
	output.close();
}

//void ScheduleLinkedList::reschedule(Car carNode) {
//	Schedule* scheduleNode = head;
//	bool isChanged = true;
//	while (scheduleNode->next != NULL) {
//		isChanged = true;
//		if (scheduleNode->carID == carNode.carID) {
//			for (int i = 0; i < carNode.departureTimeCount; i++) {
//				if (scheduleNode->departureTime == carNode.departureTime[i]) {
//					isChanged = false;
//				}
//			}
//			if (isChanged) {
//				scheduleNode->bookedSeats = 0;
//			}
//		}
//		scheduleNode = scheduleNode->next;
//	}
//	writeFile("schedule.txt");
//}