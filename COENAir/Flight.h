#pragma once
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef FLIGHT
#define FLIGHT
class Flight{
private:
	static unsigned int globalID;
	string ID;
	string departureCity;
	string arrivalCity;
	Date departureDate;
	Date arrivalDate;
	unsigned int duration;

public:
	Flight(string dc = {}, string ac = {}, Date& depart, Date& arrival, unsigned int d = 0);
	Flight(Flight&);
	string getID();
	string getDepartureCity();
	string getArrivalCity();
	Date getDepartureDate();
	Date getArrivalDate();
	unsigned int getDuration();
	void setDepartureCity(string&);
	void setArrivalCity(string&);
	void setDepartureDate(Date&);
	void setArrivalDate(Date&);
	void setDuration(unsigned int);
};

#endif // FLIGHT