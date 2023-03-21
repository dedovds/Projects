#include "DataBase.h"

using namespace std;

void DataBase:: add(const vector<string> args) {
    stringstream ss(args[1]);
    date dt;
    try{
        ss >> dt;
        pair[dt].insert(args[2]);
        } catch (runtime_error& ex) {
            cout << ex.what();
        };
}
void DataBase:: del(const vector<string> args, int c) {
    if (c == 3) {
        stringstream ss(args[1]);
        date dt;
        try{
        ss >> dt;
        if (pair[dt].count(args[2]) > 0) {
            pair[dt].erase(args[2]);
            cout << "Deleted successfully\n";
        }
        else {
            cout << "Event not found\n";
        }
        if (pair[dt].size() == 0) {
            pair.erase(dt);
        }
        } catch (runtime_error& ex) {
            cout << ex.what();
        };
    }
    else if (c == 2) {
        stringstream ss(args[1]);
        date dt;
        try{
        ss >> dt;
        cout << "Deleted " << pair[dt].size() << " events\n";
        pair.erase(dt);
        } catch (runtime_error& ex) {
            cout << ex.what();
        };
    }
}
void DataBase:: find(const vector<string> args) {
    date dt;
    stringstream ss(args[1]);
    try{
        ss >> dt;
        } catch (runtime_error& ex) {
            cout << ex.what();
        };
    for (auto& l : pair[dt]) {
        cout << l << "\n";
    }
}
void DataBase:: print() {
    
    for (auto& t : pair) {
        for (auto& m : t.second) {
            cout << t.first << " " << m << endl;
        }
    }
}

