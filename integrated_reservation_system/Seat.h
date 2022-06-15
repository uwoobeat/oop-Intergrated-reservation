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
	/* getter의 경우 pair중 하나를 택해서 사용하면 되지만, setter는 한 가지 역할만을 수행해야 함 */
};

