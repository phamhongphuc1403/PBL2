#include "schedule.h"
using namespace std;

Schedule::Schedule(string carID, string  departmentTime, string departmentDate, string bookedSeats)
	:carID(carID), departmentTime(stoi(departmentTime)), departmentDate(departmentDate), bookedSeats(stoi(bookedSeats)) {
	this->next = NULL;
}