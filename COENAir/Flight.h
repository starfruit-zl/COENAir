// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739

#pragma once
#include "Date.h"
#include "Time.h"
#include "Passenger.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifndef FLIGHT
#define FLIGHT
class Flight{
private:
	static unsigned int globalID; //globalID integer to be used in ID management system, ensuring each ID is unique.
	string ID; //string to store ID, beginning in COA for COENAir
	string departureCity; 
	string arrivalCity;
	Date departureDate;
	Date arrivalDate;
	unsigned int duration;
	vector<Passenger> passengers;
	vector<Date> bookingDates;
	void dateInput(std::vector<string> &stringStore);
	void setDuration();

public: //descriptions in .cpp
	Flight();
	Flight(string dc, string ac, Date depart, Date arrival, vector<Passenger> pas, vector<Date> bkd); //default constructor hated having objects set to default nulls, so unique null constructor nescessary.
	~Flight();
	Flight(const Flight&); //added const modifier to make code work, basically it requires the const to adapt to out of scoped returns. Stops re-allocation of memory.
	string getID();
	string getDepartureCity();
	string getArrivalCity();
	Date getDepartureDate();
	Date getArrivalDate();
	std::vector<Passenger> getPassengers();
	std::vector<Date> getBookingDates();
	unsigned int getDuration();
	void setDepartureCity(string&);
	void setArrivalCity(string&);
	void setDepartureDate(Date&);
	void setArrivalDate(Date&);
	void printFlight();
	void addPassenger(Passenger&); //adds a passenger to the flight
	void removePassenger(string); //removes a passenger from the flight
	bool searchPassenger(string); //check if a passenger is on flight
	void displayPassengers(); //lists passengers and info
};

#endif // FLIGHT
