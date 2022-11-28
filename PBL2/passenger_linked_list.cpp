#include "passenger_linked_list.h"
#include "passenger.h"
#include "car_linked_list.h"
#include "car.h"
#include "schedule_linked_list.h"
#include "schedule.h"
#include "available_cars_linked_list.h"

using namespace std;

PassengerLinkedList::PassengerLinkedList(string fileName) {
	ifstream input(fileName);
	string fullName, destination, carID, phoneNumber, date, bookedSeats, totalPrice, time;
	while (!input.eof()) {
		getline(input, fullName, ',');
		input.seekg(1, ios::cur);
		getline(input, phoneNumber, ',');
		input.seekg(1, ios::cur);
		getline(input, bookedSeats, ',');
		input.seekg(1, ios::cur);
		getline(input, destination, ',');
		input.seekg(1, ios::cur);
		getline(input, carID, ',');
		input.seekg(1, ios::cur);
		getline(input, time, ',');
		input.seekg(1, ios::cur);
		getline(input, date, ',');
		input.seekg(1, ios::cur);
		getline(input, totalPrice, '\n');
		//cout << fullName << phoneNumber << bookedSeats << destination << carID << date << endl;
		Passenger *newNode = new Passenger(fullName, phoneNumber, stoi(bookedSeats), destination, carID, stoi(time), date, stoll(totalPrice));
		if (head == NULL) {
			head = newNode;
		} else {
			Passenger* tempNode = head;
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
		}
	}
}

ostream& operator << (ostream& out, const PassengerLinkedList& passengerLinkedList) {
	if (passengerLinkedList.head != NULL) {
        Passenger *passenger = passengerLinkedList.head;
        while (passenger != NULL) {
            out << *passenger;
            passenger = passenger->next;
        }
    }
	return out;
}

istream& operator >> (istream& in, PassengerLinkedList& passengerLinkedList) {
	ScheduleLinkedList scheduleLinkedList("schedule.txt");
	CarLinkedList carLinkedList("car.txt");

	string fullName, phoneNumber;
	string destination, departureDate;
	int choice, bookingSeats;

	cout << "Nhap thong tin khach hang moi." << endl;
	cout << "Nhap diem den: ";
	getline(in, destination);
	cout << "Nhap ngay khoi hanh: "; in >> departureDate;
	cout << "Nhap so luong ve muon mua: "; in >> bookingSeats;

	AvailableCarsLinkedList availableCarsLinkedList(destination, departureDate, bookingSeats);
	cout << availableCarsLinkedList;

	cout << "nhap so thu tu xe muon chon: "; in >> choice;
	AvailableCar selectedCar = availableCarsLinkedList.getNode(choice);

	cout << "xe da chon: "; cout << selectedCar;
	cout << "Nhap ten: ";
	in.ignore();
	getline(in, fullName);
	cout << "Nhap so dien thoai: "; in >> phoneNumber;

	string carID = selectedCar.getCarID();
	int departureTime = selectedCar.getTime();
	
	Passenger *newPassenger = new Passenger(fullName, phoneNumber, bookingSeats, destination, carID, departureTime, 
		departureDate, carLinkedList.getPrice(carID) * bookingSeats);
	
	if (passengerLinkedList.head == NULL) {
		passengerLinkedList.head = newPassenger;
	} else {
		Passenger *temp = new Passenger(*passengerLinkedList.head);
		passengerLinkedList.head = newPassenger;
		passengerLinkedList.head->next = temp;
	}
	cout << *newPassenger;

	passengerLinkedList.writeFile("receipt.txt");
	scheduleLinkedList.addNode(selectedCar, bookingSeats);

	return in;
}

void PassengerLinkedList::writeFile(string fileName) {
	fstream output;
	output.open(fileName, ios::out);
	Passenger *passengerNode = head;
	while (passengerNode->next != NULL) {
		output << passengerNode->fullName << ", " << passengerNode->phoneNumber << ", " << passengerNode->bookedSeats << ", " << passengerNode->destination
			<< ", " << passengerNode->carID << ", " << passengerNode->departureTime << ", " << passengerNode->departureDate << ", " << passengerNode->totalPrice << endl;
		passengerNode = passengerNode->next;
	}
	output << passengerNode->fullName << ", " << passengerNode->phoneNumber << ", " << passengerNode->bookedSeats << ", " << passengerNode->destination
		<< ", " << passengerNode->carID << ", " << passengerNode->departureTime << ", " << passengerNode->departureDate << ", " << passengerNode->totalPrice;
	output.close();
}