#include "User_Restaurant.h"

void User_Restaurant::set_size(int size) {
	if (size > 0)
		this->size = size;
	else
		this->size = -1;
}

void User_Restaurant::set_isWalk(bool isWalk) {
	this->isWalk = isWalk;
}

void User_Restaurant::set_queue(int queue) {
	this->queue = queue;
}

int User_Restaurant::get_size() {
	return size;
}

bool User_Restaurant::get_isWalk() {
	return isWalk;
}

int User_Restaurant::get_queue() {
	return queue;
}