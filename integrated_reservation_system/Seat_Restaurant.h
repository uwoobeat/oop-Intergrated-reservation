#pragma once
#include "Seat.h"
class Seat_Restaurant : public Seat
{
	int size = 0;
	bool isWalk = 0;
public:
	void set_size(int);
	void set_isWalk(bool);
	int get_size();
	bool get_isWalk();
};

