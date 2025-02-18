#include <iomanip>
#include "Date.h"

Date::Date(int d, int m, int y, int hour, int min, int sec) {
    day = d; //removed print utility used for testing.
    month = m;
    year = y;
    time.setTime(hour, min, sec);
}

void Date::printDate() const {
    cout << std::setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << setw(2) << year << setfill(' ') << " "; //modified print function to fill whitespace with 0's, to match input format.
    time.printTime();
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

Time Date::getTime() {
    return time;
}