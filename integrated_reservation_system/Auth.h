#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

template <typename User>
class Auth
{
	static map<string, string> user_auth_map;
public:
	void sign_up(vector<User>&); //User의 파생 클래스들을 Template으로 처리
	pair<string, typename vector<User>::iterator> sign_in();
};