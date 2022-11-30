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

long long CarLinkedList::getPrice(string carID) {
	Car *carNode = head;
	while (carNode != NULL) {
		if (carNode->carID == carID) return carNode->price;
		carNode = carNode->next;
	}
}

void CarLinkedList::findCar(string carID) {
	Car* carNode = head;
	bool isFound = false;
	while (carNode != NULL) {
		if (carNode->carID == carID) {
			cout << *carNode;
			isFound = true;
			break;
		}
		carNode = carNode->next;
	}
	if (!isFound) {
		cout << "Khong tim thay xe." << endl;
	}
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
		string requiredTime[3][2] = { {"Hue", "5"}, {"Ha Noi", "20"},{"TP HCM", "20"} };
		int temp;
		bool isSuitable = true;
		string answer;

		cout << "1. Chinh sua diem den" << endl;
		cout << "2. Chinh sua gio khoi hanh" << endl;
		cout << "3. Chinh sua gia tien" << endl;
		cout << "ban chon: "; cin >> choice;

		switch (choice) {
		case 1:
			cout << "Nhap diem den (Ha Noi/Hue/TP HCM): "; 
			cin.ignore();
			getline(cin, str);
			carNode->setDestination(str);
		case 2:
			do {
				cout << "Nhap thoi gian khoi hanh (0 - 23): "; cin >> temp;
				for (int i = 0; i < 3; i++) {
					if (carNode->destination == requiredTime[i][0]) {
						for (int j = 0; j < departureTimeCount; j++) {
							if (abs(temp - departureTimeArray[j]) < stoi(requiredTime[i][1])) {
								isSuitable = false;
							}
						}
						if (isSuitable) {
							departureTimeArray[++departureTimeCount] = temp;
						}
						else {
							cout << "Xe chua kip ve ben." << endl;
							break;
						}
					}
				}
				cout << "Ban co muon nhap tiep khong? (Y/N): "; cin >> answer;
				if (answer == "Y") {
					continue;
				} else {
					break;
				}
			} while (true);
			carNode->setDepartureTime(departureTimeCount, departureTimeArray);
		case 3:
			cout << "Nhap gia tien moi: "; cin >> str;
			carNode->setPrice(stoll(str));
			break;
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