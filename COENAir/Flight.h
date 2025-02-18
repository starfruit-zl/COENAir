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
	vector<Date> bookingDates;
	void dateInput(std::vector<string> &stringStore);

public:
	Flight(string dc = {}, string ac = {}, Date depart = (0, 0, 0, 0, 0, 0), Date arrival = (0, 0, 0, 0, 0, 0), unsigned int d = 0, vector<Passenger> pas = {}, vector<Date> bkd = {});
	Flight(Flight&);
	~Flight();
	string getID();
	string getDepartureCity();
	string getArrivalCity();
	Date getDepartureDate();
	Date getArrivalDate();
	const std::vector<Passenger>* getPassengers();
	const std::vector<Date>* getBookingDates();
	unsigned int getDuration();
	void setDepartureCity(string&);
	void setArrivalCity(string&);
	void setDepartureDate(Date&);
	void setArrivalDate(Date&);
	void setDuration(unsigned int);
	void printFlight(); //prints info of the flight
	void addPassenger(const Passenger&); //adds a passenger to the flight
	void removePassenger(string); //removes a passenger from the flight
	bool searchPassenger(string); //check if a passenger is on flight
	void displayPassengers(); //lists passengers and info
};

#endif // FLIGHT
