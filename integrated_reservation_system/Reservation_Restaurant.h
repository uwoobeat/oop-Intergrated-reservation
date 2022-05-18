#pragma once
#include "Reservation.h"
#include "Auth.h"
#include "User_Restaurant.h"
#include "Schedule_Restaurant.h"

using namespace std;

class Reservation_Restaurant : public Reservation
{
	Auth<User_Restaurant> auth;
	vector<User_Restaurant> users;
	vector<Schedule_Restaurant> schedules;
	vector<User_Restaurant*> walkUsers; //��ũ�� �������� ��� ť. ���̵�� �ο����� �����Ѵ�.
	User_Restaurant currentUser;
	int state = -1;
public:
	void run();
	void book(); //����� ������ ��û ��� �����ؾ� ��
	void show();
	void cancel();
	void quit(); 
	//�Ļ� ���� �� ��⿭ ������ ó���ϴ� �޼���. 
	//���� �� ���� ���� ���� ���� ������ �� �� ��⿭ ���� ���´�.
};

