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
	duration = 0; // to be calculated as difference of dates
	passengers = {};
	bookingDates = {};
}

Flight::Flight(string dc, string ac, Date depart, Date arrival, vector<Passenger> pas, vector<Date> bkd): departureCity(dc), arrivalCity(ac), departureDate(depart), arrivalDate(arrival), passengers(pas), bookingDates(bkd) {
	unsigned int id = globalID++;
	ID = "COA" + to_string(id);
	setDuration();
}

Flight::~Flight(){

}

Flight::Flight(const Flight& F) { //copy each private data from inputed Flight to new Flight object.
	ID = F.ID;
	departureCity = F.departureCity;
	arrivalCity = F.arrivalCity;
	departureDate = F.departureDate;
	arrivalDate = F.arrivalDate;
	duration = F.duration;
	passengers = F.passengers;
	bookingDates = F.bookingDates;
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
}

std::vector<Passenger> &Flight::getPassengers() {
	return passengers;
}

std::vector<Date> &Flight::getBookingDates() {
	return bookingDates;
}

// DD/MM/YY HH:MM
void Flight::dateInput(std::vector<string> &stringStore) {
	std::string input;

	switch (stringStore.size()) { //using the size of the string to select input.
	case 2:
		std::getline(std::cin, input, ' '); // after reading YY(space)MM(space), read next DD stopping at ' '.
		break;
	case 3:
		std::getline(std::cin, input, ':'); // after reading YY(space)MM(space)DD(space), read next HH stopping at ':'
		break;
	case 4:
		std::getline(std::cin, input); //after reading YY(space)MM(space)DD(space)MM(space), read next MM stopping at EOF.
		break;
	default:
		std::getline(std::cin, input, '/'); //otherwise, i.e. for YY and MM, stop reading at '/'
		break;
	}
	stringStore.push_back(input); //add a space to retrieved 2 character string, and store to stringStore.

	if (stringStore.size() == 5) return; // once suffieciently sized, return.
	else dateInput(stringStore); //call function recursively, rechecking switch and break.
}


void Flight::printFlight() {
	std::cout << "\n" + ID + ": " + departureCity + " on "; 
	
	departureDate.printDate();

	std::cout << arrivalCity + " on ";

	arrivalDate.printDate();

	return;
}

void Flight::addPassenger(Passenger &pas) {
	passengers.push_back(pas);

	std::vector <string> stringStore;
	std::cout << "\tInput the booking date of following format (DD/MM/YY HH:MM): ";
	dateInput(stringStore);

	Date d1(stoi(stringStore[0]), stoi(stringStore[1]), stoi(stringStore[2]), stoi(stringStore[3]), stoi(stringStore[4]), 0);
	bookingDates.push_back(d1);

	return;
}

void Flight::removePassenger(string id) {
	for (int i(0); i < passengers.size(); i++) {
		if (passengers[i].getID() == id) {
			passengers.erase(passengers.begin() + i);
			bookingDates.erase(bookingDates.begin() + i);
			return;
		}
	}
	cout << "\nNo Passenger found!"; //error messege if no passenger id foind
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
	for (int i(0); i < passengers.size(); i++) { //prints passenger info of all passengers on flight
		passengers.at(i).printPassenger();
		cout << "\nBooked on ";
		bookingDates.at(i).printDate();
		cout << "\n";
	}
	return;
}
