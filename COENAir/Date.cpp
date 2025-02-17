
#include "Date.h"

Date::Date(int d, int m, int y, int hour, int min, int sec) {
    day = d; //removed print utility used for testing.
    month = m;
    year = y;
    time.setTime(hour, min, sec);
}

void Date::printDate() const {
    cout << day << "/" << month << "/" << year << " ";
    time.printTime();
}