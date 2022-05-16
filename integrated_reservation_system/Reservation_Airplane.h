#pragma once
#include "Reservation.h"
#include "Auth.h"
#include "User_Airplane.h"
#include "Schedule.h"

class Reservation_Airplane : public Reservation
{
	static Auth<User_Airplane> auth;
	vector<User_Airplane> users; //users ����� ��� �迭���� ���Ѿ��� vector ����� ����
	vector<Schedule> schedules; //schedules�� ���
	int state = -1;
public:
	void run();
	virtual void book();
	virtual void show();
	virtual void cancel();
};