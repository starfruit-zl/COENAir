#include "Airline.h"


Airline::Airline(std::string NC, std::string AD, std::vector<Flight> FL) : nameCompany(NC), address(AD), flights(FL) {}

Airline::Airline(const Airline& a1) {
	nameCompany = a1.nameCompany;

	address = a1.address;
}

Airline::~Airline() {
	
}

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
	return address;
}

void Airline::addFlight(const Flight& f1) {

	flights.push_back(f1);
}

void Airline::removeFlight(std::string flightID) {
	
	if(searchFlight(flightID))
		for (int i; i <= flights.size(); i++)
		if (flightID == flights[i].getID()) {
			flights.erase(flights.begin() + i);

			return;
		}

	return;

}

bool Airline::searchFlight(std::string flightID) {

	for (int i; i <= flights.size(); i++)
		if (flightID == flights[i].getID())
			return true;

	return false;
}

void Airline::displayFlights() {
	std::cout << "\n\nFlightID:\tDeparture City:\tDeparture Time:\tArrival City:\tArrival Time:";
	for (int i; i <= flights.size(); i++)
		flights[i].printFlight();
}

void Airline::displayFlightsFromTo(std::string departure, std::string destination) {
	std::cout << "\n\nFlights from " + departure + " to " + destination;

	bool notDisplayed = false;

	for (int i; i <= flights.size(); i++)
		if (flights[i].getDepartureCity() == departure)
			if (flights[i].getArrivalCity() == destination) {
				std::cout << '\n' + flights[i].getID();

				if (notDisplayed) notDisplayed = true;
			}

	if (notDisplayed)std::cout << "\nNo flights are currently available.";
	
	return;
}