#pragma once
#include "User.h"


class User_Restaurant : public User
{
	int size;
	bool isWalk = false; //��ũ�� �� ���� Ȯ��
	int queue = 0; //��ũ�� ��⿭ ���� ��⿭ ����. ��ũ���� �ƴ϶�� 0
public:
	void set_size(int);
	void set_isWalk(bool);
	void set_queue(int);
	int get_size();
	bool get_isWalk();
	int get_queue();
};

