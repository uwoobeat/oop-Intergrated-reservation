#pragma once
#include "User.h"
#include <utility>
#include <vector>

class User_Library :
    public User
{
    int totTime = 0;
    vector<pair<string, int>> times; //예약 시작 시간을 기록하는 벡터. 1시간 단위임
public:
    void set_totTime(int);
    void add_totTIme();
    void add_time(string, int);
    void remove_time(string, int);
    int get_totTime();
    vector<pair<string, int>>& get_times();
};

