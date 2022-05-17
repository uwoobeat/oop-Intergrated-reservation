#include "User_Restaurant.h"

void User_Restaurant::set_groupNum(int groupNum) {
	if (groupNum > 0)
		this->groupNum = groupNum;
	else
		this->groupNum = -1;
}

void User_Restaurant::set_isWalk(bool isWalk) {
	this->isWalk = isWalk;
}

void User_Restaurant::set_queue(int queue) {
	this->queue = queue;
}

int User_Restaurant::get_groupNum() {
	return groupNum;
}

bool User_Restaurant::get_isWalk() {
	return isWalk;
}

int User_Restaurant::get_queue() {
	return queue;
}