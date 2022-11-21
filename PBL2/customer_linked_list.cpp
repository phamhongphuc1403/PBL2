#include "customer_linked_list.h"
#include "customer.h"
#include "car_linked_list.h"
#include "car.h"
#include "schedule_linked_list.h"
#include "schedule.h"
#include "available_cars_linked_list.h"

using namespace std;

CustomerLinkedList::CustomerLinkedList(string fileName) {
	ifstream input(fileName);
	string fullName, destination, carID, phoneNumber, date, bookedSeats, totalPrice;
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
		getline(input, date, ',');
		input.seekg(1, ios::cur);
		getline(input, totalPrice, '\n');
		//cout << fullName << phoneNumber << bookedSeats << destination << carID << date << endl;
		Customer *newNode = new Customer(fullName, phoneNumber, stoi(bookedSeats), destination, carID, date, stoll(totalPrice));
		if (head == NULL) {
			head = newNode;
		} else {
			Customer* tempNode = head;
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			tempNode->next = newNode;
		}
	}
}

ostream& operator << (ostream& out, const CustomerLinkedList& customerLinkedList) {
	if (customerLinkedList.head != NULL) {
        Customer *customer = customerLinkedList.head;
        while (customer != NULL) {
            out << *customer;
            customer = customer->next;
        }
    }
	return out;
}

istream& operator >> (istream& in, CustomerLinkedList& customerLinkedList) {
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
	
	Customer *newCustomer = new Customer(fullName, phoneNumber, bookingSeats, destination, carID, departureDate, 
		carLinkedList.getPrice(carID) * bookingSeats);
	
	if (customerLinkedList.head == NULL) {
		customerLinkedList.head = newCustomer;
	} else {
		Customer *temp = new Customer(*customerLinkedList.head);
		customerLinkedList.head = newCustomer;
		customerLinkedList.head->next = temp;
	}
	cout << *newCustomer;

	customerLinkedList.writeFile("receipt.txt");
	scheduleLinkedList.addNode(selectedCar, bookingSeats);

	return in;
}

void CustomerLinkedList::writeFile(string fileName) {
	fstream output;
	output.open(fileName, ios::out);
	Customer *customerNode = head;
	while (customerNode->next != NULL) {
		output << customerNode->fullName << ", " << customerNode->phoneNumber << ", " << customerNode->bookedSeats << ", " << customerNode->destination
			<< ", " << customerNode->carID << ", " << customerNode->departureDate << ", " << customerNode->totalPrice << endl;
		customerNode = customerNode->next;
	}
	output << customerNode->fullName << ", " << customerNode->phoneNumber << ", " << customerNode->bookedSeats << ", " << customerNode->destination
		<< ", " << customerNode->carID << ", " << customerNode->departureDate << ", " << customerNode->totalPrice;
	output.close();
}