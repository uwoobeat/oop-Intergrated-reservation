#include "Schedule_Restaurant.h"
#include <vector>

Schedule_Restaurant::Schedule_Restaurant() {
	seats = new Seat_Restaurant[8];

	for (int i = 0; i < 8; i++) {
		if (i == 0 || i == 1) {
			seats[i].set_size(6);
			seats[i].set_isWalk(false);
		}
		else if (i == 2 || i == 3) {
			seats[i].set_size(4);
			if (i == 3) seats[i].set_isWalk(false);
			else seats[i].set_isWalk(true);
		}
		else if (i == 4 || i == 5) {
			seats[i].set_size(2);
			if (i == 4) seats[i].set_isWalk(false);
			else seats[i].set_isWalk(true);
		}
		else {
			seats[i].set_size(1);
			if (i == 6) seats[i].set_isWalk(false);
			else seats[i].set_isWalk(true);
		}
	}

	/*
	6��(�����) * 2
	4��(�����) * 1, 4��(�湮��) * 1
	2��(�����) * 1, 2��(�湮��) * 1
	1��(�����) * 1, 1��(�湮��) * 1
	*/
}

Schedule_Restaurant::Schedule_Restaurant(string date, string time) {
	this->date = date;
	this->time = time;
}

Schedule_Restaurant::~Schedule_Restaurant() {
	delete[] seats;
}

void Schedule_Restaurant::set_date(string date) {
	this->date = date;
}

void Schedule_Restaurant::set_time(string time) {
	if (time == "����" || time == "����" || time == "����")
		this->time = time;
	else
		this->time = "";
}

string Schedule_Restaurant::get_date() { return date; }
string Schedule_Restaurant::get_time() { return time; }
Seat_Restaurant* Schedule_Restaurant::get_seat() { return seats; }

void Schedule_Restaurant::book(string id, string name, int seatNum) {
	seats[seatNum].set_id(id);
	seats[seatNum].set_name(name);
}
