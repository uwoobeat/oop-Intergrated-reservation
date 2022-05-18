#include "Seat_Airplane.h"

void Seat_Airplane::set_type(string type) {
	if (type != "B" && type != "E") 
		this->type = "";
	else 
		this->type = type;
}

void Seat_Airplane::set_price(int price) {
	if (price <= 0) 
		this->price = 0;
	else 
		this->price = price;
}

string Seat_Airplane::get_type() {
	return type;
}

int Seat_Airplane::get_price() {
	return price;
}