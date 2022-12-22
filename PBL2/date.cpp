#include "date.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <chrono>
#include <ctime>
#pragma warning(disable : 4996)

using namespace std;

Date::Date(string str) {
	setDate(str);
}

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

void Date::setCurrentDate() {
   auto end = std::chrono::system_clock::now();
   std::time_t end_time = std::chrono::system_clock::to_time_t(end);
   string str = std::ctime(&end_time);
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
	cout << date.day << "/" << date.month << "/" << date.year;
	return out;
}

void Date::operator = (string str) {
	setDate(str);
}

bool Date::operator == (const Date& date) {
	return date.day == day && date.month == month && date.year == year;
}

string Date::toString() {
	return to_string(day) + "/" + to_string(month) + "/" + to_string(year);
}

int Date::getMonth() {
	return month;
}

bool isLeap(int year) {
	return (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0));
}

bool Date::isValid() {
	if (month < 1 || month > 12) return false;
	if (day < 1 || day > 31) return false;
	if (month == 2)	{
		if (isLeap(year)) {
			return (day <= 29);
		} else {
			return (day <= 28);
		}
	}
	if (month == 4 || month == 6 ||	month == 9 || month == 11) return (day <= 30);
	return true;
}

bool Date::operator >= (const Date& date) {
	try {
		if (year < date.year) {
			throw false;
		}
		else if (year == date.year) {
			if (month < date.month) {
				throw false;
			}
			else if (month == date.month) {
				if (day < date.day) {
					throw false;
				}
			}
		}
	} catch (bool e) {
		cout << "Ngay xuat phat khong duoc nho hon ngay hien tai." << endl;
		return e;
	}
	return true;
}