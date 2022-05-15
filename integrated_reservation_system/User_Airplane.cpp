#include "User_Airplane.h"

void User_Airplane::set_mileage(int mileage) {
	if (mileage >= 0)
		this->mileage = mileage;
	else
		this->mileage = -1;
}

void User_Airplane::set_isOneWay(bool isOneWay) {
	this->isOneWay = isOneWay;
}

int User_Airplane::get_mileage() { return mileage; }
bool User_Airplane::get_isOneWay() { return isOneWay; }