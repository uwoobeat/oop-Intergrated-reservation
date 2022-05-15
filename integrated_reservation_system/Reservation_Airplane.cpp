#include "Reservation_Airplane.h"

using namespace std;

//생성자에서 Schedule 객체 동적 생성 후 getter 호출하여 지정해줘야 함

Reservation_Airplane::Reservation_Airplane() {
	auth = new Auth;
}

Reservation_Airplane::~Reservation_Airplane() {
	delete auth;
}

void Reservation_Airplane::run() {
	cout << "한성항공에 오신 것을 환영합니다." << "\n\n";

	cout << "로그인을 진행합니다." << '\n';
	cout << "한성항공 아이디가 있다면 1, 아니라면 0을 눌러주세요." << '\n';
	cin >> state; //todo : 0,1 외 예외 처리
	
	if (state == 0) {
		while (1)
			if (auth->sign_up()) {
				break;
			}
	}
	while (1) {
		auto isSignedUp_ID = auth->sign_in();
		if (isSignedUp_Id.first) {
			id = isSignedUp_ID.second;
			break;
		}
	}

	state = 0;

	while (1) {
		switch (state) {
		case 0:
			cout << "예약:1, 취소:2, 보기:3, 끝내기:4 >> ";
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
			cout << "긴급탈출 이히히";
			exit(1);
		default:
			cout << "올바르지 않은 입력값입니다.";
		}
	}
}

void Reservation_Airplane::book() {
}

void Reservation_Airplane::show() {
	cout << "예약을 시작합니다." << '\n';
}

void Reservation_Airplane::cancel() {

}