#include "date.h"
#include "node.h"
#include <chrono>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

void Date::setDate(string str) {
	string tempDay, tempMonth, tempYear;
	int i = 0;
	while (str[i] != '/') {
		tempDay.push_back(str[i++]);
	}
	i++;
	while (str[i] != '/') {
		tempMonth.push_back(str[i++]);
	}
	i++;
	while (i < str.size()) {
		tempYear.push_back(str[i++]);
	}

	day = stoi(tempDay);
	month = stoi(tempMonth);
	year = stoi(tempYear);
}

void Date::getCurrentDate() {
   auto end = std::chrono::system_clock::now();
   std::time_t end_time = std::chrono::system_clock::to_time_t(end);
   string str = std::ctime(&end_time);
   cout << str;
   string tempDay, tempMonth, tempYear;

   for (int i = 4; i < 7; i++) {
	   tempMonth.push_back(str[i]);
   }
   for (int i = 8; i < 10; i++) {
	   tempDay.push_back(str[i]);
   }
   for (int i = 20; i < 24; i++) {
	   tempYear.push_back(str[i]);
   }

   day = stoi(tempDay);
   year = stoi(tempYear);
   string monthArray[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
   for (int i = 0; i < 12; i++) {
	   if (tempMonth == monthArray[i]) {
		   month = i + 1;
	   }
   }
}

ostream& operator << (ostream& out, const Date& date) {
	cout << date.day << "/" << date.month << "/" << date.year << endl;
	return out;
}