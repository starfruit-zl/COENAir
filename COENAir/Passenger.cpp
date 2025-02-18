// Students and their respective ID's: Kieran Alszko, 40314739 and Zachary Lord, 40309150
#include "Passenger.h"

unsigned int Passenger::globalID(1); //define start point as 1 of ID management system. Static property allows sharing within the class context privately, ensures used ID is unique outside of copies.

Passenger::Passenger(std::string FN, std::string LN, std::string AD, std::string EM) : firstName(FN), lastName(LN), address(AD), email(EM) {

	ID = std::to_string(globalID++);
}

Passenger::Passenger(const Passenger& p1) {
	ID = p1.ID;

	firstName = p1.firstName;

	lastName = p1.lastName;

	address = p1.address;

	email = p1.email;
}

Passenger::~Passenger() {
	//use defaults provided by compiler.
}

void Passenger::setID(std::string id) { //setters set the private data ID to the inputed string id
	ID = id;
	return;
}

std::string Passenger::getID() {
	return ID;
}

void Passenger::setFirstName(std::string FN) {
	firstName = FN;

	return;
}

std::string Passenger::getFirstName() {
	return firstName;
}

void Passenger::setLastName(std::string LN) {
	lastName = LN;

	return;
}

std::string Passenger::getLastName() {
	return lastName;
}

void Passenger::setAddress(std::string AD) {
	address = AD;

	return;
}

std::string Passenger::getAddress() {
	return address;
}

void Passenger::setEmail(std::string EM) {
	email = EM;

	return;
}

std::string Passenger::getEmail() {
	return email;
}

void Passenger::printPassenger() { //prints the private data of the defined Passenger object
	std::cout << "\nProfile of passenger " + ID + ": \n\tFirst Name: " + firstName + "\n\tLast Name: " + lastName + "\n\tAddress: " + address + "\n\tEmail: " + email;

	return;
}