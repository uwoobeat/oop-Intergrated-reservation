#include "Reservation_Restaurant.h"
#include "Schedule_Restaurant.h"
#include <string>
#include <vector>

using namespace std;

void Reservation_Restaurant::run() {
	cout << "��� ��������� ���� ���� ȯ���մϴ�." << "\n\n";

	cout << "������� ���̵� �ִٸ� 1, �ƴ϶�� 0�� �Է��ϼ���. : ";
	cin >> state;
	cout << '\n';

	if (state == 0)
		auth.sign_up(users);
	currentUser = auth.sign_in(users);

	state = 0;

	while (1) {
		switch (state) {
		case 0:
			cout << "����:1, ���:2, ����:3, ����:4, ������:5 >> ";
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
			quit();
			state = 0;
			break;
		case 5:
			cout << "���α׷� ����";
			return;
		default:
			cout << "�ùٸ��� ���� �Է°��Դϴ�.";
			state = 0;
		}
	}
}

void Reservation_Restaurant::book() {
	string date;
	string time;
	int size;
	bool isWalk;
	int seatNum = -1;
	bool isWalkFull = true; //��ũ�� ���� �ڸ��� �� á���� Ȯ��. á�ٸ� ��⿭�� �ֱ�
	Schedule_Restaurant currentSchedule;

	cout << "������ �����մϴ�." << "\n\n";

	cout << "���� �����̸� 1, �ƴ϶�� 0�� �Է��ϼ���. : ";
	cin >> isWalk;
	
	if (isWalk == 0) {
		cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
		cin >> date;

		cout << "���� �ð��븦 �����ϼ���. (����, ����, ����) : ";
		cin >> time;
	}
	else {
		date = "220501";
		time = "����"; //�湮���� �մ��� ���� ���� �ð���� 22�� 05�� 01�� �������� �Ѵ�.
	}

	cout << "���� �ο��� �����ϼ���. �� ���� 6�α��� ������ �� �ֽ��ϴ�. : ";
	cin >> size;

	for (auto& curSc : schedules)
		if (curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;

	int i = 0;
	for (auto p = currentSchedule.get_seat(); i < 8; i++, p++)
		if ((p->get_isWalk() && !(p->is_reserved())) && (p->get_size() >= currentUser.get_size())) {
			//��ũ�� �ڸ� �� ������ ���� �����鼭 �����Ϸ��� ������� ���̺� ������ ũ�ų� ���� �ڸ��� �ִٸ�
			isWalkFull = false; //��ũ�� �ڸ��� ���� ���ִ��� üũ�ϴ� ������ false�� �����
			break;
		}

	if (isWalkFull) {
		cout << "���� �湮���� �¼��� �� �� �����Դϴ�. �湮���� ��⿭�� ����մϴ�." << '\n';
		walkUsers.push_back(&currentUser);
		for (auto u : walkUsers)
			u->set_queue(u->get_queue() + 1);
		cout << "�湮������ �Ϸ�Ǿ����ϴ�. ���� ��� ������ " << currentUser.get_queue() << "���Դϴ�." << "\n\n";
		return;
	}

	cout << date << "���� " << " " << time << "�� ���� ��Ȳ�Դϴ�." << "\n\n";
	cout << "�¼��� ���ʺ��� ������� 6�μ� 2��, 4�μ� 2��, 2�μ� 1��, 1�μ� 2���� �����Ǿ� �ֽ��ϴ�." << '\n';
	cout << "X�� ǥ�õ� �¼��� ���� �� Ȥ�� ��ũ�� ���� ���� �¼��Դϴ�";

	int j = 0;
	for (Seat_Restaurant *p = currentSchedule.get_seat(); j < 8; j++, p++) {
		if (isWalk == 0) { //��ũ���� �ƴ϶��
			if (p->get_isWalk() == 1) //��ũ�� ������ �¼��� XXX�� ǥ�� 
				cout << "XXX";
			else {
				if (p->is_reserved())
					cout << p->get_name();
				else
					cout << "---";
			}
		}
		else { //��ũ�� ���̸�
			if (p->get_isWalk() == 0) //����� ������ �¼��� XXX�� ǥ�� 
				cout << "XXX";
			else {
				if (p->is_reserved()) //��ũ�� �� �¼������� is_reserved()�� ���� �̿� ���θ� ��Ÿ��
					cout << p->get_name();
				else
					cout << "---";
			}
		}
		cout << "   ";
	}

	//todo : get_isWalk()�� user�� isWalk �񱳷� ��� ���� �ܼ�ȭ ����
	
	cout << "\n\n";

	cout << "�¼� ��ȣ�� �Է��ϼ���. : ";
	cin >> seatNum; seatNum--;

	if ((currentSchedule.get_seat() + seatNum)->is_reserved()) {
		cout << "�̹� ����� �¼��Դϴ�." << "\n\n";
	}
	else if ((currentSchedule.get_seat() + seatNum)->get_isWalk() != currentUser.get_isWalk()) {
		cout << "���� ���� �¼� Ȥ�� ���� ���� �¼��� ������ �� �����ϴ�." << "\n\n";
	}
	else if ((currentSchedule.get_seat() + seatNum)->get_size() < currentUser.get_size()) {
		cout << "���� �ο��� ���̺� �������� Ŀ�� ������ �� �����ϴ�." << "\n\n";
	}
	else {
		string tmpid = string(currentUser.get_id());
		string tmpname = string(currentUser.get_name());
		currentSchedule.book(tmpid, tmpname, seatNum);
		cout << "���������� ����Ǿ����ϴ�." << "\n\n";
	}
}

void Reservation_Restaurant::show() {
	string date;
	string time;
	Schedule_Restaurant currentSchedule;

	cout << "���� ���� �� ����Ȳ�� �����ݴϴ�." << '\n';

	if (currentUser.get_queue() > 0) { //��⿭ ����
		cout << "���� ��� ������ " << currentUser.get_queue() << "���Դϴ�." << "\n\n";
	}
	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;
	cout << "���� �ð��븦 �����ϼ���. (����, ����, ����) : ";
	cin >> time;

	cout << date << "���� " << time << " �ð����� ���� ��Ȳ�Դϴ�." << "\n\n";

	int i = 0;
	for (auto p = currentSchedule.get_seat(); i < 8; i++, p++) {
		if (p->is_reserved()) {
			cout << p->get_name();
		}
		else {
			cout << "---";
		}
		cout << "   ";
	}
}

void Reservation_Restaurant::cancel() {
	string date;
	string time;
	int seatNum = -1;
	Schedule_Restaurant currentSchedule;


	cout << "���� �� ��⸦ ����մϴ�." << '\n';

	if (currentUser.get_queue() > 0) { //��⿭ ���
		walkUsers.erase(walkUsers.begin() + currentUser.get_queue() - 1); //��⿭���� ����
		currentUser.set_queue(0); //������ ��⿭ ��� ���� 0���� ����
		for (auto it = walkUsers.begin() + currentUser.get_queue(); it != walkUsers.end(); it++)
			(*it)->set_queue((*it)->get_queue() - 1); //���� �ڿ� �ִ� ������� ť 1�� �ٿ��ֱ�

		return;
	}

	cout << "���� ���ڸ� �����ϼ���. (220501 ~ 220507) : ";
	cin >> date;

	cout << "���� �ð��븦 �����ϼ���. (����, ����, ����) : ";
	cin >> time;

	cout << "�¼� ��ȣ�� �Է��ϼ��� : ";
	cin >> seatNum;

	for (auto& curSc : schedules)
		if (curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;

	if (currentSchedule.get_seat()[seatNum].get_id() == currentUser.get_id()) {
		currentSchedule.get_seat()[seatNum].cancel();
	}
	else {
		cout << "���� ������� ���� ������ �ƴϰų�, ���� ������ �������� �ʴ� �¼��Դϴ�." << "\n\n";
	}
}

void Reservation_Restaurant::quit() {
	string date = "220501";
	string time = "����";
	int quitedSeatNum;
	Schedule_Restaurant currentSchedule;

	for (auto& curSc : schedules)
		if (curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;
	
	cout << "������ �մ��� �¼���ȣ�� �Է����ּ���. : ";
	cin >> quitedSeatNum; quitedSeatNum--;

	if (!(currentSchedule.get_seat()[quitedSeatNum].get_isWalk() && currentSchedule.get_seat()[quitedSeatNum].is_reserved())) {
		//��ũ�� �����¼��̸鼭 ������(��ũ���� ��� �Ļ���)�� �¼��� �ƴ϶��
		cout << "��ȿ���� ���� �¼���ȣ�Դϴ�.";
		return;
	} 
	else
		currentSchedule.get_seat()[quitedSeatNum].cancel();

	cout << "���� ��û�� �Ϸ�Ǿ����ϴ�." << "\n\n";
}