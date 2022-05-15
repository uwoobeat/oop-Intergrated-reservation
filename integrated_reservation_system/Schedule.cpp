#include "Schedule.h"
#include <vector>

using namespace std;

Schedule::Schedule() {
	seats = new Seat_Airplane[8];
}

Schedule::~Schedule() {
	delete[] seats;
}

void Schedule::set_date(string date) {
	this->date = date;
}

void Schedule::set_time(int time) {
	if (time >= 0 && time <= 24)
		this->time = time;
	else
		this->time = -1;
}

void Schedule::set_departure(string departure) {
	vector<string> departure_point = {"인천","김포","김해","제주","청주"};
	//출발지는 국내 공항 5군데로 한정함
	for (auto i : departure_point) {
		if (departure == i) {
			this->departure = departure;
			return;
		}
	}
	this->departure = "--";
}

void Schedule::set_arrival(string arrival) {
	this->arrival = arrival;
}

string Schedule::get_date() { return date; }
int Schedule::get_time() { return time; }
string Schedule::get_departure() { return departure; }
string Schedule::get_arrival() { return arrival; }