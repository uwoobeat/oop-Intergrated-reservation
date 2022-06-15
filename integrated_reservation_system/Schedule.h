#pragma once
#include <iostream>
#include "Seat_Airplane.h"
#include <algorithm>
#include <string>

class Schedule //비행 스케쥴을 구현한다
{
	string date;
	int time;
	Seat_Airplane* seats;
	string departure; //출발 지점
	string arrival; //도착 지점
public:
	Schedule(); //seats에 Seat_Airplane 동적 생성
	Schedule(string, int, string, string);
	~Schedule(); //Seat_Airplane 동적 배열 메모리 해제
	void set_date(string);
	void set_time(int);
	void set_departure(string);
	void set_arrival(string);
	string get_date();
	int get_time();
	Seat_Airplane* get_seat();
	string get_departure();
	string get_arrival();
	void book(string, string, int);
};
