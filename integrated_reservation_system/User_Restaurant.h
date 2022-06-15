#pragma once
#include "User.h"


class User_Restaurant : public User
{
	int size;
	bool isWalk = false; //워크인 고객 여부 확인
	int queue = 0; //워크인 대기열 고객의 대기열 순번. 워크인이 아니라면 0
public:
	void set_size(int);
	void set_isWalk(bool);
	void set_queue(int);
	int get_size();
	bool get_isWalk();
	int get_queue();
};

