#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <map>
#include <chrono>
#include <thread>

using namespace std;

// Color Constants
const string SAMMY = "\033[32m";
const string AVA = "\033[35m";
const string RESET = "\033[0m";
const string TIME = "\033[93m";
const string INVALID = "\033[31m";


inline string toLowerStr(string s) {
    for (char& c : s) {
        c = tolower(c);
    }
    return s;
}

inline void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

extern map<string, bool> playerInventory;


inline void initInventory() {
    playerInventory["Cassette"] = false;
    playerInventory["Key_Attic"] = false;
    playerInventory["Key_Basement"] = false;
    playerInventory["Note_1"] = false;
}

inline void showInventory() {
    cout << "\n--- CURRENT INVENTORY ---" << endl;
    bool empty = true;

    
    for (auto const& pair : playerInventory) {
        if (pair.second) { 
            cout << "- " << pair.first << endl;
            empty = false;
        }
    }

    if (empty) {
        cout << "(Your pockets are empty)" << endl;
    }
    cout << "-------------------------\n" << endl;
}


inline void continue_program() {
    cout << "Press Enter to Continue..." << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

inline void dialogue(string text, string color = RESET, int speed = 100) {
    cout << color; 
    for (char c : text) {
        cout << c << flush; 
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    cout << RESET << endl; 
}

