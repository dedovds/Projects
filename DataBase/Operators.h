#pragma once
#include <fstream>
#include <sstream>
#include <map>
#include <exception>
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct date {
    int year;
    int month;
    int day;
};

bool operator< (const date& dt1, const date& dt2);

ostream& operator<< (ostream& stream, const date& date);

void PrintSortedSet(date date, set<string>& ev);

istream& operator>> (istream& stream, date& date);