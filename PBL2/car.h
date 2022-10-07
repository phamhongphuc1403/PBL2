#pragma once
#include <string>

#ifndef CAR_H
#define CAR_H
class Car {
private:
	std::string type, driver, licensePlate;
	int driverID, seats, bookedSeats;
public:
	Car(std::string, std::string, std::string, int, int, int);
	void increaseBookedSeats();
	void getSeats();
	void Show();
	void Set();
};

#endif // !1

class car
{
};
