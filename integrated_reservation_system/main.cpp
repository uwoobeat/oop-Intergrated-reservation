#include <iostream>
#include "Reservation_Airplane.h"
#include "Reservation_Restaurant.h"

using namespace std;

int main() 
{
	Reservation_Airplane* airplaneInterface = new Reservation_Airplane();
	Reservation_Restaurant* restaurantInterface = new Reservation_Restaurant();
	int state = 0;

	cout << "���� ���� ���α׷��� ���� ���� ȯ���մϴ�." << "\n\n";

	while (1) {
		switch (state) {
		case 0:
			cout << "���Ͻô� ���� ���񽺸� �����ϼ���." << '\n';
			cout << "����� : 1, �Ĵ� : 2, ������ : 3, ��� : 4 , ������ : 5 >> ";
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
			state = 0;
			break;
		case 4:
			state = 0;
			break;
		case 5:
			cout << "���α׷� ����";
			exit(1);
		default:
			cout << "�ùٸ��� ���� �Է°��Դϴ�.";
			state = 0;
		}
	}

	return 0;
}
