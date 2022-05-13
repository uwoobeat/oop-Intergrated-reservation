#pragma once
#include "Reservation.h"

class Reservation_Airplane : public Reservation
{
protected:
	virtual void book();
	virtual void show();
	virtual void cancel();
};