#pragma once

#include <iostream>
#include <utility>

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
	pair<string, string> get_id_name();
	/* getter�� ��� pair�� �ϳ��� ���ؼ� ����ϸ� ������, setter�� �� ���� ���Ҹ��� �����ؾ� �� */
};

