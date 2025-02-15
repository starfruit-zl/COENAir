#include <iostream>
#include <string>
#include "Date.h"

#include "Flight.h"

using namespace std;

unsigned int Flight::globalID(1);

Flight::

Flight::Flight() {
	Date d1;
	unsigned int id = globalID++;
	ID = "COA" + to_string(id);
	departureCity = {};
	arrivalCity = {};
	departureDate = d1;
	arrivalDate = d1;
	duration = 0;
}

Flight::Flight(string dc, string ac, unsigned int d, Date &depart, Date &arrival): departureCity(dc), arrivalCity(ac), departureDate(depart), arrivalDate(arrival), duration(d) {
	unsigned int id = globalID++;
	ID = "COA" + to_string(id);
}

Flight::~Flight(){}

Flight::Flight(const Flight& F) {
	ID = F.ID;
	departureCity = F.departureCity;
	arrivalCity = F.arrivalCity;
	departureDate = F.departureDate;
	arrivalDate = F.arrivalDate;
	duration = F.duration;
}

string Flight::getID() {
	return ID;
}

string Flight::getDepartureCity() {
	return departureCity;
}

string Flight::getArrivalCity() {
	return arrivalCity;
}

Date Flight::getDepartureDate() {
	return departureDate;
}

Date Flight::getArrivalDate() {
	return arrivalDate;
}

unsigned int Flight::getDuration() {
	return duration;
}

void Flight::setDepartureCity(string& DC) {
	departureCity = DC;

	return;
}

void Flight::setArrivalCity(string& AC) {
	arrivalCity = AC;

	return;
}

void Flight::setDepartureDate(Date& DD) {
	departureDate = DD;

	return;
}

void Flight::setArrivalDate(Date& AD) {
	arrivalDate = AD;

	return;
}

void Flight::setDuration(unsigned int D) {
	duration = D;

	return;
}

void Flight::printFlight() {
	std::cout << "\n" + ID + ": " + departureCity + " on "; 
	
	departureDate.printDate();

	std::cout << arrivalCity + " on ";

	arrivalDate.printDate();

	return;
}
