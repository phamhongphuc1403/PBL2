#include "bus_company_management_app.h"
#include "passenger_linked_list.h"
#include "car_linked_list.h"
#include <iostream>
using namespace std;

void App::printIntro() {
	cout << "\t ______________________________________________________________________________________________ \n";
	cout << "\t|                                                                                              |\n";
	cout << "\t|                                 DO AN PBL2: LAP TRINH TINH TOAN                              |\n";
	cout << "\t|                                                                                              |\n";
	cout << "\t|                             DE TAI: XAY DUNG UNG DUNG QUAN LI HANG XE                        |\n";
	cout << "\t|                                                                                              |\n";
	cout << "\t|                                                                                              |\n";
	cout << "\t|                            Giao vien huong dan: Nguyen Thi Minh Hy                           |\n";
	cout << "\t|                                                                                              |\n";
	cout << "\t|                                                                                              |\n";
	cout << "\t|                        Sinh vien thuc hien:  Pham Hong Phuc - 102210271                      |\n";
	cout << "\t|                                              Thai Ngoc Quy - 102210274                       |\n";
	cout << "\t|                                                                                              |\n";
	cout << "\t|______________________________________________________________________________________________|\n";
	cout << endl;
}

void App::run() {
	printIntro();
	int chon;
	do {
		cout << "============MENU=============" << endl;
		cout << "1. Quan li hanh khach. " << endl;
		cout << "2. Quan li xe" << endl;
		cout << "0. Thoat chuong trinh" << endl;
		cout << "Moi nhap lua chon cua ban: "; cin >> chon;
		switch (chon) {
		case 1:
			passengersManager();
			break;
		case 2:
			carsManager();
		case 0:
			break;
		default:
			cout << "sai cu phap, moi ban nhap lai";
		} 
		clearScreen();
	} while (chon);
}

void App::clearScreen() {
	cout << "\033[2J\033[1;1H";
}

void App::passengersManager() {
	clearScreen();
	PassengerLinkedList receipt("receipt.txt");
	int chon;
	string pn;
	do {
		cout << "============QUAN LI HANH KHACH=============" << endl;
		cout << "1. Them hoa don. " << endl;
		cout << "2. Xem lich su mua ve" << endl;
		cout << "3. Tim hoa don theo so dien thoai" << endl;
		cout << "0. quay lai" << endl;
		cout << "Moi nhap lua chon cua ban: "; cin >> chon;
		clearScreen();
		switch (chon) {
		case 1:
			cin.ignore();
			cin >> receipt;
			break;
		case 2:
			cout << receipt;
			break;
		case 3:
			cout << "Nhap so dien thoai: ";
			cin >> pn;
			receipt.findPassenger(pn);
			break;
		case 0:
			break;
		default:
			cout << "sai cu phap, moi ban nhap lai";
		}
	} while (chon);
}

void App::carsManager() {
	clearScreen();
	CarLinkedList car("car.txt");
	int chon, month;
	string carID;
	do {
		cout << "============QUAN LI XE=============" << endl;
		cout << "1. Xem thong tin tat ca cac xe dang su dung." << endl;
		cout << "2. Thong ke doanh thu theo thang." << endl;
		cout << "3. Tim xe theo bien so xe." << endl;
		cout << "4. Sua thong tin xe." << endl;
		cout << "0. Quay lai" << endl;
		cout << "Moi nhap lua chon cua ban: "; cin >> chon;
		clearScreen();
		switch (chon) {
		case 1:
			cout << car;
			break;
		case 2:
			cout << "Nhap thang: "; cin >> month;
			car.printIncome(month);
			break;
		case 3:
			cout << "Nhap bien so xe: "; cin >> carID;
			car.findCar(carID);
			break;
		case 4:
			cout << "Nhap bien so xe: "; cin >> carID;
			if (car.findCar(carID)) car.editCar(carID);
		case 0:
			break;
		default:
			cout << "sai cu phap, moi ban nhap lai";
		}
	} while (chon);
}
