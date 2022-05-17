#pragma once
#include <queue>
#include "Reservation.h"
#include "Auth.h"
#include "User_Restaurant.h"

class Reservation_Restaurant : public Reservation
{
	Auth<User_Restaurant> auth;
	vector<User_Restaurant> users;
	queue<User_Restaurant> users_walk; //��ũ�� �������� ��� ť
	User_Restaurant currentUser;
	int state = -1;
public:
	void run();
	void book(); //����� ������ ��û ��� �����ؾ� ��
	void show();
	void cancel();
	void quit(); //�Ļ� ���� ��û�� ó���ϴ� �޼���
	//todo : ������ ������ ���� ���� ���� ������ �ϳ��� ���������� ������ �Ѵ�.
};

