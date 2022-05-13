#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Auth
{
	map<string, string> user_auth_map;
public:
	bool sign_up();
	pair<bool, string> sign_in(); //로그인 성공 여부와 아이디 반환
};