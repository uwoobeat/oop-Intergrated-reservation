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
	/* getter의 경우 pair중 하나를 택해서 사용하면 되지만, setter는 한 가지 역할만을 수행해야 함 */
};

