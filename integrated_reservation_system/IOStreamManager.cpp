#include "IOStreamManager.h"

using namespace std;

void IOStreamManager::read_auth_data(map<string, string>&) {

}

void IOStreamManager::write_auth_data(map<string, string>& user_auth_map) {
	fstream userAuthFile("auth.txt", ios::out | ios::app);
	if (!userAuthFile.is_open()) {
		cout << "파일을 여는 중 오류가 발생했습니다.";
		return;
	}

	for (const auto& user_data : user_auth_map) {
		userAuthFile << user_data.first << ', ' << user_data.second << endl;
	}

	userAuthFile.close();
}

void IOStreamManager::write_airplane_data(vector<User_Airplane>& users, vector<Schedule>& schedules) {
	fstream airUserFile("airplane_user.txt", ios::out | ios::app);
	fstream airScheduleFile("airplane_schedule.txt", ios::out | ios::app);
	if (!airUserFile.is_open() || !airScheduleFile.is_open()) {
		cout << "파일을 여는 중 오류가 발생했습니다.";
		return;
	}

	for (auto& user : users) {
		airUserFile << user.get_id() << ', ' << user.get_name() << ', ' << user.get_age() << ', ' << user.get_reservedCount() << ', ' << user.get_mileage() << ', ' << user.get_isOneWay();
	}

	for (auto& schedule : schedules) {
		airScheduleFile << schedule.get_date() << ', ' << schedule.get_time() << ', ' << schedule.get_departure() << ', ' << schedule.get_arrival();
	}
}

void IOStreamManager::read_restaurant_data() {

}

void IOStreamManager::write_restaurant_data(vector<User_Restaurant>& users, vector<Schedule_Restaurant>& schedules) {
	fstream resUserFile("restaurant_user.txt", ios::out | ios::app);
	fstream resScheduleFile("restaurant_schedule.txt", ios::out | ios::app);
	if (!resUserFile.is_open() || !resScheduleFile.is_open()) {
		cout << "파일을 여는 중 오류가 발생했습니다.";
		return;
	}

	for (auto& user : users) {
		resUserFile << user.get_id() << ', ' << user.get_name() << ', ' << user.get_age() << ', ' << user.get_reservedCount() << ', ' << user.get_size() << ', ' << user.get_isWalk() << ', ' << user.get_queue();
	}

	for (auto& schedule : schedules) {
	}
}

void IOStreamManager::read_library_data() {

}

void IOStreamManager::write_library_data(vector<User_Library>& users, vector<Schedule_Library>& schedules) {
	fstream libUserFile("restaurant_user.txt", ios::out | ios::app);
	fstream libScheduleFile("restaurant_schedule.txt", ios::out | ios::app);
	if (!libUserFile.is_open() || !libScheduleFile.is_open()) {
		cout << "파일을 여는 중 오류가 발생했습니다.";
		return;

	for (auto& user : users) {
		libUserFile << user.get_id() << ', ' << user.get_name() << ', ' << user.get_age() << ', ' << user.get_reservedCount() << ', ' << user.get_totTime() << ', ' << user.get_times()[0] << ', ' << user.get_times()[1];
	}
}