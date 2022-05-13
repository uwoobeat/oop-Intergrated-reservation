#include "Auth.h"

bool Auth::sign_up() {
	string userID;
	string userPW;
	cout << "���̵� �Է��ϼ��� : ";
	cin >> userID;

	if (userID == "") {
		cout << "�ùٸ� ������ ���̵� �Է��ϼ���." << '\n';
		return 0;
	}

	if (user_auth_map.count(userID)) {
		cout << "�̹� �����ϴ� ���̵��Դϴ�." << '\n';
		return 0;
	}
	else {
		cout << "��й�ȣ�� �Է��ϼ��� : ";
		cin >> userPW;

		if (userPW == "") {
			cout << "�ùٸ� ������ ��й�ȣ�� �Է��ϼ���." << '\n';
			return 0;
		}

		user_auth_map[userID] = userPW;
		cout << "���������� ������ ����߽��ϴ�." << '\n';
		return 1;
	}
}

pair<bool, string> Auth::sign_in() {
	string userID;
	string userPW;
	cout << "���̵� �Է��ϼ��� : ";
	cin >> userID;
	cout << "��й�ȣ�� �Է��ϼ��� : ";
	cin >> userPW;

	auto it = user_auth_map.find(userID);
	if (it != user_auth_map.end()) {
		cout << "�α��ο� �����߽��ϴ�." << '\n';
		return make_pair(true, userID);
	}
	else {
		cout << "��Ȯ�� ���̵�� �н����带 �Է����ּ���." << '\n';
		return make_pair(false, "");
	}
}