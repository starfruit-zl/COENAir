#include <iostream>
#include <sstream>
#include <string>
#include "Airline.h"

using namespace std;

void dateInput(std::string&, std::string&);

Flight initializeFlight();

int main() {
	
	bool running = true;

	short int selection;

	std::string input, input2;

	std::vector<Flight> flights;
	//Flight(string dc, string ac, unsigned int d, Date& depart, Date& arrival)
	Date d1(28, 10, 25, 12, 15, 0), d2(29, 10, 25, 8, 6, 0);
	flights.push_back(Flight("Montreal", "Amsterdam", 180, d1, d2));

	Airline COENAir("COENAir", "1616 Saint-Catherine Street West, Montreal", flights);

	std::cout << "Welcome to the " + COENAir.getName() + " management terminal. We are located at " + COENAir.getAddress() + ", please contact us if any system issues arise." 
		<< "\nPlease review the following selections, and have a COEN time!!!";

	while (running) {

		std::cout << "\n\n\t1.Register New Flight\n\t2.Remove Flight from List\n\t3.Check flight status.\n\t4.Display Upcoming Flights.\n\t5.Search Flights by Trajectory\n\t6.Exit Search.\nEnter your selection: ";
		std::cin >> selection;
		switch (selection) {
		case 1:
			COENAir.addFlight(initializeFlight());
			break;
		case 2:
			std::cout << "\n\tPlease input the ID of the flight you'd like to remove: ";
			std::cin >> input;
			COENAir.removeFlight(input);
			break;
		case 3:
			std::cout << "\n\tPlease input the ID of the flight you'd like to check: ";
			std::cin >> input;
			if (COENAir.searchFlight(input)) std::cout << "\nYour flight is awaiting departure";
			else std::cout << "\nYour flight is not currently registered in our database. Please check by later.";
			break;
		case 4:
			COENAir.displayFlights();
			break;
		case 5:
			std::cout << "\n\tPlease input the departure and arrival destinations of interest, seperated by an arrowhead > : ";
			std::cin.ignore();
			std::getline(std::cin, input, '>');
			std::getline(std::cin, input2);
			COENAir.displayFlightsFromTo(input, input2);
			break;
		case 6:
			std::cout << "\nThank you for consulting COENAir, exiting now...";
			running = false;
			break;
		}
	}

	return 0;
}

// YY MM DD HH MM 
void dateInput(std::string& stringStore) {
	std::string input;

	switch (stringStore.size()) {
	case 6: 
		std::getline(std::cin, input, ' ');
		break;
	case 9:
		std::getline(std::cin, input, ':');
		break;
	case 12:
		std::getline(std::cin, input);
		break;
	default:
		std::getline(std::cin, input, '/');
		break;
	}
	stringStore += input + " ";

	if (stringStore.size() == 15) return;
	else dateInput(stringStore);
}

Flight initializeFlight() {

	short unsigned int capacity;
	string input;
	std::vector<std::string> stringStore, dateStore;

	std::cout << "\nPlease enter the relevant flight parameters:\n\tDeparture city: ";
	std::cin >> input;
	stringStore.push_back(input);
	std::cout << "\tDeparture time of the following format (MM/DD/YY HH:MM): ";
	std::cin.ignore();
	dateInput(input = {});
	stringStore.push_back(input);
	std::cout << "\tDestination city : ";
	std::cin >> input;
	stringStore.push_back(input);
	while (true) {
		std::cout << "\tArrival time of the following format (MM/DD/YY HH:MM): ";
		std::cin.ignore();
		dateInput(input = {});
		stringStore.push_back(input);
		if (stringStore[1] > stringStore[3]) {
			std::cout << "Error: cannot arrive at destination before you depart.\n";
			continue;
		}
		break;
	}
	while (true) {
		std::cout << "\tCapacity of flight: ";
		std::cin >> capacity;
		if (capacity < 520 && capacity > 0) break;
		else {
			std::cout << "Error: invalid capacity, must range between 520 (Airbus A380) and 0.\n";
			continue;
		}
	}

	std::istringstream date1(stringStore[1]), date2(stringStore[3]); //uses istringstream to be able to grab elements from a single string separately, using it as a vector functionally.

	for (int i = 0; i < 5; i++) {
		getline(date1, input, ' ');
		dateStore.push_back(input);
	}
	Date d1(stoi(dateStore[0]), stoi(dateStore[1]), stoi(dateStore[2]), stoi(dateStore[3]), stoi(dateStore[4]), 0);
	dateStore = {};
	for (int i = 0; i < 5; i++) {
		getline(date2, input, ' ');
		dateStore.push_back(input);
	}
	Date d2(stoi(dateStore[0]), stoi(dateStore[1]), stoi(dateStore[2]), stoi(dateStore[3]), stoi(dateStore[4]), 0);
	dateStore = {};

	Flight f1(stringStore[0], stringStore[2], capacity, d1, d2);
	
	stringStore = {};
	input = {};

	return Flight(f1);
}