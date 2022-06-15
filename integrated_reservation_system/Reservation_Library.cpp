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
	cout << "T동 독서실에 오신 것을 환영합니다." << "\n\n";

	cout << "세대 아이디가 있다면 1, 아니라면 0을 입력하세요. (세대 아이디는 1~300 사이의 정수) : ";
	cin >> state;
	cout << '\n';

	if (state == 0)
		auth.sign_up(users);
	currentUser = auth.sign_in(users);

	state = 0;

	while (1) {
		switch (state) {
		case 0:
			cout << "예약:1, 취소:2, 보기:3, 통계:4, 끝내기:5 >> ";
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
			cout << "프로그램 종료" << "\n\n";
			return;
		default:
			cout << "올바르지 않은 입력값입니다.";
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
		cout << "13세 이하 어린이는 예약이 불가능합니다.";
		return;
	}

	if (currentUser.get_totTime() >= 4) {
		cout << "총 예약 시간은 4시간을 넘을 수 없습니다.";
		return;
	}

	cout << "예약을 시작합니다." << "\n\n";

	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;

	cout << "예약 시작 시간을 입력하세요. 1시간 단위로 예약이 가능합니다. (9 ~ 23) : ";
	cin >> time;

	set_current(date, time);
	auto p = currentSchedule.get_seat();

	cout << date << "일자" << " " << time << "시의 예약 현황입니다." << "\n\n";
	cout << "* 같은 성별과 인접하여 앉을 수 없습니다." << "\n";
	cout << "** 좌석표가 잘 보이지 않는다면 콘솔창을 확대해주세요." << "\n\n";

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (p[i][j].is_reserved()) {
				string gstr;
				if (p[i][j].get_gender() == 1) gstr = "(남)";
				else if (p[i][j].get_gender() == 0) gstr = "(여)";
				cout << setw(7) << right << p[i][j].get_name() << setw(5) << left << gstr;
			}
			else {
				cout << setw(3) << "" << setw(6) << "------" << setw(3) << "";
			}
		}
		cout << "\n";
	}

	cout << "\n";

	cout << "좌석이 위치한 행을 입력해주세요. : ";
	cin >> row; row--;

	cout << "좌석이 위치한 열을 입력해주세요. : ";
	cin >> col; col--;

	if (p[row][col].is_reserved()) {
		cout << "이미 예약된 좌석입니다." << "\n\n";
		return;
	}
	
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	bool isSameGenderAdjacent = false; //인접 위치에 같은 성별이 존재하는지 확인

	for (auto x : dx) {
		for (auto y : dy) {
			int nx = col; int ny = row;
			nx += x; ny += y;
			if (nx >= 0 && nx <= 14 && ny >= 0 && ny <= 14) { //인덱스 초과하지 않는 범위 내에서 상하좌우 확인
				if (p[ny][nx].is_reserved() && currentUser.get_gender() == p[ny][nx].get_gender())
					isSameGenderAdjacent = true;
			}
		}
	}

	if (isSameGenderAdjacent) {
		cout << "같은 성별이 인접한 자리를 예약할 수 없습니다." << "\n\n";
		return;
	}
	else {
		currentSchedule.book(currentUser.get_id(), currentUser.get_name(), currentUser.get_gender(), row, col);
		currentUser.add_totTIme();
		currentUser.add_time(date, time);
		currentUser.add_reservedCount();
		if (currentUser.get_gender() == 1) this->maleReservedCount++;
		else if (currentUser.get_gender() == 0) this->femaleReservedCount++;
		cout << "예약이 성공적으로 완료되었습니다." << "\n\n";
	}
}

void Reservation_Library::show() {
	string date;
	int time;

	cout << "현재 예약 상황을 보여줍니다." << "\n";

	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;

	cout << "예약 시작 시간을 입력하세요. 1시간 단위로 예약이 가능합니다. (9 ~ 23) : ";
	cin >> time;

	set_current(date, time);
	auto p = currentSchedule.get_seat();


	cout << '\n' << date << "일자" << " " << time << "시의 예약 현황입니다." << "\n\n";
	cout << "* 같은 성별과 인접하여 앉을 수 없습니다." << "\n";
	cout << "** 좌석표가 잘 보이지 않는다면 콘솔창을 확대해주세요." << "\n\n";

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			if (p[i][j].is_reserved()) {
				string gstr;
				if (p[i][j].get_gender() == 1) gstr = "(남)";
				else if (p[i][j].get_gender() == 0) gstr = "(여)";
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

	cout << "예약을 취소합니다." << '\n';

	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;

	cout << "예약 시작 시간을 입력하세요. (9 ~ 23) : ";
	cin >> time;

	cout << "좌석이 위치한 행을 입력해주세요. : ";
	cin >> row; row--;

	cout << "좌석이 위치한 열을 입력해주세요. : ";
	cin >> col; col--;

	set_current(date, time);
	auto p = currentSchedule.get_seat();

	if (p[row][col].get_id() == currentUser.get_id() && p[row][col].is_reserved()) {
		p[row][col].cancel();
		cout << "예약이 성공적으로 취소되었습니다." << "\n\n";
	}
	else {
		cout << "현재 사용자의 예약 정보가 아니거나, 예약 정보가 존재하지 않는 좌석입니다." << "\n\n";
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

	cout << "통계 현황을 보여줍니다." << "\n\n";

	cout << "현재 로그인된 고객의 예약 횟수 : " << this->maleReservedCount + this->femaleReservedCount << '\n';
	cout << "남성 고객들의 예약 횟수 : " << this->maleReservedCount << '\n';
	cout << "여성 고객들의 예약 횟수 : " << this->femaleReservedCount << '\n';


	cout << "좌석 별 예약 횟수를 보여줍니다." << "\n";
	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;
	cout << "예약 시작 시간을 입력하세요. (9 ~ 23) : ";
	cin >> time;

	set_current(date, time);
	auto p = currentSchedule.get_seat();

	cout << date << "일자" << " " << time << "시의 좌석 별 예약 횟수입니다." << "\n\n";

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << p[i][j].get_reservedCount() << "  ";
		}
		cout << "\n";
	}
	cout << "\n";
}