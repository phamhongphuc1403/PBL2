#include "schedule_linked_list.h"
#include "schedule.h"
using namespace std;

ScheduleLinkedList::ScheduleLinkedList(string fileName) {
	ifstream input(fileName);
	string carID, departmentDate, departmentTime, bookedSeats;

	while (!input.eof()) {
		getline(input, carID, ',');
		input.seekg(1, ios::cur);
		getline(input, departmentTime, ',');
		input.seekg(1, ios::cur);
		getline(input, departmentDate, ',');
		input.seekg(1, ios::cur);
		getline(input, bookedSeats, '\n');

		if (head == NULL) {
			head = new Schedule(carID, departmentTime, departmentDate, bookedSeats);
		}
		else {
			Schedule* tempNode = head;
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			tempNode->next = new Schedule(carID, departmentTime, departmentDate, bookedSeats);
		}
	}
	input.close();
}