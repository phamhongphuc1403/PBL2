#include "car_linked_list.h"
#include "car.h"
#include "schedule_linked_list.h"

using namespace std;

CarLinkedList::CarLinkedList(string fileName) {
	ifstream input(fileName);
	string carID, capacity, destination, price, temp;
	int departureTimeArray[5];
	
	while (!input.eof()) {
		int departureTimeCount = 0;
		getline(input, carID, ',');
		input.seekg(1, ios::cur);
		getline(input, capacity, ',');
		input.seekg(1, ios::cur);
		getline(input, destination, ',');
		input.seekg(1, ios::cur);
		getline(input, price, ',');
		input.seekg(1, ios::cur);
		getline(input, temp, '\n');

		int departureTime = 0;
		for (int i = 0; i <= temp.length(); i++) {
			if (temp[i] - '0' >= 0) {
				departureTime = departureTime * 10 + (temp[i] - '0');
			} else {
				if (departureTime > 0) {
					departureTimeArray[departureTimeCount++] = departureTime;
				}
				departureTime = 0;
			}
		} 
		if (head == NULL) {
			head = new Car(carID, capacity, destination, price, departureTimeCount, departureTimeArray);
		}
		else {
			Car* tempNode = head;
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			tempNode->next = new Car(carID, capacity, destination, price, departureTimeCount, departureTimeArray);
		}
	}
	input.close();
}

ostream& operator << (ostream& out, const CarLinkedList& carLinkedList) {
	if (carLinkedList.head != NULL) {
		Car* car = carLinkedList.head;
		while (car != NULL) {
			out << *car;
			car = car->next;
		}
	}
	return out;
}

void CarLinkedList::printAvailableCars(string destination, string bookingDate) {
	ScheduleLinkedList scheduleList("schedule.txt");
	Car* carNode = head;
	Schedule* scheduleNode = scheduleList.head;
	int order = 0, capacity = 0;
	bool isFull = false;

	while (carNode != NULL) {
		if (carNode->destination == destination) {
			for (int i = 0; i < carNode->departureTimeCount; i++) {
				isFull = false;
				capacity = 0;
				while (scheduleNode != NULL) {
					if (scheduleNode->carID == carNode->carID &&
						scheduleNode->departmentTime == carNode->departureTime[i] &&
						scheduleNode->departmentDate == bookingDate) {
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
					carNode->printCar(++order, carNode->departureTime[i],
						bookingDate,
						capacity);
				}
				scheduleNode = scheduleList.head;
			}
		}
		carNode = carNode->next;
	}
}