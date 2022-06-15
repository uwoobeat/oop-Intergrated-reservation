#include "Seat_Library.h"

void Seat_Library::set_gender(int gender) {
	if (gender == 0 || gender == 1)
		this->gender = gender;
	else
		this->gender = -1;
}

int Seat_Library::get_gender() { return gender; }