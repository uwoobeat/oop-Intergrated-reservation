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
	void sign_up(vector<User>&); //User�� �Ļ� Ŭ�������� Template���� ó��
	pair<string, User&> sign_in(vector<User>&); //id�� users �迭���� ���� �α��� ������ ��ȯ
};