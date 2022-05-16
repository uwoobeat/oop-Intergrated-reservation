#pragma once
#include "Reservation.h"
#include "Auth.h"
#include "User_Airplane.h"
#include "Schedule.h"

class Reservation_Airplane : public Reservation
{
	static Auth<User_Airplane> auth;
	vector<User_Airplane> users; //users 멤버의 경우 배열길이 제한없는 vector 사용이 유리
	vector<Schedule> schedules; //schedules의 경우
	int state = -1;
public:
	void run();
	virtual void book();
	virtual void show();
	virtual void cancel();
};