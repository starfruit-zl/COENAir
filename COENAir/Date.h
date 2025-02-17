// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739
//CODE IS NOT AUTHORED BY US, class taken from moodle, as per instructed in assignment. Credits to professor Wahab Hamou-Lhadj.
#pragma once
#include "Time.h"

#ifndef DATE_H_
#define DATE_H_

class Date { //class taken from moodle, as per instructed in assignment. Credits to professor Wahab Hamou-Lhadj.
public:
	Date(int d = 0, int m = 0, int y = 0, int hour = 0, int min = 0, int sec = 0);   // sets day, month, year, hours, minutes, seconds.
	//added in-line default constructor.
	void printDate() const;   	    // print date to the screen
	
	int getDay(), getMonth(), getYear();

	Time getTime();

private:
	int day, month, year;
	Time time;   // a component object
};

#endif