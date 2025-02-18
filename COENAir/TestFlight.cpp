#include <iostream>
#include <string>
#include "Flight.h"

using namespace std;

void testFlight(Flight& F, string id, string dc, string ac, unsigned int d) { //function to test flight object
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
	//test constructor data (dates)
	cout << "\nDate 1:";
	F.getDepartureDate().printDate();
	cout << "\nDate 2:";
	F.getArrivalDate().printDate();
}

int main() {
	//sample testing data
	string dc("here"), ac("there");
	Date D1(1, 2, 3, 1, 2, 3);
	unsigned int d(3);
	Flight F1(dc, ac, D1, D1, d), F2; //inisialising both test objects (using both constructors)
	//testing each object using test function
	cout << "Testing Flight using test data (dates should be 1/2/3 1:2:3 : ";
	testFlight(F1, "COA1", dc, ac, d);
	cout << "\nTesting Flight using test data (dates should be 0/0/0 0:0:0 : ";
	testFlight(F2, "COA2", {}, {}, {});
	return 0;
}