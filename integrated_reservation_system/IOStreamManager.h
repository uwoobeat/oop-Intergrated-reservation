#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include "Auth.h"
#include "Reservation_Airplane.h"
#include "Reservation_Restaurant.h"
#include "Reservation_Library.h"

class IOStreamManager
{
	void read_auth_data(map<string, string>&);
	void write_auth_data(map<string, string>&);
	void read_airplane_data(Reservation_Airplane&);
	void write_airplane_data(vector<User_Airplane>&, vector<Schedule>&);
	void read_restaurant_data();
	void write_restaurant_data(vector<User_Restaurant>&, vector<Schedule_Restaurant>&);
	void read_library_data();
	void write_library_data(vector<User_Library>&, vector<Schedule_Library>&);
};

