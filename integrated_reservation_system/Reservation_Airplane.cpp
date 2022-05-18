#include "Reservation_Airplane.h"
#include "Schedule.h"
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//�����ڿ��� Schedule ��ü ���� ���� �� getter ȣ���Ͽ� ��������� ��
//-> ���� ����ϹǷ� �ʿ����

void Reservation_Airplane::run() {
	cout << "�Ѽ��װ��� ���� ���� ȯ���մϴ�." << "\n\n";

	make_schedules();

	cout << "�Ѽ��װ� ���̵� �ִٸ� 1, �ƴ϶�� 0�� �Է��ϼ���. : ";
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
			return;
		default:
			cout << "�ùٸ��� ���� �Է°��Դϴ�.";
			state = 0;
		}
	}
}

void Reservation_Airplane::make_schedules() {
	vector<string> gpoint = { "��õ","����","����","����","û��" };
	vector<int> gtime = { 7, 12, 17 };

	for (int d = 220501; d <= 220507; d++) {
		for (int t : gtime) {
			for (string& start : gpoint) {
				for (string& end : gpoint) {
					if (start != end) {
						auto tmp = Schedule(to_string(d), t, start, end);
						schedules.push_back(Schedule(tmp));
					}
				}
			}
		}
	}
}

void Reservation_Airplane::set_schedule() {
	string date;
	int time;
	string start;
	string end;
	int seatNum = -1;
	int budget = 0;
	Schedule currentSchedule;

	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;

	cout << "���� �ð��� �����ϼ���. (7��, 12��, 17��) : ";
	cin >> time;

	cout << "��� ����(��õ,����,����,����,û��)�� �Է��ϼ���. : ";
	cin >> start;

	cout << "���� ����(��õ,����,����,����,û��)�� �Է��ϼ���. : ";
	cin >> end;

	cout << "���� ������ �ִ� �ݾ��� �Է��ϼ���. : ";
	cin >> budget;

	cout << date << "���� " << time << "���� ���� ��Ȳ�Դϴ�." << '\n' << '\n';

	for (auto& curSc : schedules)
		if (curSc.get_departure() == start && curSc.get_arrival() == end && curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;

	int i = 0;
	for (auto p = currentSchedule.get_seat(); i < 8; i++, p++) {
		if (p->get_price() > budget)
			cout << "XXX";
		else {
			if (p->is_reserved())
				cout << p->get_name();
			else
				cout << "---";
		}
		cout << "   ";
	}

	cout << "\n\n";

	cout << "�¼� ��ȣ�� �Է��ϼ���. : ";
	cin >> seatNum; seatNum--;

	if ((currentSchedule.get_seat() + seatNum)->is_reserved()) {
		cout << "�̹� ����� �¼��Դϴ�." << "\n\n";
	}
	else if ((currentSchedule.get_seat() + seatNum)->get_price() > budget) {
		cout << "���� �ʰ��� ������ �� �����ϴ�." << "\n\n";
	}
	else {
		string tmpid = string(currentUser.get_id());
		string tmpname = string(currentUser.get_name());
		currentSchedule.book(tmpid, tmpname, seatNum);
		currentUser.set_mileage(currentUser.get_mileage() + 100);
		cout << "���������� ����Ǿ����ϴ�." << "\n\n";
	}
}

void Reservation_Airplane::book() {
	int isOneWay;

	cout << "������ �����մϴ�." << "\n\n";

	cout << "�պ� / �� ���θ� �����ϼ���. (�� - 1, �պ� - 0) : ";
	cin >> isOneWay; 
	
	currentUser.set_isOneWay(isOneWay);

	if (currentUser.get_isOneWay()) {
		cout << "�� ������ �����մϴ�." << endl;
		set_schedule();
	}
	else {
		cout << "�պ� ������ �����մϴ�." << '\n';
		cout << "����� ������ ������ �����մϴ�." << '\n';
		set_schedule();
		cout << "������ ������ ������ �����մϴ�." << '\n';
		set_schedule();
		//console �����ؼ� �Է� �ѹ��� �ް� �պ� ���� ó���ϵ���
	}
}

void Reservation_Airplane::show() {
	string date;
	int time;
	string start;
	string end;
	int seatNum = -1;
	Schedule currentSchedule;

	cout << "���� �����Ȳ�� �����ݴϴ�." << '\n';

	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;

	cout << "���� �ð��� �����ϼ���. (7��, 12��, 17��) : ";
	cin >> time;

	cout << "��� ����(��õ,����,����,����,û��)�� �Է��ϼ���. : ";
	cin >> start;

	cout << "���� ����(��õ,����,����,����,û��)�� �Է��ϼ���. : ";
	cin >> end;

	cout << date << "���� " << time << "���� ���� ��Ȳ�Դϴ�." << '\n' << '\n';

	for (auto& curSc : schedules)
		if (curSc.get_departure() == start && curSc.get_arrival() == end && curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;

	int i = 0;
	for (auto p = currentSchedule.get_seat(); i < 8; i++, p++) {
		if (p->is_reserved())
			cout << p->get_name();
		else
			cout << "---";
		cout << "   ";
	}

	cout << "\n\n";
}

void Reservation_Airplane::cancel() {
	string date;
	int time;
	string start;
	string end;
	int seatNum = -1;
	Schedule currentSchedule;

	cout << "������ ����մϴ�." << '\n';

	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;

	cout << "���� �ð��� �����ϼ���. (7��, 12��, 17��) : ";
	cin >> time;

	cout << "��� ����(��õ,����,����,����,û��)�� �Է��ϼ���. : ";
	cin >> start;

	cout << "���� ����(��õ,����,����,����,û��)�� �Է��ϼ���. : ";
	cin >> end;

	cout << "�¼� ��ȣ�� �Է��ϼ��� : ";
	cin >> seatNum;

	for (auto& curSc : schedules)
		if (curSc.get_departure() == start && curSc.get_arrival() == end && curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;

	if (currentSchedule.get_seat()[seatNum].get_id() == currentUser.get_id()) {
		currentSchedule.get_seat()[seatNum].cancel();
	}
	else {
		cout << "���� ������� ���� ������ �ƴϰų�, ���� ������ �������� �ʴ� �¼��Դϴ�." << '\n';
	}
}