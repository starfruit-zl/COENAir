#include <iostream>

#include "Passenger.h"

int main() {
	std::cout << "Testing the passenger class. Initializing a passenger of the following information, then displaying with print function. It should match the following output: "
		<< "\n\nProfile of passenger 1: \n\tFirst Name: Chelsea\n\tLast Name: Canaan\n\tAddress: 92 Serenity Lane, Manchester, United Kingdom\n\tEmail: chelseacanaan.cc@gmail.com\n";

	Passenger p1("Chelsea", "Canaan", "92 Serenity Lane, Manchester, United Kingdom", "chelseacanaan.cc@gmail.com");
	p1.printPassenger();

	std::cout << "\n\nUsing copy constructor to create a copy. Output should match: ";

	Passenger p1copy(p1);
	p1copy.printPassenger();

	std::cout << "\n\nUsing default constructor, should be blank inputs and 0's apart from ID: ";

	Passenger p2;
	p2.printPassenger();

	std::cout << "\n\nUsing setter functions to change, getter functions to output data. It should match the following output: "
		<< "\n\nProfile of passenger 2: \n\tFirst Name: Martin\n\tLast Name: Truex\n\tAddress: 63 Home Track Road, New Jersey, United States\n\tEmail: mtj.56@gmail.com\n";

	p2.setFirstName("Martin");
	p2.setLastName("Truex");
	p2.setAddress("63 Home Track Road, New Jersey, United States");
	p2.setEmail("mtj.56@gmail.com");

	std::cout << "\nProfile of passenger " + p2.getID() + ": \n\tFirst Name: " + p2.getFirstName() + "\n\tLast Name: " + p2.getLastName() + "\n\tAddress: " + p2.getAddress() + "\n\tEmail: " + p2.getEmail();
}