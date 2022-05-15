#include "User.h"

/*to-do : setter의 return형을 bool에서 void로 바꾸고,
콘솔 출력 및 유효성 판단은 book같은 여러 동작 수행하는 메서드에서 절차지향적으로 구현*/

bool User::set_name(string name) {
	if (name != "") {
		this->name = name;
		return 1;
	}
	else {
		cout << "올바른 형식의 이름을 입력하세요.";
		return 0;
	}
}

bool User::set_gender(int gender) {
	if (gender == 1 || gender == 0) {
		this->gender = gender;
		return 1;
	}
	else {
		cout << "올바른 형식의 성별을 입력하세요.";
		this->gender = -1;
		return 0;
	}
}

bool User::set_age(int age) {
	if (age >= 1 && age <= 150) {
		this->age = age;
		return 1;
	}
	else {
		cout << "올바른 형식의 나이를 입력하세요.";
	}
}

string User::get_name() {
	return name;
}

int User::get_gender() {
	return gender;
}

int User::get_age() {
	return age;
}