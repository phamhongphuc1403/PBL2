#include "handle_regex.h"
#include "date.h"
using namespace std;

HandleRegex::HandleRegex(string printStr, string& checkStr, bool (*function)(string)) {
	do {
		cout << printStr;
		getline(cin, checkStr);
		if (function(checkStr)) {
			break;
		}
		else {
			cout << "Sai cu phap, moi ban nhap lai." << endl;
		}
	} while (true);
}
HandleRegex::HandleRegex(string printStr, int& checkInt, bool (*function)(int, int), int referenceInt) {
	do {
		cout << printStr;
		cin >> checkInt;
		if (function(checkInt, referenceInt)) {
			break;
		}
		else {
			cout << "Sai cu phap, moi ban nhap lai." << endl;
		}
	} while (true);
}
bool HandleRegex::checkDestination(string str) {
	return str == "Ha Noi" || str == "Hue" || str == "TP HCM";
}

bool HandleRegex::checkDepartureDate(string str) {
	Date checkDate(str);
	Date currentDate;
	currentDate.setCurrentDate();
	return checkDate.isValid() && checkDate >= currentDate;
}

bool HandleRegex::checkSelectChoice(int a, int b) {
	return a <= b;
}

bool HandleRegex::checkYN(string printStr) {
	string str;
	do {
		cout << printStr;
		cin >> str;
		if (str == "Y" || str == "y") return true;
		if (str == "N" || str == "n") return false;
		cout << "Sai cu phap, moi ban nhap lai." << endl;
	} while (true);
}