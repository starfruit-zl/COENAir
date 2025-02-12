#include <iostream>
#include <string>

#include "Flight.h"

using namespace std;

Flight::Flight(string id, string dc, string ac, Date depart, Date arrival): ID(id), departureCity(dc), arrivalCity(ac), departureDate(depart), arrivalDate(arrival) {}

Flight::~Flight(){}

