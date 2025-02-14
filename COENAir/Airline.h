#pragma once
#include "Flight.h"
#include <vector>

#ifndef AIRLINE_H_
#define AIRLINE_H_

class Airline {
private:
	std::string nameCompany;

	std::string address;

	std::vector<Flight> flights;

public:

	Airline(std::string NC = {}, std::string AD = {}, std::vector<Flight> FL = {}); //also array or vector of Flight objects.

	Airline(const Airline&);

	~Airline();

	void setName(std::string NC);

	std::string getName();

	void setAddress(std::string AD);

	std::string getAddress();

	void addFlight(const Flight&);

	void removeFlight(std::string flightID);

	bool searchFlight(std::string flightID);

	void displayFlights();

	void displayFlightsFromTo(std::string departure, std::string destination);

};

#endif