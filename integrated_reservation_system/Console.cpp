#include "Console.h"

string Console::get_auth_id() {
	string id;
	while (1) {
		cout << "아이디를 입력하세요 : ";
		cin >> id;
		if (id == "") {
			cout << "올바른 형식의 아이디를 입력하세요." << '\n';
		}
		else break;
	}
	return id;
}

string Console::get_auth_pw() {
	string pw;
	while (1) {
		cout << "비밀번호를 입력하세요 : ";
		cin >> pw;
		if (pw == "") cout << "올바른 형식의 비밀번호를 입력하세요." << '\n';
		else return pw;
	}
}

string Console::get_user_name() {
	string name;
	while (1) {
		cout << "이름을 입력하세요 : ";
		cin >> name;
		if (name == "") cout << "올바른 형식의 이름을 입력하세요." << '\n';
		else return name;
	}
}

int Console::get_user_gender() {
	int gender;
	while (1) {
		cout << "성별을 입력하세요 (남자 1, 여자 0) : ";
		cin >> gender;
		if (!(gender == 1 || gender == 0)) cout << "올바른 형식의 성별을 입력하세요." << '\n';
		else return gender;
	}
}

int Console::get_user_age() {
	int age;
	while (1) {
		cout << "나이를 입력하세요 : ";
		cin >> age;
		if (!(age >= 1 && age <= 150)) cout << "올바른 형식의 나이를 입력하세요." << '\n';
		else return age;
	}
}