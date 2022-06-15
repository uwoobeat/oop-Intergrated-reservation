#include <iostream>
#include "Reservation_Airplane.h"
#include "Reservation_Restaurant.h"
#include "Reservation_Library.h"

using namespace std;

int main() 
{
	Reservation_Airplane* airplaneInterface = new Reservation_Airplane();
	Reservation_Restaurant* restaurantInterface = new Reservation_Restaurant();
	Reservation_Library* libraryInterface = new Reservation_Library();
	int state = 0;

	cout << "통합 예매 프로그램에 오신 것을 환영합니다." << "\n\n";

	while (1) {
		switch (state) {
		case 0:
			cout << "원하시는 예약 서비스를 선택하세요." << '\n';
			cout << "비행기:1, 식당:2, 독서실:3, 끝내기:4 >> ";
			cin >> state;
			cout << endl;
			break;
		case 1:
			airplaneInterface->run();
			state = 0;
			break;
		case 2:
			restaurantInterface->run();
			state = 0;
			break;
		case 3:
			libraryInterface->run();
			state = 0;
			break;
		case 4:
			cout << "프로그램 종료";
			exit(1);
		default:
			cout << "올바르지 않은 입력값입니다.";
			state = 0;
		}
	}

	return 0;
}
