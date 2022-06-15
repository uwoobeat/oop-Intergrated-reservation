#pragma once
#include <iostream>
#include <vector>
#include "User.h"
#include "Auth.h"

class Reservation {
protected:
	virtual void book() = 0;
	virtual void show() = 0;
	virtual void cancel() = 0;
public:
	int maleReservedCount = 0;
	int femaleReservedCount = 0;
};

