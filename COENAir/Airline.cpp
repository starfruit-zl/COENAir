#include "Airline.h"


Airline::Airline(std::string NC = {}, std::string AD = {}) {} //also array or vector of Flight objects.

Airline::Airline(Airline& a1) {
	nameCompany = a1.nameCompany;

	address = a1.address;
}

Airline::~Airline();

void Airline::setName(std::string NC) {
	nameCompany = NC;

	return;
}

std::string Airline::getName() {
	return nameCompany;
}

void Airline::setAddress(std::string AD) {
	address = AD;

	return;
}

std::string Airline::getAddress() {
	return getAddress;
}

void Airline::addFlight(const Flight&);

void Airline::removeFlight(std::string flightID);

bool Airline::searchFlight(std::string flightID);

void Airline::displayFlights();

void Airline::displayFlightsFromTo(std::string departure, std::string destination);