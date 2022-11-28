#include "date.h"
#include "node.h"
using namespace std;

Date::Date(string str) {
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