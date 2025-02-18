// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739

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
	static unsigned int globalID; //globalID integer to be used in ID management system, ensuring each ID is unique.
	string ID; //string to store ID, beginning in COA for COENAir
	string departureCity; 
	string arrivalCity;
	Date departureDate; //object of type Date storing parameters related to departure date.
	Date arrivalDate; //object of type Date storing parameters related to departure date.
	unsigned int duration; //duration is not signed.

public: //descriptions in .cpp
	Flight();
	Flight(string dc, string ac, Date& depart, Date& arrival); //default constructor hated having objects set to default nulls, so unique null constructor nescessary.
	~Flight();
	Flight(const Flight&); //added const modifier to make code work, basically it requires the const to adapt to out of scoped returns. Stops re-allocation of memory.
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
	void setDuration();
	void printFlight();
};

#endif // FLIGHT
