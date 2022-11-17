#include "customer_linked_list.h"
#include "customer.h"
#include "car_linked_list.h"
#include "car.h"
#include "schedule_linked_list.h"
#include "schedule.h"

using namespace std;

CustomerLinkedList::CustomerLinkedList(string fileName) {
	ifstream input(fileName);
	string fullName, destination, carID, phoneNumber, date, bookedSeats;
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
		getline(input, date, '\n');
		//cout << fullName << phoneNumber << bookedSeats << destination << carID << date << endl;
		if (head == NULL) {
			head = new Customer(fullName, phoneNumber, bookedSeats, destination, carID, date);
		} else {
			Customer* tempNode = head;
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			tempNode->next = new Customer(fullName, phoneNumber, bookedSeats, destination, carID, date);
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
	string fullName, phoneNumber, bookedSeats;
	string carID, destination, bookingDate;
	CarLinkedList cars("car.txt");
	ScheduleLinkedList schedule("schedule.txt");

	

	cout << "Nhap thong tin khach hang moi." << endl;
	cout << "Nhap ten: ";
	getline(in, fullName);
	cout << "Nhap so dien thoai: "; in >> phoneNumber;
	cout << "Nhap diem den: ";
	in.ignore();
	getline(in, destination);
	cout << "Nhap Vao Ngay: "; in >> bookingDate;

	//Schedule* scheduleNode = schedule.head;
	//Car* carNode = cars.head;

	cars.printAvailableCars(destination, bookingDate);
	

	cout << "Nhap Vao So Luong Ve dat"; in >> bookedSeats;

	Customer *newCustomer = new Customer(fullName, phoneNumber, bookedSeats, destination, carID, bookingDate);
	if (customerLinkedList.head == NULL) {
		customerLinkedList.head = newCustomer;
	} else {
		Customer *temp = new Customer(*customerLinkedList.head);
		customerLinkedList.head = newCustomer;
		customerLinkedList.head->next = temp;
	}
	return in;
}

void CustomerLinkedList::writeFile(string fileName) {
	fstream output;
	output.open(fileName, ios::out);
	Customer *customerNode = head;
	while (customerNode != NULL) {
		output << customerNode->fullName << ", " << customerNode->phoneNumber << ", " << customerNode->bookedSeats << ", " << customerNode->destination
			<< ", " << customerNode->carID << ", " << customerNode->bookingDate << endl;
		customerNode = customerNode->next;
	}
	output.close();
}