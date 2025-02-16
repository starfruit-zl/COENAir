#include "Date.h"
#include "Passenger.h"
#include "Flight.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned int Flight::globalID(1);

Flight::Flight(string dc, string ac, Date depart, Date arrival, unsigned int d, vector<Passenger> pas): departureCity(dc), arrivalCity(ac), departureDate(depart), arrivalDate(arrival), duration(d),passengers(pas) {
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

void Flight::addPassenger(const Passenger& pas) {
	passengers.push_back(pas);
}

void Flight::removePassenger(string id) {
	for (int i(0); i < passengers.size(); i++) {
		if (passengers[i].getID() == id) {
			passengers.erase(passengers.begin() + i);
			return;
		}
	}
	cout << "\nNo Passenger found!";
	return;

}

bool Flight::searchPassenger(string id) {
	for (int i(0); i < passengers.size(); i++) {
		if (passengers[i].getID() == id)
			return true;
	}
	return false;
}

void Flight::displayPassengers() {
	cout << "\nPassengers on flight " + ID + ":\n";
	for (int i(0); i < passengers.size(); i++) {
		passengers[i].printPassenger();
		cout << "\n";
	}
	return;
}