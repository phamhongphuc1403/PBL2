#include "passenger_linked_list.h"
#include "passenger.h"
#include "car_linked_list.h"
#include "car.h"
#include "schedule_linked_list.h"
#include "schedule.h"
#include "available_cars_linked_list.h"
#include "handle_regex.h"
using namespace std;

PassengerLinkedList::PassengerLinkedList(string fileName) {
	ifstream input(fileName);
	string fullName, destination, carID, bookingDate, phoneNumber, departureDate, bookedSeats, totalPrice, time;
	while (!input.eof()) {
		getline(input, fullName, ',');
		input.seekg(1, ios::cur);
		getline(input, phoneNumber, ',');
		input.seekg(1, ios::cur);
		getline(input, bookingDate, ',');
		input.seekg(1, ios::cur);
		getline(input, bookedSeats, ',');
		input.seekg(1, ios::cur);
		getline(input, destination, ',');
		input.seekg(1, ios::cur);
		getline(input, carID, ',');
		input.seekg(1, ios::cur);
		getline(input, time, ',');
		input.seekg(1, ios::cur);
		getline(input, departureDate, ',');
		input.seekg(1, ios::cur);
		getline(input, totalPrice, '\n');
		Passenger *newNode = new Passenger(fullName, phoneNumber, bookingDate, stoi(bookedSeats), destination, carID, stoi(time), departureDate, stoll(totalPrice));
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
		cout << setiosflags(ios::left) << setw(25) << "Ho va ten" << setiosflags(ios::left) << setw(20) << "So dien thoai" << setiosflags(ios::left) << setw(20) << "Ngay dat ve" << setiosflags(ios::left) << setw(10) << "So ve"
			<< setiosflags(ios::left) << setw(15) << "Diem den" << setiosflags(ios::left) << setw(20) << "Bien so" << setiosflags(ios::left) << setw(20) << "Ngay khoi hanh"
			<< setiosflags(ios::left) << setw(10) << "Gio" << setiosflags(ios::left) << "Gia tien" << endl;
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
	HandleRegex("Nhap diem den (Ha Noi / Hue / TP HCM): ", destination, &HandleRegex::checkDestination);
	HandleRegex("Nhap ngay khoi hanh: ", departureDate, &HandleRegex::checkDepartureDate);
	cout << "Nhap so luong ve muon mua: "; in >> bookingSeats;

	AvailableCarsLinkedList availableCarsLinkedList(destination, departureDate, bookingSeats);
	cout << availableCarsLinkedList;
	int numOfCars = availableCarsLinkedList.getNumOfCars();
	HandleRegex("Nhap so thu tu xe muon chon: ", choice, &HandleRegex::checkSelectChoice, numOfCars);
	AvailableCar selectedCar = availableCarsLinkedList.getNode(choice);

	string carID = selectedCar.getCarID();

	cout << "So tien can thanh toan: " << carLinkedList.getPrice(carID) * bookingSeats;
	if (!HandleRegex::checkYN(". Tiep tuc? (Y/N): ")) {
		return in;
	}
	cout << "Nhap ten: ";
	in.ignore();
	getline(in, fullName);
	cout << "Nhap so dien thoai: "; in >> phoneNumber;

	
	int departureTime = selectedCar.getTime();
	
	Passenger* newPassenger = new Passenger(fullName, phoneNumber, "", bookingSeats, destination, carID, departureTime,
		departureDate, carLinkedList.getPrice(carID) * bookingSeats);
	
	if (passengerLinkedList.head == NULL) {
		passengerLinkedList.head = newPassenger;
	} else {
		Passenger *temp = new Passenger(*passengerLinkedList.head);
		passengerLinkedList.head = newPassenger;
		passengerLinkedList.head->next = temp;
	}
	//cout << *newPassenger;

	passengerLinkedList.writeFile("receipt.txt");
	scheduleLinkedList.addNode(selectedCar, bookingSeats);

	return in;
}

void PassengerLinkedList::writeFile(string fileName) {
	fstream output;
	output.open(fileName, ios::out);
	Passenger *passengerNode = head;
	while (passengerNode != NULL) {
		output << passengerNode->fullName << ", " << passengerNode->phoneNumber << ", " << passengerNode->bookingDate.toString() << ", " << passengerNode->bookedSeats << ", " << passengerNode->destination
			<< ", " << passengerNode->carID << ", " << passengerNode->departureTime << ", " << passengerNode->departureDate.toString() << ", " << passengerNode->totalPrice;
		if (passengerNode->next != NULL) output << endl;
		passengerNode = passengerNode->next;
	}
	
	output.close();
}

void PassengerLinkedList::findPassenger(string phoneNumber) {
	Passenger* passengerNode = head;
	bool isFound = false;
	while (passengerNode != NULL) {
		if (passengerNode->phoneNumber == phoneNumber) {
			cout << *passengerNode;
			isFound = true;
		}
		passengerNode = passengerNode->next;
	}
	if (!isFound) {
		cout << "Khong tim thay hanh khach." << endl;
	}
}