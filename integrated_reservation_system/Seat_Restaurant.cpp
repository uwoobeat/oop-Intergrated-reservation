#include "Seat_Restaurant.h"
#include <iostream>

using namespace std;

void Seat_Restaurant::set_size(int size) {
	if (size > 0)
		this->size = size;
	else
		this->size = -1;
}

void Seat_Restaurant::set_isWalk(bool isWalk) {
	this->isWalk = isWalk;
}


int Seat_Restaurant::get_size() {
	return size;
}

bool Seat_Restaurant::get_isWalk() {
	return isWalk;
}