#pragma once
#include "User.h"
class User_Airplane : public User
{
	int mileage;
	bool isOneWay; //���� true, �պ��̸� false
public:
	void set_mileage(int);
	void set_isOneWay(bool);
	int get_mileage();
	bool get_isOneWay();
};
