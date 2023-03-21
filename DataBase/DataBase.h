#pragma once
#include <vector>
#include <string>
#include <map>
#include <set>
#include <exception>
#include <iostream>
#include "Operators.h"

using namespace std;

class DataBase {
public:
    void add(const vector<string> args);

    void del(const vector<string> args, int c);

    void find(const vector<string> args);

    void print();
private:
     map<date, set<string>> pair;
};