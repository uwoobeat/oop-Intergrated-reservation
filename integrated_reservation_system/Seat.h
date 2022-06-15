#pragma once

#include <iostream>

using namespace std;

class Seat
{
	string id = "";
	string name = "";
	int reservedCount = 0;
public:
	void set_id(string);
	void set_name(string);
	void cancel();
	void add_reservedCount();
	bool is_reserved();
	string get_name();
	string get_id();
	int get_reservedCount();
	/* getter�� ��� pair�� �ϳ��� ���ؼ� ����ϸ� ������, setter�� �� ���� ���Ҹ��� �����ؾ� �� */
};

