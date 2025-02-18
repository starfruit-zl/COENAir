// Students and their respective ID's: Kieran Alszko, 40314739 and Zachary Lord, 40309150
#pragma once

#include <iostream>
#include <string>
#include <iomanip>

#ifndef PASSENGER
#define PASSENGER

class Passenger {
private:
	static unsigned int globalID;

	std::string ID;

	std::string firstName;

	std::string lastName;

	std::string address;

	std::string email;

	void setID(std::string id);

public:
	Passenger(std::string FN = {}, std::string LN = {}, std::string AD = {}, std::string EM = {}); //constructor for Passenger with in-line defaults.

	Passenger(const Passenger& p1); //copy constructor for passenger.

	~Passenger();

	std::string getID();

	void setFirstName(std::string FN);

	std::string getFirstName();

	void setLastName(std::string LN);

	std::string getLastName();

	void setAddress(std::string AD);

	std::string getAddress();

	void setEmail(std::string EM);

	std::string getEmail();

	void printPassenger();
};

#endif