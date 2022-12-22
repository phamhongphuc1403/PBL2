#include "schedule.h"
using namespace std;

Schedule::Schedule(string carID, int departureTime, string departureDate, int bookedSeats)
	:carID(carID), departureTime(departureTime), bookedSeats(bookedSeats) {
	this->departureDate = departureDate;
	this->next = NULL;
}