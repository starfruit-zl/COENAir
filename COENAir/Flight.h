#pragma once
#include "Date.h"
#include <iostream>
#include <string>

using namespace std;

#ifndef FLIGHT
#define FLIGHT
class Flight{
private:
	static unsigned int globalID; //used to manage number for unique IDs
	string ID;
	string departureCity;
	string arrivalCity;
	Date departureDate;
	Date arrivalDate;
	unsigned int duration;
	void setDuration();

public:
	Flight(string dc, string ac, Date depart, Date arrival);
	Flight();
	Flight(Flight&);
	~Flight();
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
	void printFlight();
};

#endif // FLIGHT
