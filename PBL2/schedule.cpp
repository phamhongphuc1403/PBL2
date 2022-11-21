#include "schedule.h"
using namespace std;

Schedule::Schedule(string carID, int departureTime, string departureDate, int bookedSeats)
	:carID(carID), departureTime(departureTime), departureDate(departureDate), bookedSeats(bookedSeats) {
	this->next = NULL;
}