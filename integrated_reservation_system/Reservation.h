#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "Auth.h"

class Reservation {
	vector<User> users;
	Auth auth;
protected:
	virtual void book() = 0;
	virtual void show() = 0;
	virtual void cancel() = 0;
};

