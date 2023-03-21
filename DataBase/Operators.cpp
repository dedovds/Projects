#include "Operators.h"

using namespace std;

bool operator< (const date& dt1, const date& dt2) {
    if (dt1.year < dt2.year) {
        return 1;
    }
    else if (dt1.year > dt2.year) {
        return 0;
    }
    else {
        if (dt1.month < dt2.month) {
            return 1;
        }
        else if (dt1.month > dt2.month) {
            return 0;
        }
        else {
            if (dt1.day < dt2.day) {
                return 1;
            }
            else {
                return 0;
            }
        }
    }
}


ostream& operator<< (ostream& stream, const date& date) {
    stream << date.year << "-" << date.month << "-" << date.day;
    return stream;
}
void PrintSortedSet(date date, set<string>& ev) {
    vector<string> events;
    for (auto& b: ev) {
        events.push_back(b);
    }
    sort(begin(events), end(events));
    for (auto& h : events) {
        cout << date << " " << h << "\n";
    }
}


istream& operator>> (istream& stream, date& date) {
    int c = 0;
    string s = "";
    stream >> date.year;
    s += to_string(date.year);
    if (stream.peek() != '-') {
        c++;
    }
    s += stream.peek();
    stream.ignore(1);
    stream >> date.month;
    s += to_string(date.month);
    if(date.month > 12 || date.month < 1) {
        stringstream ss;
        ss << "Month value is invalid: " << date.month << endl;
        throw runtime_error(ss.str());
    }
    if (stream.peek() != '-') {
        c++;
    }
    s += stream.peek();
    stream.ignore(1);
    stream >> date.day;
    s += to_string(date.day);
    if (date.day > 31 || date.day < 1) {
        stringstream ss;
        ss << "Day value is invalid: " << date.day << endl;
        throw runtime_error(ss.str());
    }
    if (c != 0) {
        stringstream ss;
        ss << "Wrong date format: " << s << endl;
        throw runtime_error(ss.str());
    }
    return stream;
}

