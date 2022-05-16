#include "User.h"

/*to-do : setter의 return형을 bool에서 void로 바꾸고,
콘솔 출력 및 유효성 판단은 book같은 여러 동작 수행하는 메서드에서 절차지향적으로 구현*/

void User::set_id(string id) {
	this->id = id;
}

void User::set_name(string name) {
	this->name = name;
}

void User::set_gender(int gender) {
	if (gender == 1 || gender == 0)
		this->gender = gender;
	else
		this->gender = -1;
}

void User::set_age(int age) {
	if (age >= 1 && age <= 150) 
		this->age = age;
	else 
		this->age = -1;
}

string User::get_id() {
	return id;
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