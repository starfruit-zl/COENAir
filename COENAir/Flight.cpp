#include <iostream>
#include <string>

#include "Flight.h"

using namespace std;

unsigned int Flight::globalID(1);

Flight::Flight(string dc, string ac, Date& depart, Date& arrival): departureCity(dc), arrivalCity(ac), departureDate(depart), arrivalDate(arrival) {
	unsigned int id = globalID++;
	ID = "COA" + to_string(id);
}

Flight::~Flight(){}

Flight::Flight(Flight& F) {
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
}

void Flight::setArrivalCity(string& AC) {
	arrivalCity = AC;
}

void Flight::setDepartureDate(Date& DD) {
	departureDate = DD;
}

void Flight::setArrivalDate(Date& AD) {
	arrivalDate = AD;
}

void Flight::setDuration(unsigned int D) {
	duration = D;
}


