#pragma once
#include "Date.h"
#include "Time.h"
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
	Date d1;
	Flight();
	Flight(string dc, string ac, unsigned int d, Date& depart, Date& arrival); //default constructor hated having objects set to default nulls, so unique null constructor nescessary.
	~Flight();
	Flight(const Flight&); //added const modifier to make code work, basically it requires the const to adapt to out of scoped returns. Stops re-allocation of memory.
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
	void printFlight();
};

#endif // FLIGHT
