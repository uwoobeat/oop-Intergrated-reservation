#include "Reservation_Restaurant.h"
#include "Schedule_Restaurant.h"
#include <string>
#include <vector>

using namespace std;

void Reservation_Restaurant::run() {
	cout << "고급 레스토랑에 오신 것을 환영합니다." << "\n\n";

	cout << "레스토랑 아이디가 있다면 1, 아니라면 0을 입력하세요. : ";
	cin >> state;
	cout << '\n';

	if (state == 0)
		auth.sign_up(users);
	currentUser = auth.sign_in(users);

	state = 0;

	while (1) {
		switch (state) {
		case 0:
			cout << "예약:1, 취소:2, 보기:3, 퇴장:4, 끝내기:5 >> ";
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
			cout << "프로그램 종료";
			return;
		default:
			cout << "올바르지 않은 입력값입니다.";
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
	bool isWalkFull = true; //워크인 전용 자리가 꽉 찼는지 확인. 찼다면 대기열에 넣기
	Schedule_Restaurant currentSchedule;

	cout << "예약을 시작합니다." << "\n\n";

	cout << "현장 예약이면 1, 아니라면 0을 입력하세요. : ";
	cin >> isWalk;
	
	if (isWalk == 0) {
		cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
		cin >> date;

		cout << "예약 시간대를 선택하세요. (오전, 오후, 저녁) : ";
		cin >> time;
	}
	else {
		date = "220501";
		time = "오전"; //방문예약 손님을 위한 현재 시간대는 22년 05월 01일 오전으로 한다.
	}

	cout << "예약 인원을 선택하세요. 한 번에 6인까지 예약할 수 있습니다. : ";
	cin >> size;

	for (auto& curSc : schedules)
		if (curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;

	int i = 0;
	for (auto p = currentSchedule.get_seat(); i < 8; i++, p++)
		if ((p->get_isWalk() && !(p->is_reserved())) && (p->get_size() >= currentUser.get_size())) {
			//워크인 자리 중 예약이 있지 않으면서 예약하려는 사이즈보다 테이블 정원이 크거나 같은 자리가 있다면
			isWalkFull = false; //워크인 자리가 전부 차있는지 체크하는 변수를 false로 만든다
			break;
		}

	if (isWalkFull) {
		cout << "현재 방문예약 좌석이 꽉 찬 상태입니다. 방문예약 대기열에 등록합니다." << '\n';
		walkUsers.push_back(&currentUser);
		for (auto u : walkUsers)
			u->set_queue(u->get_queue() + 1);
		cout << "방문예약이 완료되었습니다. 현재 대기 순번은 " << currentUser.get_queue() << "번입니다." << "\n\n";
		return;
	}

	cout << date << "일자 " << " " << time << "의 예약 현황입니다." << "\n\n";
	cout << "좌석은 왼쪽부터 순서대로 6인석 2개, 4인석 2개, 2인석 1개, 1인석 2개로 구성되어 있습니다." << '\n';
	cout << "X로 표시된 좌석은 예약 고객 혹은 워크인 고객을 위한 좌석입니다";

	int j = 0;
	for (Seat_Restaurant *p = currentSchedule.get_seat(); j < 8; j++, p++) {
		if (isWalk == 0) { //워크인이 아니라면
			if (p->get_isWalk() == 1) //워크인 전용인 좌석은 XXX로 표시 
				cout << "XXX";
			else {
				if (p->is_reserved())
					cout << p->get_name();
				else
					cout << "---";
			}
		}
		else { //워크인 고객이면
			if (p->get_isWalk() == 0) //예약고객 전용인 좌석은 XXX로 표시 
				cout << "XXX";
			else {
				if (p->is_reserved()) //워크인 고객 좌석에서의 is_reserved()는 현재 이용 여부를 나타냄
					cout << p->get_name();
				else
					cout << "---";
			}
		}
		cout << "   ";
	}

	//todo : get_isWalk()와 user의 isWalk 비교로 출력 로직 단순화 가능
	
	cout << "\n\n";

	cout << "좌석 번호를 입력하세요. : ";
	cin >> seatNum; seatNum--;

	if ((currentSchedule.get_seat() + seatNum)->is_reserved()) {
		cout << "이미 예약된 좌석입니다." << "\n\n";
	}
	else if ((currentSchedule.get_seat() + seatNum)->get_isWalk() != currentUser.get_isWalk()) {
		cout << "예약 전용 좌석 혹은 현장 전용 좌석을 예매할 수 없습니다." << "\n\n";
	}
	else if ((currentSchedule.get_seat() + seatNum)->get_size() < currentUser.get_size()) {
		cout << "예약 인원이 테이블 정원보다 커서 예매할 수 없습니다." << "\n\n";
	}
	else {
		string tmpid = string(currentUser.get_id());
		string tmpname = string(currentUser.get_name());
		currentSchedule.book(tmpid, tmpname, seatNum);
		cout << "성공적으로 예약되었습니다." << "\n\n";
	}
}

void Reservation_Restaurant::show() {
	string date;
	string time;
	Schedule_Restaurant currentSchedule;

	cout << "현재 예약 및 대기상황을 보여줍니다." << '\n';

	if (currentUser.get_queue() > 0) { //대기열 보기
		cout << "현재 대기 순번은 " << currentUser.get_queue() << "번입니다." << "\n\n";
	}
	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;
	cout << "예약 시간대를 선택하세요. (오전, 오후, 저녁) : ";
	cin >> time;

	cout << date << "일자 " << time << " 시간대의 예약 현황입니다." << "\n\n";

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


	cout << "예약 및 대기를 취소합니다." << '\n';

	if (currentUser.get_queue() > 0) { //대기열 취소
		walkUsers.erase(walkUsers.begin() + currentUser.get_queue() - 1); //대기열에서 삭제
		currentUser.set_queue(0); //유저의 대기열 멤버 변수 0으로 설정
		for (auto it = walkUsers.begin() + currentUser.get_queue(); it != walkUsers.end(); it++)
			(*it)->set_queue((*it)->get_queue() - 1); //유저 뒤에 있는 멤버들의 큐 1씩 줄여주기

		return;
	}

	cout << "예약 일자를 선택하세요. (220501 ~ 220507) : ";
	cin >> date;

	cout << "예약 시간대를 선택하세요. (오전, 오후, 저녁) : ";
	cin >> time;

	cout << "좌석 번호를 입력하세요 : ";
	cin >> seatNum;

	for (auto& curSc : schedules)
		if (curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;

	if (currentSchedule.get_seat()[seatNum].get_id() == currentUser.get_id()) {
		currentSchedule.get_seat()[seatNum].cancel();
	}
	else {
		cout << "현재 사용자의 예약 정보가 아니거나, 예약 정보가 존재하지 않는 좌석입니다." << "\n\n";
	}
}

void Reservation_Restaurant::quit() {
	string date = "220501";
	string time = "오전";
	int quitedSeatNum;
	Schedule_Restaurant currentSchedule;

	for (auto& curSc : schedules)
		if (curSc.get_date() == date && curSc.get_time() == time)
			currentSchedule = curSc;
	
	cout << "퇴장한 손님의 좌석번호를 입력해주세요. : ";
	cin >> quitedSeatNum; quitedSeatNum--;

	if (!(currentSchedule.get_seat()[quitedSeatNum].get_isWalk() && currentSchedule.get_seat()[quitedSeatNum].is_reserved())) {
		//워크인 전용좌석이면서 예약중(워크인인 경우 식사중)인 좌석이 아니라면
		cout << "유효하지 않은 좌석번호입니다.";
		return;
	} 
	else
		currentSchedule.get_seat()[quitedSeatNum].cancel();

	cout << "퇴장 신청이 완료되었습니다." << "\n\n";
}