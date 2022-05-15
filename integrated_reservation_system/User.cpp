#include "User.h"

/*to-do : setter�� return���� bool���� void�� �ٲٰ�,
�ܼ� ��� �� ��ȿ�� �Ǵ��� book���� ���� ���� �����ϴ� �޼��忡�� �������������� ����*/

bool User::set_name(string name) {
	if (name != "") {
		this->name = name;
		return 1;
	}
	else {
		cout << "�ùٸ� ������ �̸��� �Է��ϼ���.";
		return 0;
	}
}

bool User::set_gender(int gender) {
	if (gender == 1 || gender == 0) {
		this->gender = gender;
		return 1;
	}
	else {
		cout << "�ùٸ� ������ ������ �Է��ϼ���.";
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
		cout << "�ùٸ� ������ ���̸� �Է��ϼ���.";
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