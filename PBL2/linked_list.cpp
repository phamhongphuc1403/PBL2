#include "linked_list.h"
#include "customer.h"
using namespace std;

LinkedList::LinkedList(string fileName) {
	if (fileName == "receipt.txt") {
		/*getline(filein, hoten, ',');
		filein.seekg(1, 1);
		getline(filein, sdt, ',');
		filein >> chuyenxe;*/
		ifstream input(fileName);
		string fullName, destination, type, phoneNumber;
		string date;
		string bookedSeats;
		while (!input.eof()) {

			getline(input, fullName, ',');
			input.seekg(1, ios::cur);
			cout << "ten " << fullName << endl;
			getline(input, phoneNumber, ',');
			input.seekg(1, ios::cur);
			cout << "std " << phoneNumber << endl;
			getline(input, bookedSeats, ',');
			input.seekg(1, ios::cur);
			cout << "dat " << bookedSeats << endl;
			getline(input, destination, ',');
			input.seekg(1, ios::cur);
			cout << "diem den " << destination << endl;
			getline(input, type, ',');
			input.seekg(1, ios::cur);
			cout << "loai xe " << type << endl;
			getline(input, date , '\n');
			cout << "ngay " << date << endl << endl;
		}
	}
}