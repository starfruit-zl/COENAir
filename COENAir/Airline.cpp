// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739

#include "Airline.h"
#include <iomanip>


Airline::Airline(std::string NC, std::string AD, std::vector<Flight> FL) : nameCompany(NC), address(AD), flights(FL) {} //list declaration of inputed strings and vectors to private data.

Airline::Airline(const Airline& a1) { //copy all private data.
	nameCompany = a1.nameCompany;

	address = a1.address;

	flights = a1.flights;
}

Airline::~Airline() { //destructor.
	
}

void Airline::setName(std::string NC) { //setters set private data to inputted data.
	nameCompany = NC;

	return;
}

std::string Airline::getName() { //getters return private data.
	return nameCompany;
}

void Airline::setAddress(std::string AD) {
	address = AD;

	return;
}

std::string Airline::getAddress() {
	return address;
}

void Airline::addFlight(const Flight& f1) { //add Flight object to vector flights.

	flights.push_back(f1);
}

void Airline::removeFlight(std::string flightID) { //remove Flight from vector flights.


		for (int i = 0; i < flights.size(); i++) //for instances of objects Flight in flights.
		if (flightID == flights[i].getID()) { //if ID's are a match
			flights.erase(flights.begin() + i); //erase the found Flight object

			return; //exit
		}

	std::cout << "\nError: Could not find the ID";

	return;
}

bool Airline::searchFlight(std::string flightID) {

	for (int i = 0; i < flights.size(); i++) //for instances of objects Flight in flights.
		if (flightID == flights[i].getID()) //if ID's are a match
			return true;

	return false;
}

void Airline::displayFlights() { //flight board style display
	std::cout << "\n\nFlightID:\tDeparture City:\tDeparture Time:\tArrival City:\tArrival Time:\tDuration (in hours):"; //add duration?
	for (int i = 0; i < flights.size(); i++) { //loop to print flight in specified format.
		std::cout <<'\n' << flights[i].getID() << std::setw(20) << flights[i].getDepartureCity()  << setw(6) << " ";
		flights[i].getDepartureDate().printDate(); //use modified print function with fills for departure date.
		std::cout << std::setw(10) << flights[i].getArrivalCity() << std::setw(6) << " ";
		flights[i].getArrivalDate().printDate();
		std::cout << std::setw(8) << flights[i].getDuration();
	}

	return;
}

void Airline::displayFlightsFromTo(std::string departure, std::string destination) {
	std::cout << "\n\nFlights from " + departure + " to " + destination;

	bool notDisplayed = true; //bool to confirm that despite common return point, different exit message will occur if there are no flights that fit.
	//this is done as there may be multiple flights between two destinations.
	for (int i = 0; i < flights.size(); i++) //for flights vector
		if (flights[i].getDepartureCity() == departure) //if at index i, destination in put matches private data
			if (flights[i].getArrivalCity() == destination) {// and arrival matches private data.
				std::cout << '\n' + flights[i].getID(); //output ID's in rows.

				if (notDisplayed) notDisplayed = false; //set bool to false, as there are flights now displayed.
			}

	if (notDisplayed)std::cout << "\nNo flights are currently available."; //print if there are no flights displayed.
	
	return;
}