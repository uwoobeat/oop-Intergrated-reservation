#pragma once

#include <iostream>

using namespace std;

class Seat
{
	string id;
	string name;
public:
	void set_id(string);
	void set_name(string);
	void cancel();
	bool is_reserved();
	string get_name();
	string get_id();
	/* getter�� ��� pair�� �ϳ��� ���ؼ� ����ϸ� ������, setter�� �� ���� ���Ҹ��� �����ؾ� �� */
};

