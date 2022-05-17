#include "Console.h"

string Console::get_auth_id() {
	string id;
	while (1) {
		cout << "���̵� �Է��ϼ��� : ";
		cin >> id;
		if (id == "") {
			cout << "�ùٸ� ������ ���̵� �Է��ϼ���." << '\n';
		}
		else break;
	}
	return id;
}

string Console::get_auth_pw() {
	string pw;
	while (1) {
		cout << "��й�ȣ�� �Է��ϼ��� : ";
		cin >> pw;
		if (pw == "") cout << "�ùٸ� ������ ��й�ȣ�� �Է��ϼ���." << '\n';
		else return pw;
	}
}

string Console::get_user_name() {
	string name;
	while (1) {
		cout << "�̸��� �Է��ϼ��� : ";
		cin >> name;
		if (name == "") cout << "�ùٸ� ������ �̸��� �Է��ϼ���." << '\n';
		else return name;
	}
}

int Console::get_user_gender() {
	int gender;
	while (1) {
		cout << "������ �Է��ϼ��� (���� 1, ���� 0) : ";
		cin >> gender;
		if (!(gender == 1 || gender == 0)) cout << "�ùٸ� ������ ������ �Է��ϼ���." << '\n';
		else return gender;
	}
}

int Console::get_user_age() {
	int age;
	while (1) {
		cout << "���̸� �Է��ϼ��� : ";
		cin >> age;
		if (!(age >= 1 && age <= 150)) cout << "�ùٸ� ������ ���̸� �Է��ϼ���." << '\n';
		else return age;
	}
}