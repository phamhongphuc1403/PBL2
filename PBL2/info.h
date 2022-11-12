#pragma once

#ifndef INFO_H
#define INFO_H

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

class Info {
	protected:
		std::string phoneNumber;
	public:
		virtual void readFile(std::ifstream &);
		virtual void writeFile(std::ofstream&);
		virtual void printFile();
		virtual void get();
		friend int main();
		std::string getPhoneNumber();
};
#endif