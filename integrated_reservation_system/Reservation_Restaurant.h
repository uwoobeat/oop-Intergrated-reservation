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
	vector<User_Restaurant*> walkUsers; //워크인 유저들의 대기 큐. 아이디와 인원수를 저장한다.
	User_Restaurant currentUser;
	int state = -1;
public:
	void run();
	void book(); //예약과 현장대기 신청 모두 가능해야 함
	void show();
	void cancel();
	void quit(); 
	//식사 종료 및 대기열 순번을 처리하는 메서드. 
	//실행 시 가장 먼저 들어온 팀이 나가고 맨 앞 대기열 팀이 들어온다.
};

