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

	cout << "���� ���� ���α׷��� ���� ���� ȯ���մϴ�." << "\n\n";

	while (1) {
		switch (state) {
		case 0:
			cout << "���Ͻô� ���� ���񽺸� �����ϼ���." << '\n';
			cout << "�����:1, �Ĵ�:2, ������:3, ������:4 >> ";
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
			cout << "���α׷� ����";
			exit(1);
		default:
			cout << "�ùٸ��� ���� �Է°��Դϴ�.";
			state = 0;
		}
	}

	return 0;
}
