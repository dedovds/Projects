#include "DataBase1.cpp"
#include "Operators.cpp"

using namespace std;

int main() {
    string s, s1;
    int c = 0;
    DataBase db;
    vector<string> args;
    while(getline(cin, s)) {
        stringstream ss(s);
        while(getline(ss, s1, ' ')) {
            args.push_back(s1);
            c++;
        }
        if (args[0] == "Add") {
            db.add(args);
        }
        else if (args[0] == "Del") {
            db.del(args, c);
        }
        else if (args[0] == "Find") {
            db.find(args);
        }
        else if (args[0] == "Print") {
            db.print();
        }
        else {
            cout << "Unknown command: " << args[0]; 
            return 0;
        }
        args.clear();
        c = 0;

    }
    return 0;
}