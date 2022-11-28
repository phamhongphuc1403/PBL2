#include "car.h"
#include "car_linked_list.h"
#include "passenger.h"
#include "passenger_linked_list.h"
#include "date.h"
#include <chrono>
#include <ctime>
#pragma warning(disable : 4996)
using namespace std;

int main() {
	PassengerLinkedList receipt("receipt.txt");
	//cout << receipt;
	//CarLinkedList car("car.txt");
	//cout << car;
	

    //// Some computation here
 //   auto end = std::chrono::system_clock::now();

 //   std::time_t end_time = std::chrono::system_clock::to_time_t(end);

	//string str = std::ctime(&end_time);
	//string date, month, year;


	//for (int i = 4; i < 7; i++) {
	//	month.push_back(str[i]);
	//}
	//for (int i = 8; i < 10; i++) {
	//	date.push_back(str[i]);
	//}
	//for (int i = 20; i < 24; i++) {
	//	year.push_back(str[i]);
	//}
 //   std::cout  << date << " " << month << " " << year;

	Date h("13/1/2003");

	//cin >> receipt;

	//int n, chon, a;
	//string pn;
	//do {
	//	cout << "============MENU=============" << endl;
	//	cout << "1: Them khach hang. " << endl;
	//	cout << "3: Xem hoa don dat xe" << endl;
	//	cout << "2: Xem thong tin xe." << endl;
	//	cout << "4: Tim hoa don Theo So Dien Thoai." << endl;
	//	cout << "5: Thoat Chuong Trinh." << endl;
		//cout << "Moi nhap lua chon cua ban :"; cin >> chon;
}
