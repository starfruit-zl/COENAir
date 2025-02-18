// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739

#include <iostream>
#include <string>
#include "Date.h"
#include <array>

#include "Flight.h"

using namespace std;

unsigned int Flight::globalID(1); //start count of ID as 1.

Flight::

Flight::Flight() {
	Date d1; //initialize null instance of Date object.
	unsigned int id = globalID++; //unique ID, increments after each usage.
	ID = "COA" + to_string(id); //convert int to string, add COA to it and store as ID.
	departureCity = {}; //null declaration
	arrivalCity = {}; //null declaration
	departureDate = d1; //default Object copied to departure and arrival dates.
	arrivalDate = d1;
	duration = 0; // to be calculated as difference of dates.
}

Flight::Flight(string dc, string ac, Date &depart, Date &arrival): departureCity(dc), arrivalCity(ac), departureDate(depart), arrivalDate(arrival) {
	unsigned int id = globalID++;
	ID = "COA" + to_string(id);
	setDuration();
}

Flight::~Flight(){
	std::cout << "\tRemoving flight " + ID + " from system."; //message to confirm destructor in use.
}

Flight::Flight(const Flight& F) { //copy each private data from inputed Flight to new Flight object.
	ID = F.ID;
	departureCity = F.departureCity;
	arrivalCity = F.arrivalCity;
	departureDate = F.departureDate;
	arrivalDate = F.arrivalDate;
	duration = F.duration;
}

string Flight::getID() { //getters return private data.
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

void Flight::setDepartureCity(string& DC) { //setters set inputted string to private data.
	departureCity = DC;

	return;
}

void Flight::setArrivalCity(string& AC) {
	arrivalCity = AC;

	return;
}

void Flight::setDepartureDate(Date& DD) {
	departureDate = DD;
	setDuration();
	
	return;
}

void Flight::setArrivalDate(Date& AD) {
	arrivalDate = AD;
	setDuration();
	
	return;
}

void Flight::setDuration() {
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
