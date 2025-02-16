#pragma once
#include "Date.h"
#include "Passenger.h"
#include <iostream>
#include <string>
#include <vector>

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
	vector<Passenger> passengers;

public:
	Flight(string dc = {}, string ac = {}, Date depart = (0,0,0,0,0,0), Date arrival = (0, 0, 0, 0, 0, 0), unsigned int d = 0, vector<Passenger> pas = {});
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
	void setDuration(unsigned int);
	void printFlight();
	void addPassenger(const Passenger&);
	void removePassenger(string);
	bool searchPassenger(string);
	void displayPassengers();
};

#endif // FLIGHT