#pragma once
#include <iostream>

using namespace std;

class User {
	string id;
	string name;
	int gender; //0�� ����, 1�� ����
	int age;
public:
	void set_id(string);
	void set_name(string);
	void set_gender(int);
	void set_age(int);
	string get_id();
	string get_name();
	int get_gender();
	int get_age();
};