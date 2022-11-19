#include "schedule_linked_list.h"
#include "schedule.h"
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
			head = new Schedule(carID, departureTime, departureDate, bookedSeats);
		}
		else {
			Schedule* tempNode = head;
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			tempNode->next = new Schedule(carID, departureTime, departureDate, bookedSeats);
		}
	}
	input.close();
}