#pragma once
#include <iostream>

using namespace std;

class User {
	string name = "";
	int gender; //0은 여자, 1은 남자
	int age;
public:
	bool set_name(string);
	bool set_gender(int);
	bool set_age(int);
	string get_name();
	int get_gender();
	int get_age();
};