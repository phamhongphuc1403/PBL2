#include "car_linked_list.h"
#include "car.h"
#include "schedule_linked_list.h"
#include "schedule.h"

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
		Car *newCar = new Car(carID, capacity, destination, price, departureTimeCount, departureTimeArray);
		if (head == NULL) {
			head = newCar;
		}
		else {
			Car* tempNode = head;
			while (tempNode->next != NULL) {
				tempNode = tempNode->next;
			}
			tempNode->next = newCar;
		}
	}
	input.close();
}

ostream& operator << (ostream& out, const CarLinkedList& carLinkedList) {
	out << setiosflags(ios::left) << setw(15) << "Bien so xe" << setiosflags(ios::left) << setw(15) << "So cho" << setiosflags(ios::left) << setw(15) << "Diem den"
		<< setiosflags(ios::left) << setw(15) << "Gia tien" << "Gio xuat phat trong ngay" << endl;

	if (carLinkedList.head != NULL) {
		Car* car = carLinkedList.head;
		while (car != NULL) {
			out << *car;
			car = car->next;
		}
	}
	return out;
}

long long CarLinkedList::getPrice(string carID) {
	Car *carNode = head;
	while (carNode != NULL) {
		if (carNode->carID == carID) return carNode->price;
		carNode = carNode->next;
	}
}

bool CarLinkedList::findCar(string carID) {
	Car* carNode = head;
	bool isFound = false;
	while (carNode != NULL) {
		if (carNode->carID == carID) {
			cout << setiosflags(ios::left) << setw(15) << "Bien so xe" << setiosflags(ios::left) << setw(15) << "So cho" << setiosflags(ios::left) << setw(15) << "Diem den"
				<< setiosflags(ios::left) << setw(15) << "Gia tien" << "Gio xuat phat trong ngay" << endl;
			cout << *carNode;
			isFound = true;
			break;
		}
		carNode = carNode->next;
	}
	if (!isFound) {
		cout << "Khong tim thay xe." << endl;
		return false;
	}
	return true;
}

void CarLinkedList::editCar(string carID) {
	Car* carNode = head;
	bool isFound = false;
	while (carNode != NULL) {
		if (carNode->carID == carID) {
			isFound = true;
			break;
		}
		carNode = carNode->next;
	}
	if (!isFound) {
		cout << "Khong tim thay xe." << endl;
	}
	else {
		int choice;
		int departureTimeArray[5] = { 0, 0, 0, 0, 0 }, departureTimeCount = 0;
		string str;
		string requiredTime[3][2] = { {"Hue", "6"}, {"Ha Noi", "20"},{"TP HCM", "20"} };
		int temp;
		bool isSuitable = true;
		string answer;

		cout << "1. Chinh sua gio khoi hanh" << endl;
		cout << "2. Chinh sua gia tien" << endl;
		cout << "ban chon: "; cin >> choice;

		switch (choice) {
		case 1:
			do {
				cout << "Nhap thoi gian khoi hanh (0 - 23): "; cin >> temp;
				for (int i = 0; i < 3; i++) {
					isSuitable = true;
					if (carNode->destination == requiredTime[i][0]) {
						for (int j = 0; j < departureTimeCount; j++) {
							if (abs(temp - departureTimeArray[j]) < stoi(requiredTime[i][1]) || abs(temp - 24 - departureTimeArray[j]) < stoi(requiredTime[i][1])) {
								isSuitable = false;
							}
						}
						if (isSuitable) {
							departureTimeArray[departureTimeCount++] = temp;
						}
						else {
							cout << "Xe chua kip ve ben." << endl;
							break;
						}
					}
				}
				cout << "Ban co muon nhap tiep khong? (Y/N): "; cin >> answer;
				if (answer == "Y" || answer == "y") {
					continue;
				} else {
					break;
				}
			} while (true);
			carNode->setDepartureTime(departureTimeCount, departureTimeArray);
			break;
		case 2:
			cout << "Nhap gia tien moi: "; cin >> str;
			carNode->setPrice(stoll(str));
			break;
		default:
			cout << "sai cu phap." << endl;
		}
	}	
	writeFile("car.txt");
}

void CarLinkedList::writeFile(string fileName) {
	fstream output;
	output.open(fileName, ios::out);
	Car* carNode = head;
	while (carNode->next != NULL) {
		output << carNode->carID << ", " << carNode->capacity << ", " << carNode->destination << ", " << carNode->price << ", ";
		for (int i = 0; i < carNode->departureTimeCount - 1; i++) {
			output << carNode->departureTime[i] << ", ";
		}
		output << carNode->departureTime[carNode->departureTimeCount - 1] << endl;
		carNode = carNode->next;
	}
	output << carNode->carID << ", " << carNode->capacity << ", " << carNode->destination << ", " << carNode->price << ", ";
	for (int i = 0; i < carNode->departureTimeCount - 1; i++) {
		output << carNode->departureTime[i] << ", ";
	}
	output << carNode->departureTime[carNode->departureTimeCount - 1];
	output.close();
}

void CarLinkedList::printIncome(int month) {
	long long sum = 0;
	ScheduleLinkedList scheduleList("schedule.txt");
	Car* carNode = head;
	cout << setiosflags(ios::left) << setw(15) << "Bien so xe" << setiosflags(ios::left) << setw(15) << "So ve da dat" << setiosflags(ios::left) << setw(15) << "Doanh thu" << endl;
	while (carNode != NULL) {
		int count = 0;
		Schedule* scheduleNode = scheduleList.head;
		while (scheduleNode != NULL) {
			if (scheduleNode->departureDate.getMonth() == month && scheduleNode->carID == carNode->carID) {
				count = count + scheduleNode->bookedSeats;
			}
			scheduleNode = scheduleNode->next;
		}
		sum += carNode->price * count;
		cout << setiosflags(ios::left) << setw(15) << carNode->carID << setiosflags(ios::left) << setw(15) << count << setiosflags(ios::left) << setw(15) << carNode->price * count << endl;
		carNode = carNode->next;
	}
	cout << "Tong doanh thu thang " << month << ": " << sum << endl;
}