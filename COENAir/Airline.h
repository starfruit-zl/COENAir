#pragma once
#include "Flight.h"

#ifndef FLIGHT_H
#define FLIGHT_H

class Airline {
private:
	std::string nameCompany;

	std::string address;

	//array or vector of Flight objects.

public:

	Airline(std::string NC = {}, std::string AD = {}); //also array or vector of Flight objects.

	Airline(Airline&);

	~Airline();

	void setName(std::string NC);

	std::string getName(std::string NC);

	void setAddress(std::string AD);

	std::string getAddress(std::string AD);

	void addFlight(const Flight&);

	void removeFlight(std::string flightID);

	bool searchFlight(std::string flightID);

	void displayFlights();

	void displayFlightsFromTo(std::string departure, std::string destination);

};

#endif