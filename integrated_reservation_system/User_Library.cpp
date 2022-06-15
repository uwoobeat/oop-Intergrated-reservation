#include "User_Library.h"
#include <vector>
#include <utility>

using namespace std;

void User_Library::set_totTime(int totTime) {
	this->totTime = totTime;
}

void User_Library::add_totTIme() {
	this->totTime++;
}

void User_Library::add_time(string date, int time) {
	if (time >= 9 && time <= 22)
		times.push_back(make_pair(date, time));
}

void User_Library::remove_time(string date, int time) {
	for (auto i = times.begin(); i != times.end(); i++)
		if (i->first == date && i->second == time)
			times.erase(i);
}

int User_Library::get_totTime() { return totTime; }
vector<pair<string, int>>& User_Library::get_times() { return times; }