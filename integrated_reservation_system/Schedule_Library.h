#pragma once
#include "Seat_Library.h"

class Schedule_Library
{
	string date = "";
	int time = 0; //9~ 22
	Seat_Library** seats;
public:
	Schedule_Library();
	Schedule_Library(string, int);
	Schedule_Library(const Schedule_Library&);
	~Schedule_Library();
	void set_date(string);
	void set_time(int);
	string get_date();
	int get_time();
	Seat_Library** get_seat();
	void book(string, string, int, int, int);
};

