// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739

#include <iostream>
#include <sstream>
#include <string>
#include "Airline.h"

using namespace std;

void dateInput(std::string&, std::string&); //function to read the specified date input used by the initializeFlight() function.

Flight initializeFlight(); //initializes a new instance of flight based off user input and adds it to the flights vector of the Airline class.

int main() {
	
	bool running = true; //bool that controls the while loop containing switch-break function, allows for indefinite repetition until otherwise requested.

	short int selection; //selection input.

	std::string input, input2;

	std::vector<Flight> flights; //default flight vector.
	//Flight(string dc, string ac, unsigned int d, Date& depart, Date& arrival)
	Date d1(28, 10, 25, 12, 15, 0), d2(29, 10, 25, 8, 6, 0);
	flights.push_back(Flight("Montreal", "Amsterdam", d1, d2)); //flight pre-defined using direct input constructor.

	Airline COENAir("COENAir", "1616 Saint-Catherine Street West, Montreal", flights); //defining COENAir airline including address and flights vector.

	std::cout << "Welcome to the " + COENAir.getName() + " management terminal. We are located at " + COENAir.getAddress() + ", please contact us if any system issues arise." 
		<< "\nPlease review the following selections, and have a COEN time!!!"; //demonstrating getter functions for airline.

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
			if (COENAir.searchFlight(input)) std::cout << "\nYour flight is awaiting departure"; //meaning that flight will appear on display flights.
			else std::cout << "\nYour flight is not currently registered in our database. Please check by later."; //meaning that flight was not found.
			break;
		case 4:
			COENAir.displayFlights();
			break;
		case 5:
			std::cout << "\n\tPlease input the departure and arrival destinations of interest, separated by an arrowhead > : ";
			std::cin.ignore();
			std::getline(std::cin, input, '>'); //receives first destination, stopping at '>' character.
			std::getline(std::cin, input2); //receives second destination, stopping at EOF
			COENAir.displayFlightsFromTo(input, input2);
			break;
		case 6:
			std::cout << "\nThank you for consulting COENAir, exiting now...";
			running = false; //set to false, disabling while loop.
			break;
		}
	}

	return 0;
}

// YY MM DD HH MM 
void dateInput(std::string& stringStore) {
	std::string input;

	switch (stringStore.size()) { //using the size of the string to select input.
	case 6: 
		std::getline(std::cin, input, ' '); // after reading YY(space)MM(space), read next DD stopping at ' '.
		break;
	case 9:
		std::getline(std::cin, input, ':'); // after reading YY(space)MM(space)DD(space), read next HH stopping at ':'
		break;
	case 12:
		std::getline(std::cin, input); //after reading YY(space)MM(space)DD(space)MM(space), read next MM stopping at EOF.
		break;
	default:
		std::getline(std::cin, input, '/'); //otherwise, i.e. for YY and MM, stop reading at '/'
		break;
	}
	stringStore += input + " "; //add a space to retrieved 2 character string, and store to stringStore.

	if (stringStore.size() == 15) return; // once suffieciently sized, return.
	else dateInput(stringStore); //call function recursively, rechecking switch and break.
}

Flight initializeFlight() {

	string input; //string to store input.
	std::vector<std::string> stringStore, dateStore; //vectors to store strings for input to flight function.

	std::cout << "\nPlease enter the relevant flight parameters:\n\tDeparture city: ";
	std::cin >> input;
	stringStore.push_back(input); //add departure city to vector.
	std::cout << "\tDeparture time of the following format (DD/MM/YY HH:MM): ";
	std::cin.ignore();
	dateInput(input = {}); //call dateInput with empty string.
	stringStore.push_back(input); //add departure date to vector.
	std::cout << "\tDestination city : ";
	std::cin >> input;
	stringStore.push_back(input); //add arrival city to vector.
	while (true) { //while loop to confirm function.
		std::cout << "\tArrival time of the following format (DD/MM/YY HH:MM): ";
		std::cin.ignore();
		dateInput(input = {});
		stringStore.push_back(input); //add arrival date to vector.
		if (stringStore[1] > stringStore[3]) { //check if arrival date is before departure date.
			std::cout << "Error: cannot arrive at destination before you depart.\n";
			stringStore.pop_back(); //remove date from vector.
			continue;
		}
		else break;
	}

	std::istringstream date1(stringStore[1]), date2(stringStore[3]); //uses istringstream to be able to grab elements from a single string separately, using it as a vector functionally.

	for (int i = 0; i < 5; i++) { //using input from buffer date1, grab elements one at a time and store in dateStore vector.
		getline(date1, input, ' ');
		dateStore.push_back(input);
	}
	Date d1(stoi(dateStore[0]), stoi(dateStore[1]), stoi(dateStore[2]), stoi(dateStore[3]), stoi(dateStore[4]), 0); //inititalize date object with values from vector.
	dateStore = {}; //reset dateStore vector to null.
	for (int i = 0; i < 5; i++) { //repeat process for arrival date.
		getline(date2, input, ' ');
		dateStore.push_back(input);
	}
	Date d2(stoi(dateStore[0]), stoi(dateStore[1]), stoi(dateStore[2]), stoi(dateStore[3]), stoi(dateStore[4]), 0);
	dateStore = {};

	Flight f1(stringStore[0], stringStore[2], d1, d2); //constructor inititalization of new flight object.
	
	stringStore = {};
	input = {};

	return Flight(f1);
}