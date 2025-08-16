#include <iostream>
#include <typeinfo>
#include <string>
using namespace std;

string get_string(string prompt) {
    cout << prompt;
    string text; cin >> text;

    return text;
}

int get_int(string prompt) {
    int i;
    while (true) {
        cout << prompt;
        string input; cin >> input;
        try {
            i = stoi(input);
            break;
        } catch (...) {}
    } 

    return i;
}