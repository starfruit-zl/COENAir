#include "Date.h"
#include "Passenger.h"
#include "Flight.h"
#include <array>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

unsigned int Flight::globalID(1);

Flight::Flight(string dc, string ac, Date depart, Date arrival, unsigned int d, vector<Passenger> pas, vector<Date> bkd): departureCity(dc), arrivalCity(ac), departureDate(depart), arrivalDate(arrival), duration(d),passengers(pas), bookingDates(bkd){
	unsigned int id = globalID++;
	ID = "COA" + to_string(id);
	setDuration();
}

Flight::~Flight(){}

Flight::Flight(Flight& F) {
	ID = F.ID;
	departureCity = F.departureCity;
	arrivalCity = F.arrivalCity;
	departureDate = F.departureDate;
	arrivalDate = F.arrivalDate;
	duration = F.duration;
	passengers = F.passengers;
	bookingDates = F.bookingDates;
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
	double hoursDeparture = (departureDate.getYear() * 8760) + hoursMonth[departureDate.getMonth() - 1] + (departureDate.getDay() * 24) + departureDate.getTime().getHour() + (departureDate.getTime().getMin() / 60) + (departureDate.getTime().getSecond() / 3600);
	double hoursArrival = (arrivalDate.getYear() * 8760) + hoursMonth[arrivalDate.getMonth() - 1] + (arrivalDate.getDay() * 24) + arrivalDate.getTime().getHour() + (arrivalDate.getTime().getMin() / 60) + (arrivalDate.getTime().getSecond() / 3600);
	double timeDifference = hoursArrival - hoursDeparture;
	duration = timeDifference;

	return;
}

std::vector<Passenger>* Flight::getPassenger() {
	return &passengers;
}

std::vector<Date>* Flight::getBookingDates() {
	return &bookingDates;
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

void Flight::addPassenger(const Passenger& pas) {
	passengers.push_back(pas);

	std::vector <string> stringStore;
	std::cout << "\tDeparture time of the following format (DD/MM/YY HH:MM): ";
	dateInput(stringStore);

	bookingDates.push_back(Date(stoi(stringStore[0]), stoi(stringStore[1]), stoi(stringStore[2]), stoi(stringStore[3]), stoi(stringStore[4])));
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
		passengers[i].printPassenger();
		cout << "\n";
	}
	return;
}