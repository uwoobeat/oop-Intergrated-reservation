#pragma once
#include <utility>
#include "Reservation.h"
#include "Auth.h"
#include "User_Airplane.h"
#include "Schedule.h"

class Reservation_Airplane : Reservation
{
	Auth<User_Airplane> auth;
	vector<User_Airplane> users; //users ����� ��� �迭���� ���Ѿ��� vector ����� ����
	vector<Schedule> schedules; //
	User_Airplane currentUser; //���� �α��ε� ���� ����
	int state = -1;
public:
	void run();
	void make_schedules();
	void set_schedule();
	void book();
	void show();
	void cancel();
};