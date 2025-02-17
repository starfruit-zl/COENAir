// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739

#pragma once
#include "Flight.h"
#include <vector>

#ifndef AIRLINE_H_
#define AIRLINE_H_

class Airline {
private:
	std::string nameCompany; //private string to store company name, formated as such as user or future coder is likely to enter name first.

	std::string address; //private string to store address.

	std::vector<Flight> flights; //private vector of Flight objects to store relevant flights of airline.

public:

	Airline(std::string NC = {}, std::string AD = {}, std::vector<Flight> FL = {}); //

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