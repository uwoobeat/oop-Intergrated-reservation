#pragma once
#include <iostream>

using namespace std;

class User {
	string name = "";
	int gender; //0�� ����, 1�� ����
	int age;
public:
	bool set_name(string);
	bool set_gender(int);
	bool set_age(int);
	string get_name();
	int get_gender();
	int get_age();
};