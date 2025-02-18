// Students and their respective ID's: Kieran Alszko, 40314739 and Zachary Lord, 40309150
#pragma once

#ifndef TIME_H_
#define TIME_H_

#include <iostream>
using namespace std;

class Time { //class taken from moodle, as per instructed in assignment. Credits to professor Wahab Hamou-Lhadj.
public:
	void setTime(int h = 0, int = 0, int = 0);
	void printTime() const;
	double getHour(), getMin(), getSecond();

private:
	int hour, minute, second;
};


#endif