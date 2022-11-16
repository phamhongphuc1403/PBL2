#include "schedule.h"
using namespace std;

Schedule::Schedule(string carID, int  departmentTime, string departmentDate, int bookedSeats)
	:carID(carID), departmentTime(departmentTime - '0'), departmentDate(departmentDate), bookedSeats(bookedSeats - '0') {
	this->next = NULL;
}