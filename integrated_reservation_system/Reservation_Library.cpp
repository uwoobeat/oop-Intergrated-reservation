#include "Reservation_Library.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

Reservation_Library::Reservation_Library() {
	for (int i = 220501; i <= 220507; i++)
		for (int j = 9; j <= 22; j++)
			schedules.push_back(Schedule_Library(to_string(i), j));
}

void Reservation_Library::run() {
	cout << "T�� �����ǿ� ���� ���� ȯ���մϴ�." << "\n\n";

	cout << "���� ���̵� �ִٸ� 1, �ƴ϶�� 0�� �Է��ϼ���. (���� ���̵�� 1~300 ������ ����) : ";
	cin >> state;
	cout << '\n';

	if (state == 0)
		auth.sign_up(users);
	currentUser = auth.sign_in(users);

	state = 0;

	while (1) {
		switch (state) {
		case 0:
			cout << "����:1, ���:2, ����:3, ���:4, ������:5 >> ";
			cin >> state;
			cout << endl;
			break;
		case 1:
			book();
			state = 0;
			break;
		case 2:
			cancel();
			state = 0;
			break;
		case 3:
			show();
			state = 0;
			break;
		case 4:
			show_stat();
			state = 0;
			break;
		case 5:
			cout << "���α׷� ����" << "\n\n";
			return;
		default:
			cout << "�ùٸ��� ���� �Է°��Դϴ�.";
			state = 0;
		}
	}
}

void Reservation_Library::book() {
	string date;
	int time;
	int row = 0;
	int col = 0;


	if (currentUser.get_age() <= 13) {
		cout << "13�� ���� ��̴� ������ �Ұ����մϴ�.";
		return;
	}

	if (currentUser.get_totTime() >= 4) {
		cout << "�� ���� �ð��� 4�ð��� ���� �� �����ϴ�.";
		return;
	}

	cout << "������ �����մϴ�." << "\n\n";

	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;

	cout << "���� ���� �ð��� �Է��ϼ���. 1�ð� ������ ������ �����մϴ�. (9 ~ 23) : ";
	cin >> time;

	set_current(date, time);
	auto p = currentSchedule.get_seat();

	cout << date << "����" << " " << time << "���� ���� ��Ȳ�Դϴ�." << "\n\n";
	cout << "* ���� ������ �����Ͽ� ���� �� �����ϴ�." << "\n";
	cout << "** �¼�ǥ�� �� ������ �ʴ´ٸ� �ܼ�â�� Ȯ�����ּ���." << "\n\n";

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (p[i][j].is_reserved()) {
				string gstr;
				if (p[i][j].get_gender() == 1) gstr = "(��)";
				else if (p[i][j].get_gender() == 0) gstr = "(��)";
				cout << setw(7) << right << p[i][j].get_name() << setw(5) << left << gstr;
			}
			else {
				cout << setw(3) << "" << setw(6) << "------" << setw(3) << "";
			}
		}
		cout << "\n";
	}

	cout << "\n";

	cout << "�¼��� ��ġ�� ���� �Է����ּ���. : ";
	cin >> row; row--;

	cout << "�¼��� ��ġ�� ���� �Է����ּ���. : ";
	cin >> col; col--;

	if (p[row][col].is_reserved()) {
		cout << "�̹� ����� �¼��Դϴ�." << "\n\n";
		return;
	}
	
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	bool isSameGenderAdjacent = false; //���� ��ġ�� ���� ������ �����ϴ��� Ȯ��

	for (auto x : dx) {
		for (auto y : dy) {
			int nx = col; int ny = row;
			nx += x; ny += y;
			if (nx >= 0 && nx <= 14 && ny >= 0 && ny <= 14) { //�ε��� �ʰ����� �ʴ� ���� ������ �����¿� Ȯ��
				if (p[ny][nx].is_reserved() && currentUser.get_gender() == p[ny][nx].get_gender())
					isSameGenderAdjacent = true;
			}
		}
	}

	if (isSameGenderAdjacent) {
		cout << "���� ������ ������ �ڸ��� ������ �� �����ϴ�." << "\n\n";
		return;
	}
	else {
		currentSchedule.book(currentUser.get_id(), currentUser.get_name(), currentUser.get_gender(), row, col);
		currentUser.add_totTIme();
		currentUser.add_time(date, time);
		currentUser.add_reservedCount();
		if (currentUser.get_gender() == 1) this->maleReservedCount++;
		else if (currentUser.get_gender() == 0) this->femaleReservedCount++;
		cout << "������ ���������� �Ϸ�Ǿ����ϴ�." << "\n\n";
	}
}

void Reservation_Library::show() {
	string date;
	int time;

	cout << "���� ���� ��Ȳ�� �����ݴϴ�." << "\n";

	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;

	cout << "���� ���� �ð��� �Է��ϼ���. 1�ð� ������ ������ �����մϴ�. (9 ~ 23) : ";
	cin >> time;

	set_current(date, time);
	auto p = currentSchedule.get_seat();


	cout << '\n' << date << "����" << " " << time << "���� ���� ��Ȳ�Դϴ�." << "\n\n";
	cout << "* ���� ������ �����Ͽ� ���� �� �����ϴ�." << "\n";
	cout << "** �¼�ǥ�� �� ������ �ʴ´ٸ� �ܼ�â�� Ȯ�����ּ���." << "\n\n";

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (p[i][j].is_reserved()) {
				string gstr;
				if (p[i][j].get_gender() == 1) gstr = "(��)";
				else if (p[i][j].get_gender() == 0) gstr = "(��)";
				cout << setw(7) << right << p[i][j].get_name() << setw(5) << left << gstr;
			}
			else {
				cout << setw(3) << "" << setw(6) << "------" << setw(3) << "";
			}
		}
		cout << "\n";
	}


	cout << "\n";
}

void Reservation_Library::cancel() {
	string date;
	int time;
	int row;
	int col;

	cout << "������ ����մϴ�." << '\n';

	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;

	cout << "���� ���� �ð��� �Է��ϼ���. (9 ~ 23) : ";
	cin >> time;

	cout << "�¼��� ��ġ�� ���� �Է����ּ���. : ";
	cin >> row; row--;

	cout << "�¼��� ��ġ�� ���� �Է����ּ���. : ";
	cin >> col; col--;

	set_current(date, time);
	auto p = currentSchedule.get_seat();

	if (p[row][col].get_id() == currentUser.get_id() && p[row][col].is_reserved()) {
		p[row][col].cancel();
		cout << "������ ���������� ��ҵǾ����ϴ�." << "\n\n";
	}
	else {
		cout << "���� ������� ���� ������ �ƴϰų�, ���� ������ �������� �ʴ� �¼��Դϴ�." << "\n\n";
	}
}

void Reservation_Library::set_current(string date, int time) {
	for (auto& i : schedules)
		if (i.get_date() == date && i.get_time() == time)
			currentSchedule = i;
}

void Reservation_Library::show_stat() {
	string date;
	int time;

	cout << "��� ��Ȳ�� �����ݴϴ�." << "\n\n";

	cout << "���� �α��ε� ���� ���� Ƚ�� : " << this->maleReservedCount + this->femaleReservedCount << '\n';
	cout << "���� ������ ���� Ƚ�� : " << this->maleReservedCount << '\n';
	cout << "���� ������ ���� Ƚ�� : " << this->femaleReservedCount << '\n';


	cout << "�¼� �� ���� Ƚ���� �����ݴϴ�." << "\n";
	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;
	cout << "���� ���� �ð��� �Է��ϼ���. (9 ~ 23) : ";
	cin >> time;

	set_current(date, time);
	auto p = currentSchedule.get_seat();

	cout << date << "����" << " " << time << "���� �¼� �� ���� Ƚ���Դϴ�." << "\n\n";

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << p[i][j].get_reservedCount() << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}