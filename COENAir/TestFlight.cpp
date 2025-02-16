#include <iostream>
#include <string>
#include <vector>
#include "Passenger.h"
#include "Flight.h"

using namespace std;

void testFlight(Flight& F, string id, string dc, string ac, unsigned int d, vector<Passenger> pas) {
	Passenger pas3("Gerald", "Hemsworth", "419 Street street", "ghemsworth@gmail.com");
	int pass(pas.size());
	if (F.getID() != id) {
		cout << "\nID set error";
	}
	if (F.getDepartureCity() != dc) {
		cout << "\nDeparture city set error";
	}
	if (F.getArrivalCity() != ac) {
		cout << "\nArrival City set error";
	}
	if (F.getDuration() != d) {
		cout << "\nDuration set error";
	}
	cout << "\nDate 1:";
	F.getDepartureDate().printDate();
	cout << "\nDate 2:";
	F.getArrivalDate().printDate();
	
	cout << "\nTestting passengers (Fist list should have " << pass << " passengers and second should have " << (pass + 1) << "):";
	F.displayPassengers();
	F.addPassenger(pas3);
	F.displayPassengers();
}

int main() {
	Passenger pas1("Bob", "Marley", "68th street", "bob@gmail.com"), pas2("Arneld", "Shworts", "70th street", "arneld.s@gmail.com");
	vector<Passenger> pas{pas1, pas2};
	string dc("here"), ac("there");
	Date D1(1, 2, 3, 1, 2, 3);
	unsigned int d(3);
	Flight F1(dc, ac, D1, D1, d, pas), F2;
	cout << "Testing Flight using test data (dates should be 1/2/3 1:2:3 : ";
	testFlight(F1, "COA1", dc, ac, d, pas);
	cout << "\nTesting Flight using test data (dates should be 0/0/0 0:0:0 : ";
	testFlight(F2, "COA2", {}, {}, {}, vector<Passenger> {});
	return 0;
}