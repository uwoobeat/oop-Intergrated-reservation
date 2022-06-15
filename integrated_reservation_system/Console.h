#pragma once
#include <iostream>
#include <string>

using namespace std;

class Console
{
public:
	static string get_auth_id();
	static string get_auth_pw();
	static string get_user_name();
	static int get_user_gender();
	static int get_user_age();
};