#pragma once

#include <iostream>

using namespace std;

class Seat
{
	string id;
	string name;
public:
	void set_id_name(string, string);
	void cancel();
	bool is_reserved();
	pair<string, string> get_id_name();
};

