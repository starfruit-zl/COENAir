// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739
//CODE IS NOT AUTHORED BY US, class taken from moodle, as per instructed in assignment. Credits to professor Wahab Hamou-Lhadj.
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