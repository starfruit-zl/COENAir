// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739

#include <iostream>
#include <sstream>
#include <string>
#include "Airline.h"

using namespace std;



void dateInput(std::string&, std::string&); //function to read the specified date input used by the initializeFlight() function.

Flight initializeFlight(); //initializes a new instance of flight based off user input and adds it to the flights vector of the Airline class.
Passenger  initializePassenger(); //initializes a new instance of Passenger based off user input and adds it to the global passengers vector, as well as the passengers
//vector of the specified flight.

int main() {
	
	bool running = true; //bool that controls the while loop containing switch-break function, allows for indefinite repetition until otherwise requested.

	short int selection, flightPos, passPos; //selection input.
	
	char answer;

	std::string input, input2, flightID;

	std::vector<Flight> flights; //default flight vector.

	Date d1(28, 10, 25, 12, 15, 0), d2(29, 10, 25, 8, 6, 0), dp1(28, 10, 25, 12, 0, 0), dp2(10, 10, 25, 23, 35, 0), dp3(19, 5, 24, 6, 18, 0), dp4(11, 7, 24, 8, 6, 0), dp5(18, 2, 25, 7, 10, 0);
	std::vector<Date> bookingDate{ dp1, dp2, dp3, dp4, dp5 };

	Passenger p1("Chelsea", "Canaan", "92 Serenity Lane, Manchester, United Kingdom", "chelseacanaan.cc@gmail.com"), p2("Martin", "Truex", "63 Home Track Road, New Jersey, United States", "mtj.56@gmail.com"),
		p3("Gerald", "Hemsworth", "419 Street street", "ghemsworth@gmail.com"), p4("Bob", "Marley", "68th street", "bob@gmail.com"), p5("Arneld", "Shworts", "70th street", "arneld.s@gmail.com");

	std::vector<Passenger> passenger{ p1, p2, p3, p4 ,p5 };//"global/registered" system passengers, corresponds to the unique instances of Passenger in the
	//private passengers vector for all Flight objects in the private flights vector.

	Flight defaultFlight("Montreal", "Amsterdam", d1, d2, passenger, bookingDate);
	flights.push_back(defaultFlight); //flight pre-defined using direct input constructor.

	Flight selectFlight;

	Airline COENAir("COENAir", "1616 Saint-Catherine Street West, Montreal", flights); //defining COENAir airline including address and flights vector.

	std::cout << "Welcome to the " + COENAir.getName() + " management terminal. We are located at " + COENAir.getAddress() + ", please contact us if any system issues arise." 
		<< "\nPlease review the following selections, and have a COEN time!!!"; //demonstrating getter functions for airline.

	while (running) {

		std::cout << "\n\n\t1.Register New Flight\n\t2.Remove Flight from List\n\t3.Check flight status\n\t4.Display Upcoming Flights\n\t5.Search Flights by Trajectory\n\t6.Access Passenger Interface\n\t7.Exit Search\nEnter your selection: ";
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
			else std::cout << "\nYour flight is not currently registered in our database. Please check by later."; //meaning that flight was not found
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
			std::cout << "\nEnter the flightID you wish to interact with: ";
			std::cin >> input;

			for (int i = 0; i < COENAir.getFlights().size(); i++) { //for the flights vector in airline.
				if (input == COENAir.getFlights().at(i).getID()) { //if ID is found.
					flightPos = i; //select this specific flights index.
					break; //escape
				}
				if (i == COENAir.getFlights().size() - 1) {//else, when about to move out of range.
					std::cout << "The inputed passenger could not be found inside the system. Please try again: ";
					i = 0; //reset count
					std::cin >> input;//re-request input
					continue; //repeat for loop.
				}
			}

			std::cout << "Please review the following Passenger interactions:\n\n\t1.Add Passenger to Flight\n\t2.Remove Passenger from Flight\n\t3.Check if Passenger has Booked Flight\n\t4.Display Booking Information\nEnter your selection: ";
			std::cin >> selection;
			switch (selection) { //switch case for selection.
			case 1:
				std::cout << "\nIs the passenger already registered in the system?(y/n): "; 
				std::cin >> answer;
				switch (answer) { //switch case of char for different adding modes (none vs pre-existing.)
				case 'n': {
					Passenger pas1 = initializePassenger();
					COENAir.addPassengerToFlight(flightPos,pas1); //utilising class hierarchy to access private data with member functions.
					passenger.push_back(pas1);
					break;
				}
				case 'y':
					std::cout << "Enter the passengerID: ";
					for (int i = 0; i < passenger.size(); i++) {
						std::cin >> input;
						if (input == passenger.at(i).getID()) {
							passPos = i;
							COENAir.addPassengerToFlight(flightPos, passenger.at(passPos)); //call member function that adds Passenger to flight for Passenger in
							// "public" passenger vector.
							break;
						}
						if (i == passenger.size() - 1) { //else, when about to move out of range.
							std::cout << "The inputed passenger could not be found inside the system. Please try again: ";
							i = 0;
							std::cin >> input;
							continue;
						}
					}
					break;
				}
				break;//allow for reusing of passengers, if not initialize new.
			case 2:
				std::cout << "\nEnter the passengerID you wish to remove from the flight: ";
				std::cin >> input;

				for (int i = 0; i < COENAir.getFlights().at(flightPos).getPassengers().size(); i++) { //for the vector passengers
					if (input == COENAir.getFlights().at(flightPos).getPassengers().at(i).getID()) { //if ID at index i of passenger matches input
						COENAir.removePassengerFromFlight(flightPos, input); //remove Passenger with this ID, new member function similar to addPassengerToFlight
						break;
					}
					if (i == COENAir.getFlights().at(flightPos).getPassengers().size() - 1) //else, when about to move out of scope
						std::cout << "Could not find the requested Passenger."; //error message.
				}
				break;
			case 3: //these can function with scoped copies, so no need for new member functions.
				std::cout << "\nEnter the passengerID you wish to check for: ";
				std::cin >> input;

				if (COENAir.getFlights().at(flightPos).searchPassenger(input)) std::cout << "Reservation confirmed, the skies await you.";
				else std::cout << "Passenger not registered for this flight.";
				break;
			case 4: //these can function with scoped copies, so no need for new member functions.
				COENAir.getFlights().at(flightPos).displayPassengers();
				break;
			}
			break;
		case 7:
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

	vector<Passenger> temp1{};
	vector<Date> temp2{};

	Flight f1(stringStore[0], stringStore[2], d1, d2, temp1, temp2); //constructor inititalization of new flight object.
	
	stringStore = {};
	input = {};

	return Flight(f1);
}

Passenger initializePassenger() {
	std::vector<string> stringStore;
	std::string input;

	std::cout << "\nEnter the first name of the passenger: ";
	std::cin >> input;
	stringStore.push_back(input);

	std::cout << "Enter the last name of the passenger: ";
	std::cin >> input;
	stringStore.push_back(input);
	//FN, LN, AD, EM

	std::cout << "Enter the address of the passenger: ";
	std::cin.ignore();
	std::getline(std::cin, input);
	stringStore.push_back(input);

	std::cout << "Enter the email of the passenger: ";
	std::cin >> input;
	stringStore.push_back(input);

	return Passenger(stringStore[0], stringStore[1], stringStore[2], stringStore[3]);
}