#include "Reservation_Airplane.h"
#include "Schedule.h"
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//�����ڿ��� Schedule ��ü ���� ���� �� getter ȣ���Ͽ� ��������� ��
//-> ���� ����ϹǷ� �ʿ����

void Reservation_Airplane::run() {
	set_schedules();

	cout << "�Ѽ��װ��� ���� ���� ȯ���մϴ�." << "\n\n";

	cout << "�Ѽ��װ� ���̵� �ִٸ� 1, �ƴ϶�� 0�� �����ּ��� : ";
	cin >> state; //todo : 0,1 �� ���� ó��
	cout << endl;
	
	if (state == 0)
		auth.sign_up(users);
	currentUser = auth.sign_in(users);

	state = 0;

	while (1) {
		switch (state) {
		case 0:
			cout << "����:1, ���:2, ����:3, ������:4 >> ";
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
			cout << "���α׷� ����";
			exit(1);
		default:
			cout << "�ùٸ��� ���� �Է°��Դϴ�.";
		}
	}
}

void Reservation_Airplane::set_schedules() {
	vector<string> gpoint = { "��õ","����","����","����","û��" };
	vector<int> gtime = { 7, 12, 17 };

	for (int d = 220501; d <= 220507; d++) {
		for (int& t : gtime) {
			for (string& start : gpoint) {
				for (string& end : gpoint) {
					if (start != end)
						schedules.push_back(Schedule(to_string(d), t, start, end));
				}
			}
		}
	}
}

void Reservation_Airplane::book() {
	string date;
	string time;
	int seatNum = -1;
	int budget = 0;

	cout << "������ �����մϴ�." << "\n\n";

	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;

	cout << "���� �ð��� �����ϼ���. (7��, 12��, 17��) : ";
	cin >> time;

	cout << "���� ������ �Է��ϼ���. : ";
	cin >> budget;

	cout << date << "���� " << time << "���� ���� ��Ȳ�Դϴ�." << '\n' << '\n';

	Schedule currentSchedule;

	for (auto& curSc : schedules)
		if (curSc.get_date() == date && curSc.get_time())
			currentSchedule = curSc;
	int i = 0;
	for (auto p = currentSchedule.get_seat_ptr(); i<8; i++, p++) {
		if (p->get_price() > budget)
			cout << setw(5) << "XXX";
		else {
			if (p->is_reserved())
				cout << setw(5) << p->get_name();
			else
				cout << setw(5) << "---";
		}
	}
	cout << endl;

	cout << "�¼� ��ȣ�� �Է��ϼ���. : ";
	cin >> seatNum; seatNum--;

	if ((currentSchedule.get_seat_ptr() + seatNum)->is_reserved()) {
		cout << "�̹� ����� �¼��Դϴ�." << "\n\n";
	}
	else if ((currentSchedule.get_seat_ptr() + seatNum)->get_price() > budget) {
		cout << "���� �ʰ��� ������ �� �����ϴ�." << "\n\n";
	}
	else {
		(currentSchedule.get_seat_ptr() + seatNum)->set_id(currentUser.get_id());
		(currentSchedule.get_seat_ptr() + seatNum)->set_name(currentUser.get_name());
		cout << "���������� ����Ǿ����ϴ�." << "\n\n";
	}
}

void Reservation_Airplane::show() {
	cout << "���� �����Ȳ�� �����ݴϴ�." << '\n';

	Schedule currentSchedule;
	string date; cout << "���� : "; cin >> date;
	int time; cout << "�ð� : ";  cin >> time;
	int budget; cout << "���� : "; cin >> budget;


	for (auto& curSc : schedules)
		if (curSc.get_date() == date && curSc.get_time())
			currentSchedule = curSc;
	int i = 0;
	for (auto p = currentSchedule.get_seat_ptr(); i < 8; i++, p++) {
		if (p->get_price() > budget)
			cout << setw(7) << "XXX";
		else {
			if (p->is_reserved())
				cout << setw(7) << p->get_name();
			else
				cout << setw(7) << "---";
		}
	}
	cout << endl;
}

void Reservation_Airplane::cancel() {
	cout << "���� ������ ����մϴ�." << '\n';
}