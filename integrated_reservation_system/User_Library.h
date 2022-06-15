#pragma once
#include "User.h"
#include <utility>
#include <vector>

class User_Library :
    public User
{
    int totTime = 0;
    vector<pair<string, int>> times; //���� ���� �ð��� ����ϴ� ����. 1�ð� ������
public:
    void set_totTime(int);
    void add_totTIme();
    void add_time(string, int);
    void remove_time(string, int);
    int get_totTime();
    vector<pair<string, int>>& get_times();
};

