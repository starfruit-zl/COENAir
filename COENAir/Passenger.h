#pragma once
/*Q2. (15 points) Write a class called Passenger that represents the passengers of
CoenAir. A passenger has an id (string), first name (string), last name (string), address
(string), and email (string). The class should have one or more constructors, accessing
functions, a copy constructor, a destructor, a function that prints information about a
passenger. Write a driver to test the Passenger class.
Deliverables: A zip file that contains three files: Passenger.h, Passenger.cpp,
TestPassenger.cpp*/

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