#include "User.h"

/*to-do : setter�� return���� bool���� void�� �ٲٰ�,
�ܼ� ��� �� ��ȿ�� �Ǵ��� book���� ���� ���� �����ϴ� �޼��忡�� �������������� ����*/

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