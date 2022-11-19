#include "schedule.h"
using namespace std;

Schedule::Schedule(string carID, string  departureTime, string departureDate, string bookedSeats)
	:carID(carID), departureTime(stoi(departureTime)), departureDate(departureDate), bookedSeats(stoi(bookedSeats)) {
	this->next = NULL;
}