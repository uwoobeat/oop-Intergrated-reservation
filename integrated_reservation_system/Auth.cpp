#include "Auth.h"

bool Auth::sign_up() {
	string userID;
	string userPW;
	cout << "아이디를 입력하세요 : ";
	cin >> userID;

	if (userID == "") {
		cout << "올바른 형식의 아이디를 입력하세요." << '\n';
		return 0;
	}

	if (user_auth_map.count(userID)) {
		cout << "이미 존재하는 아이디입니다." << '\n';
		return 0;
	}
	else {
		cout << "비밀번호를 입력하세요 : ";
		cin >> userPW;

		if (userPW == "") {
			cout << "올바른 형식의 비밀번호를 입력하세요." << '\n';
			return 0;
		}

		user_auth_map[userID] = userPW;
		cout << "성공적으로 계정을 등록했습니다." << '\n';
		return 1;
	}
}

pair<bool, string> Auth::sign_in() {
	string userID;
	string userPW;
	cout << "아이디를 입력하세요 : ";
	cin >> userID;
	cout << "비밀번호를 입력하세요 : ";
	cin >> userPW;

	auto it = user_auth_map.find(userID);
	if (it != user_auth_map.end()) {
		cout << "로그인에 성공했습니다." << '\n';
		return make_pair(true, userID);
	}
	else {
		cout << "정확한 아이디와 패스워드를 입력해주세요." << '\n';
		return make_pair(false, "");
	}
}