#include "Reservation_Airplane.h"

using namespace std;

//�����ڿ��� Schedule ��ü ���� ���� �� getter ȣ���Ͽ� ��������� ��
//-> ���� ����ϹǷ� �ʿ����

void Reservation_Airplane::run() {
	cout << "�Ѽ��װ��� ���� ���� ȯ���մϴ�." << "\n\n";

	cout << "�α����� �����մϴ�." << '\n';
	cout << "�Ѽ��װ� ���̵� �ִٸ� 1, �ƴ϶�� 0�� �����ּ���." << '\n';
	cin >> state; //todo : 0,1 �� ���� ó��
	
	if (state == 0)
		auth.sign_up(users);
	currentUser = auth.sign_in(users);

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
			cout << "���α׷� ����";
			exit(1);
		default:
			cout << "�ùٸ��� ���� �Է°��Դϴ�.";
		}
	}
}

void Reservation_Airplane::book() {
	cout << "������ �����մϴ�." << '\n';
	
	cout << "";
}

void Reservation_Airplane::show() {
	cout << "���� �������� �����ݴϴ�." << '\n';
}

void Reservation_Airplane::cancel() {
	cout << "���� ������ ����մϴ�." << '\n';
}