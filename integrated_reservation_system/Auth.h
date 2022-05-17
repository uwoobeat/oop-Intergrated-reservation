#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include "Console.h"

using namespace std;

template <typename User>
class Auth
{
	map<string, string> user_auth_map;
public:
	void sign_up(vector<User>&); //User의 파생 클래스들을 Template으로 처리
	User& sign_in(vector<User>&); //id와 users 배열에서 현재 로그인 참조자 반환
};

//클래스 템플릿 사용 시 선언부와 구현부를 분리하면 링킹 에러 발생. 따라서 헤더 파일로 묶어야 함

template <typename User>
void Auth<User>::sign_up(vector<User>& user_data) {
	//유저 배열 users의 참조자를 인자로 받아서 신규 회원정보를 등록하는 함수
	string userID;
	string userPW;
	User user = User();

	cout << "회원가입을 시작합니다." << '\n';

	//Authentication begin

	while (1) {
		userID = Console::get_auth_id();
		if (user_auth_map.count(userID)) {
			cout << "이미 존재하는 아이디입니다." << '\n';
		}
		else {
			userPW = Console::get_auth_pw();
			break;
		}
	}

	user_auth_map[userID] = userPW; //user_auth_map에 아이디-비밀번호 쌍 등록

	//Authentication end
	//Authorization begin

	user.set_id(userID);
	user.set_name(Console::get_user_name());
	user.set_gender(Console::get_user_gender());
	user.set_age(Console::get_user_age());

	user_data.push_back(user);
	//신규 user 객체를 생성하여 설정해주고, users 벡터에 push_back 해줌

	cout << "회원가입을 성공적으로 완료하였습니다." << '\n' << '\n';
	//Authorization end
}

template <typename User>
User& Auth<User>::sign_in(vector<User>& user_data) {
	string userID;
	string userPW;

	cout << "로그인을 시작합니다." << '\n';

	//Authentication begin

	while (1) {
		userID = Console::get_auth_id();
		userPW = Console::get_auth_pw();
		auto it = user_auth_map.find(userID);
		if (it != user_auth_map.end()) {
			if (it->first == userID && it->second == userPW)
				break;
		}
		cout << "입력한 정보가 존재하지 않습니다." << '\n';
	}

	//Authentication end
	//Authorization begin

	for (auto& user : user_data) {
		if (user.get_id() == userID)
			cout << "로그인을 성공적으로 완료하였습니다." << '\n' << '\n';
			return user; //아이디와 users에서 해당 아이디의 user 객체 반환
	}

	//Authorization end
}