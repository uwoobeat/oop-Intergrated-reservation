#include "Reservation_Airplane.h"
#include "Schedule.h"
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//생성자에서 Schedule 객체 동적 생성 후 getter 호출하여 지정해줘야 함
//-> 벡터 사용하므로 필요없음

void Reservation_Airplane::run() {
	set_schedules();

	cout << "한성항공에 오신 것을 환영합니다." << "\n\n";

	cout << "한성항공 아이디가 있다면 1, 아니라면 0을 눌러주세요 : ";
	cin >> state; //todo : 0,1 외 예외 처리
	cout << endl;
	
	if (state == 0)
		auth.sign_up(users);
	currentUser = auth.sign_in(users);

	state = 0;

	while (1) {
		switch (state) {
		case 0:
			cout << "예약:1, 취소:2, 보기:3, 끝내기:4 >> ";
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
			cout << "프로그램 종료";
			exit(1);
		default:
			cout << "올바르지 않은 입력값입니다.";
		}
	}
}

void Reservation_Airplane::set_schedules() {
	vector<string> gpoint = { "인천","김포","김해","제주","청주" };
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

	cout << "예약을 시작합니다." << "\n\n";

	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;

	cout << "예약 시간을 선택하세요. (7시, 12시, 17시) : ";
	cin >> time;

	cout << "예산 범위를 입력하세요. : ";
	cin >> budget;

	cout << date << "일자 " << time << "시의 예약 현황입니다." << '\n' << '\n';

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

	cout << "좌석 번호를 입력하세요. : ";
	cin >> seatNum; seatNum--;

	if ((currentSchedule.get_seat_ptr() + seatNum)->is_reserved()) {
		cout << "이미 예약된 좌석입니다." << "\n\n";
	}
	else if ((currentSchedule.get_seat_ptr() + seatNum)->get_price() > budget) {
		cout << "예산 초과로 예매할 수 없습니다." << "\n\n";
	}
	else {
		(currentSchedule.get_seat_ptr() + seatNum)->set_id(currentUser.get_id());
		(currentSchedule.get_seat_ptr() + seatNum)->set_name(currentUser.get_name());
		cout << "성공적으로 예약되었습니다." << "\n\n";
	}
}

void Reservation_Airplane::show() {
	cout << "현재 예약상황을 보여줍니다." << '\n';

	Schedule currentSchedule;
	string date; cout << "일자 : "; cin >> date;
	int time; cout << "시간 : ";  cin >> time;
	int budget; cout << "예산 : "; cin >> budget;


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
	cout << "현재 예약을 취소합니다." << '\n';
}