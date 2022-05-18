#pragma once
#include "User.h"
class User_Airplane : public User
{
	int mileage = 0;
	bool isOneWay = 1; //편도면 true, 왕복이면 false
public:
	void set_mileage(int);
	void set_isOneWay(bool);
	int get_mileage();
	bool get_isOneWay();
};
