#pragma once
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef FLIGHT
#define FLIGHT
class Flight{
private:
	string ID;
	string departureCity;
	string arrivalCity;
	Date departureDate;
	Date arrivalDate;
	unsigned int duration;

public:
	Flight(string id = {}, string dc = {}, string ac = {}, Date depart, Date arrival);
	~Flight();

};

#endif // FLIGHT
