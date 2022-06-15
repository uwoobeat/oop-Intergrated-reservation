#pragma once
#include "Reservation.h"
#include "Auth.h"
#include "User_Library.h"
#include "Schedule_Library.h"
#include <iostream>

using namespace std;

class Reservation_Library : public Reservation
{
	Auth<User_Library> auth;
	vector<User_Library> users;
	vector<Schedule_Library> schedules;
	User_Library currentUser;
	Schedule_Library currentSchedule;
	int state = -1;
public:
	Reservation_Library();
	void run();
	void book();
	void show();
	void cancel();
	void set_current(string, int);
	void show_stat();
};