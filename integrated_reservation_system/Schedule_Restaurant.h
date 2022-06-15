#pragma once
#include <iostream>
#include "Seat_Restaurant.h"

class Schedule_Restaurant
{
	string date;
	string time; //오전, 오후, 저녁
	Seat_Restaurant* seats;
public:
	Schedule_Restaurant();
	Schedule_Restaurant(string, string);
	Schedule_Restaurant(const Schedule_Restaurant&);
	~Schedule_Restaurant();
	void set_date(string);
	void set_time(string);
	string get_date();
	string get_time();
	Seat_Restaurant* get_seat();
	void book(string, string, int);
};

