#pragma once
#include "Seat.h"

class Seat_Airplane : public Seat
{
	string type;
	int price;
public:
	void set_type(string);
	void set_price(int);
	string get_type();
	int get_price();
};