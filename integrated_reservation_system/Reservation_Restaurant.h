#pragma once
#include <queue>
#include "Reservation.h"
#include "Auth.h"
#include "User_Restaurant.h"

class Reservation_Restaurant : public Reservation
{
	Auth<User_Restaurant> auth;
	vector<User_Restaurant> users;
	queue<User_Restaurant> users_walk; //워크인 유저들의 대기 큐
	User_Restaurant currentUser;
	int state = -1;
public:
	void run();
	void book(); //예약과 현장대기 신청 모두 가능해야 함
	void show();
	void cancel();
	void quit(); //식사 종료 요청을 처리하는 메서드
	//todo : 예약이 끝나면 가장 먼저 들어온 팀부터 하나씩 빠져나가는 것으로 한다.
};

