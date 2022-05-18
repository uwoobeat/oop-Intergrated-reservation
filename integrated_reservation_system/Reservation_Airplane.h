#pragma once
#include <utility>
#include "Reservation.h"
#include "Auth.h"
#include "User_Airplane.h"
#include "Schedule.h"

class Reservation_Airplane : Reservation
{
	Auth<User_Airplane> auth;
	vector<User_Airplane> users; //users 멤버의 경우 배열길이 제한없는 vector 사용이 유리
	vector<Schedule> schedules; //
	User_Airplane currentUser; //현재 로그인된 유저 정보
	int state = -1;
public:
	void run();
	void make_schedules();
	void set_schedule();
	void book();
	void show();
	void cancel();
};