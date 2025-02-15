#pragma once

#ifndef TIME_H_
#define TIME_H_

#include <iostream>
using namespace std;

class Time { //class taken from moodle, as per instructed in assignment. Credits to professor Wahab Hamou-Lhadj.
public:
	void setTime(int h = 0, int = 0, int = 0);
	void printTime() const;

private:
	int hour, minute, second;
};

#endif