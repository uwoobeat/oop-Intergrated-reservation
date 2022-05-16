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
	/* getter의 경우 pair중 하나를 택해서 사용하면 되지만, setter는 한 가지 역할만을 수행해야 함 */
};

