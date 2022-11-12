#pragma once

#ifndef CAR_H
#define CAR_H

#include "Info.h"

class Car : public Info {
	private:
		std::string id;
		std::string type;
	public:
		virtual void readFile(std::ifstream&);
		virtual void writeFile(std::ofstream&);
		virtual void printFile();
		virtual void get();
};
#endif

