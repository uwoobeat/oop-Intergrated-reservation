#pragma once
#include "Seat.h"
class Seat_Library :
    public Seat
{
    int gender = -1;
public:
    void set_gender(int);
    int get_gender();
};