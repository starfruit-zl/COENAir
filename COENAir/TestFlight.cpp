#include <iostream>
#include <string>
#include "Flight.h"

using namespace std;

void testFlight(Flight& F, string id, string dc, string ac, Date& depart, Date& arrival) {
	int error(0);

	if (F.getID() != id) {
		cout << "\nID set error";
		error++;
	}
	if (F.getDepartureCity() != dc) {
		cout << "\nDeparture city set error";
		error++;
	}
	if (F.getArrivalCity() != ac) {
		cout << "\nArrival City set error";
		error++; 
	}
	
}

int main() {
	
	return 0;
}