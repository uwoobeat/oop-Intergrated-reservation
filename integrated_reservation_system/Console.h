#pragma once
#include <iostream>

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

//to-do : 다른 데이터 타입이 들오는 등의 예외 처리 기능 추가
//to-do : 데이터 별 유효성 설정 및 검증
//to-do : 일부 데이터의 경우 setter에서 유효성 처리하는 경우 있으므로, 책임 재할당 필요