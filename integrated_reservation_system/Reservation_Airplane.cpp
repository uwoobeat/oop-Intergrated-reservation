#include "Reservation_Airplane.h"

using namespace std;

//�����ڿ��� Schedule ��ü ���� ���� �� getter ȣ���Ͽ� ��������� ��
//-> ���� ����ϹǷ� �ʿ����

void Reservation_Airplane::run() {
	cout << "�Ѽ��װ��� ���� ���� ȯ���մϴ�." << "\n\n";

	cout << "�α����� �����մϴ�." << '\n';
	cout << "�Ѽ��װ� ���̵� �ִٸ� 1, �ƴ϶�� 0�� �����ּ���." << '\n';
	cin >> state; //todo : 0,1 �� ���� ó��
	
	if (state == 0) {
		auth.sign_up(users);
	}
	/*
	if (state == 0) {
		while (1)
			if (auth->sign_up()) {
				break;
			}
	}
	while (1) {
		pair<bool, string> isSignedUp_ID = auth->sign_in();
		if (isSignedUp_ID.first) {
			this.id = isSignedUp_ID.second;
			break;
		}
	}
	*/

	state = 0;

	while (1) {
		switch (state) {
		case 0:
			cout << "����:1, ���:2, ����:3, ������:4 >> ";
			cin >> state;
			break;
		case 1:
			book();
			break;
		case 2:
			cancel();
			break;
		case 3:
			show();
			break;
		case 4:
			cout << "���Ż�� ������";
			exit(1);
		default:
			cout << "�ùٸ��� ���� �Է°��Դϴ�.";
		}
	}
}

void Reservation_Airplane::book() {
}

void Reservation_Airplane::show() {
	cout << "������ �����մϴ�." << '\n';
}

void Reservation_Airplane::cancel() {

}