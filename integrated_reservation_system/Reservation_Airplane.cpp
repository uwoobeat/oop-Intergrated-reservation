#include "Reservation_Airplane.h"
#include "Schedule.h"
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

//생성자에서 Schedule 객체 동적 생성 후 getter 호출하여 지정해줘야 함
//-> 벡터 사용하므로 필요없음

void Reservation_Airplane::run() {
	cout << "한성항공에 오신 것을 환영합니다." << "\n\n";

	make_schedules();

	cout << "한성항공 아이디가 있다면 1, 아니라면 0을 입력하세요. : ";
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
			return;
		default:
			cout << "올바르지 않은 입력값입니다.";
			state = 0;
		}
	}
}

void Reservation_Airplane::make_schedules() {
	vector<string> gpoint = { "인천","김포","김해","제주","청주" };
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

	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;

	cout << "예약 시간을 선택하세요. (7시, 12시, 17시) : ";
	cin >> time;

	cout << "출발 공항(인천,김포,김해,제주,청주)을 입력하세요. : ";
	cin >> start;

	cout << "도착 공항(인천,김포,김해,제주,청주)을 입력하세요. : ";
	cin >> end;

	cout << "예매 가능한 최대 금액을 입력하세요. : ";
	cin >> budget;

	cout << date << "일자 " << time << "시의 예약 현황입니다." << '\n' << '\n';

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

	cout << "좌석 번호를 입력하세요. : ";
	cin >> seatNum; seatNum--;

	if ((currentSchedule.get_seat() + seatNum)->is_reserved()) {
		cout << "이미 예약된 좌석입니다." << "\n\n";
	}
	else if ((currentSchedule.get_seat() + seatNum)->get_price() > budget) {
		cout << "예산 초과로 예매할 수 없습니다." << "\n\n";
	}
	else {
		string tmpid = string(currentUser.get_id());
		string tmpname = string(currentUser.get_name());
		currentSchedule.book(tmpid, tmpname, seatNum);
		currentUser.set_mileage(currentUser.get_mileage() + 100);
		cout << "성공적으로 예약되었습니다." << "\n\n";
	}
}

void Reservation_Airplane::book() {
	int isOneWay;

	cout << "예약을 시작합니다." << "\n\n";

	cout << "왕복 / 편도 여부를 선택하세요. (편도 - 1, 왕복 - 0) : ";
	cin >> isOneWay; 
	
	currentUser.set_isOneWay(isOneWay);

	if (currentUser.get_isOneWay()) {
		cout << "편도 예약을 시작합니다." << endl;
		set_schedule();
	}
	else {
		cout << "왕복 예약을 시작합니다." << '\n';
		cout << "출발지 비행편 예약을 시작합니다." << '\n';
		set_schedule();
		cout << "도착지 비행편 예약을 시작합니다." << '\n';
		set_schedule();
		//console 수정해서 입력 한번만 받고 왕복 예약 처리하도록
	}
}

void Reservation_Airplane::show() {
	string date;
	int time;
	string start;
	string end;
	int seatNum = -1;
	Schedule currentSchedule;

	cout << "현재 예약상황을 보여줍니다." << '\n';

	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;

	cout << "예약 시간을 선택하세요. (7시, 12시, 17시) : ";
	cin >> time;

	cout << "출발 공항(인천,김포,김해,제주,청주)을 입력하세요. : ";
	cin >> start;

	cout << "도착 공항(인천,김포,김해,제주,청주)을 입력하세요. : ";
	cin >> end;

	cout << date << "일자 " << time << "시의 예약 현황입니다." << '\n' << '\n';

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

	cout << "예약을 취소합니다." << '\n';

	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;

	cout << "예약 시간을 선택하세요. (7시, 12시, 17시) : ";
	cin >> time;

	cout << "출발 공항(인천,김포,김해,제주,청주)을 입력하세요. : ";
	cin >> start;

	cout << "도착 공항(인천,김포,김해,제주,청주)을 입력하세요. : ";
	cin >> end;

	cout << "좌석 번호를 입력하세요 : ";
	cin >> seatNum;

	for (auto& curSc : schedules)
		if (curSc.get_departure() == start && curSc.get_arrival() == end && curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;

	if (currentSchedule.get_seat()[seatNum].get_id() == currentUser.get_id()) {
		currentSchedule.get_seat()[seatNum].cancel();
	}
	else {
		cout << "현재 사용자의 예약 정보가 아니거나, 예약 정보가 존재하지 않는 좌석입니다." << '\n';
	}
}