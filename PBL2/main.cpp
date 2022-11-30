#include "car.h"
#include "car_linked_list.h"
#include "passenger.h"
#include "passenger_linked_list.h"
#include "date.h"

using namespace std;

int main() {
	//PassengerLinkedList receipt("receipt.txt");
	//cout << receipt;
	CarLinkedList car("car.txt");
	cout << car;
	car.editCar("43B.0001");
	cout << car;
	//receipt.findPassenger("1");
	//cin >> receipt;

	//int n, chon, a;
	//string pn;
	//do {
	//	cout << "============MENU=============" << endl;
	//	cout << "1: Them khach hang. " << endl;
	//	cout << "3: Xem hoa don dat xe" << endl;
	//	cout << "2: Xem thong tin xe." << endl;
	//	cout << "4: Tim hoa don Theo So Dien Thoai." << endl;
	//	cout << "6: Xem thong tin xe." << endl;
	//	cout << "7: Tim xe theo bien so xe." << endl;
	//	cout << "8: Sua thong tin xe." << endl;
	//	cout << "0: Thoat Chuong Trinh." << endl;
		//cout << "Moi nhap lua chon cua ban :"; cin >> chon;
}
