#include "Schedule_Library.h"
#include <iostream>
#include <vector>

Schedule_Library::Schedule_Library() {
	seats = new Seat_Library* [15];
	for (int i = 0; i < 15; i++) {
		seats[i] = new Seat_Library[15];
	}
}

Schedule_Library::Schedule_Library(string date, int time) : Schedule_Library() {
	this->date = date;
	this->time = time;
}

Schedule_Library::Schedule_Library(const Schedule_Library& s) {
	this->date = s.date;
	this->time = s.time;
	this->seats = new Seat_Library * [15];
	for (int i = 0; i < 15; i++) {
		seats[i] = new Seat_Library[15];
		for (int j = 0; j < 15; j++)
			seats[i][j] = s.seats[i][j];
	}
}

Schedule_Library::~Schedule_Library() {
	for (int i = 0; i < 15; i++)
		delete[] seats[i];
	delete[] seats;
}

void Schedule_Library::set_date(string date) {
	this->date = date;
}

void Schedule_Library::set_time(int time) {
	if (time >= 9 && time <= 22)
		this->time = time;
	else
		this->time = 0;
}

string Schedule_Library::get_date() { return date; }
int Schedule_Library::get_time() { return time; }
Seat_Library** Schedule_Library::get_seat() { return seats; }

void Schedule_Library::book(string id, string name, int gender, int row, int col) {
	seats[row][col].set_id(id);
	seats[row][col].set_name(name);
	seats[row][col].set_gender(gender);
	seats[row][col].add_reservedCount();
}