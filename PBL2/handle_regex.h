#pragma once
#pragma once

#ifndef HANDLEREGEX_H
#define HANDLEREGEX_H

#include <iostream>
#include <string>
using namespace std;

class HandleRegex {
public:
	HandleRegex(std::string, std::string&, bool (*function)(std::string));
	HandleRegex(std::string, int&, bool (*function)(int, int), int);
	static bool checkDestination(std::string a);
	static bool checkDepartureDate(std::string a);
	static bool checkSelectChoice(int, int);
	static bool checkYN(std::string);
};
#endif