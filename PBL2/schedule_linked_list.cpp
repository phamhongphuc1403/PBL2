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
		if (head == NULL) {
			head = new Schedule(carID, stoi(departureTime), departureDate, stoi(bookedSeats));
		}
		else {
			Schedule* tempNode = head;
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			tempNode->next = new Schedule(carID, stoi(departureTime), departureDate, stoi(bookedSeats));
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
			newNode->Schedule::bookedSeats = bookingSeats;
			tempNode->next = newNode;
		}
	}
	writeFile("schedule.txt");
}

void ScheduleLinkedList::writeFile(string fileName) {
	fstream output;
	output.open(fileName, ios::out);
	Schedule* scheduleNode = head;
	while (scheduleNode->next != NULL) {
		output << scheduleNode->carID << ", " << scheduleNode->departureTime << ", " << scheduleNode->departureDate 
			<< ", "  << scheduleNode->bookedSeats << endl;
		scheduleNode = scheduleNode->next;
	}
	output << scheduleNode->carID << ", " << scheduleNode->departureTime << ", " << scheduleNode->departureDate
		<< ", " << scheduleNode->bookedSeats;
	output.close();
}
