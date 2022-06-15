#pragma once
#include <iostream>

using namespace std;

class User {
	string id;
	string name;
	int gender = -1; //0은 여자, 1은 남자
	int age = -1;
	int reservedCount = 0;
public:
	void set_id(string);
	void set_name(string);
	void set_gender(int);
	void set_age(int);
	void add_reservedCount();
	string get_id();
	string get_name();
	int get_gender();
	int get_age();
	int get_reservedCount();
};