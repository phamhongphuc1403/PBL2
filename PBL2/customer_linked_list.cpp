#include "customer_linked_list.h"
#include "customer.h"


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
		getline(input, date , '\n');
			
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
	//Date bookingDate;
	string carID, destination, bookingDate;
	cout << "Nhap thong tin khach hang moi." << endl;
	cout << "Nhap ten." << endl;
	getline(in, fullName);
	cout << "Nhap so dien thoai: "; in >> phoneNumber;
	cout << "Nhap Vao So Luong Ve dat"; in >> bookedSeats;
	cout << "Nhap diem den: "; in >> destination;
	cout << "Nhap loai xe :"; in >> carID;
	cout << "Nhap Vao Ngay: "; in >> bookingDate;
;
	Customer *newCustomer = new Customer(fullName, phoneNumber, bookedSeats, destination, carID, bookingDate);
	if (customerLinkedList.head == NULL) {
		customerLinkedList.head = newCustomer;
	} else {
		Customer *temp = new Customer(*customerLinkedList.head);
		cout << "head cu" << * temp << endl;

		customerLinkedList.head = newCustomer;
		cout << "head moi" << *newCustomer << endl;
		customerLinkedList.head->next = temp;
	}
	return in;
}

void CustomerLinkedList::writeFile() {
	
}