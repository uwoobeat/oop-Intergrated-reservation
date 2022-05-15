#pragma once
#include <iostream>
#include "Seat_Airplane.h"
#include <algorithm>
#include <string>

using namespace std;

class Schedule //���� �������� �����Ѵ�
{
	string date;
	int time;
	Seat_Airplane* seats;
	string departure; //��� ����
	string arrival; //���� ����
public:
	Schedule(); //seats�� Seat_Airplane ���� ����
	~Schedule(); //Seat_Airplane ���� �迭 �޸� ����
	void set_date(string);
	void set_time(int);
	void set_departure(string);
	void set_arrival(string);
	string get_date();
	int get_time();
	string get_departure();
	string get_arrival();
};
