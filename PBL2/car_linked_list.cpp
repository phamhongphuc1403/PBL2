#include "car_linked_list.h"
#include "car.h"

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

		cout << carID << ", " << capacity << ", " << destination
			<< ", " << price << ", " << temp << endl;

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
		//for (int i = 0; i < departureTimeCount; i++) {
		//	cout << departureTimeArray[i] << ' ';
		//}
		// 
		//if (head == NULL) {
		//	head = new Car(carID, capacity, destination, price, carID, departureTimeCount, departureTimeArray);
		//}
		//else {
		//	Customer* tempNode = head;
		//	while (tempNode->next != NULL) {
		//		tempNode = tempNode->next;
		//	}
		//	tempNode->next = new Customer(fullName, phoneNumber, bookedSeats, destination, carID, date);
		//}
	}
	input.close();
}
