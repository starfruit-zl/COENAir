#pragma once

#ifndef TIME_H_
#define TIME_H_
// Students and their respective ID's: Zachary Lord, 40309150 and Kieran Alszko, 40314739
//CODE IS NOT AUTHORED BY US.
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