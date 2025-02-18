#include <iostream>
#include <string>

#include "Date.h"
#include "Flight.h"

using namespace std;

unsigned int Flight::globalID(1);

Flight::Flight(string dc, string ac, Date depart, Date arrival, unsigned int d): departureCity(dc), arrivalCity(ac), departureDate(depart), arrivalDate(arrival), duration(d) {
	unsigned int id = globalID++;
	ID = "COA" + to_string(id); //automatically setting unique ID
	setDuration();
}

Flight::~Flight(){}

Flight::Flight(Flight& F) { //coppy constructor
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
	setDuration();
}

void Flight::setArrivalDate(Date& AD) {
	arrivalDate = AD;
	setDuration();
}

void Flight::setDuration() { //sets duration baced on hours passed
	std::array<int, 12> hoursMonth{ 0, 744, 1416, 2160, 2880, 3624, 4344, 5088, 5832, 6552, 7296, 8016 }; //in order, January to December.
	double hoursDeparture = (departureDate.getYear() * 8760) + hoursMonth[departureDate.getMonth()-1] + (departureDate.getDay() * 24) + departureDate.getTime().getHour() + (departureDate.getTime().getMin() / 60) + (departureDate.getTime().getSecond() / 3600);
	double hoursArrival = (arrivalDate.getYear() * 8760) + hoursMonth[arrivalDate.getMonth()-1] + (arrivalDate.getDay() * 24) + arrivalDate.getTime().getHour() + (arrivalDate.getTime().getMin() / 60) + (arrivalDate.getTime().getSecond() / 3600);
	double timeDifference = hoursArrival - hoursDeparture;
	duration = timeDifference;

	return;
}

void Flight::printFlight() { //prints flight object.
	std::cout << "\n" + ID + ": " + departureCity + " on "; 
	
	departureDate.printDate();

	std::cout << arrivalCity + " on ";

	arrivalDate.printDate();

	return;
}

