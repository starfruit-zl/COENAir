// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739
//CODE IS NOT AUTHORED BY US, class taken from moodle, as per instructed in assignment. Credits to professor Wahab Hamou-Lhadj.
#include "Time.h"
#include <iostream>
#include <iomanip>

void Time::setTime(int h, int m, int s) {
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::printTime() const {
    cout << std::setfill('0') << setw(2) << hour << ":" << setw(2) << minute << ":" << setw(2) << second << std::setfill(' '); //removed endl portion, modified to include 0's as fill to match input format.
}

double Time::getHour() {
    return hour;
}

double Time::getMin() {
    return minute;
}

double Time::getSecond() {
    return second;
}