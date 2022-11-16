#include "car.h"
#include "car_linked_list.h"
#include "customer.h"
#include "customer_linked_list.h"
#include <chrono>
#include <ctime>   
#pragma warning(disable : 4996)
using namespace std;

int main() {
	CustomerLinkedList receipt("receipt.txt");

	//CarLinkedList car("car.txt");
	//cout << car;
	

    //auto start = std::chrono::system_clock::now();
    //// Some computation here
    //auto end = std::chrono::system_clock::now();

    //std::chrono::duration<double> elapsed_seconds = end - start;
    //std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    //std::cout << "finished computation at " << std::ctime(&end_time)
    //    << "elapsed time: " << elapsed_seconds.count() << "s"
    //    << std::endl;

	cin >> receipt;
	//cout << receipt;
	//receipt.writeFile("receipt.txt");

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
