#include <iostream>

using namespace std;

class Reservation {
	int state = 0;
	string username; //���� user ��ü �����ϴ� ������ ����
};

class Reservation_Interface {
protected:
	virtual void book() = 0;
	virtual void show() = 0;
	virtual void update() = 0;
	virtual void cancel() = 0;
};

class Reservation_Airplain {
	Auth 
};

class Auth {

};

int main() 
{
	Reservation* userInterface = new Reservation();
	return 0;
}