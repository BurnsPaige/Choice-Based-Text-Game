#pragma once
#include <string>
#include <iostream>
#include <limits>
#include <map>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;

// Color Constants
const string SAMMY = "\033[32m";
const string AVA = "\033[35m";
const string RESET = "\033[0m";
const string TIME = "\033[93m";
const string INVALID = "\033[31m";
const string NPC = "\033[0m";
const string ITEM = "\033[33m";


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



inline void continue_program() {
    std::cout << "Press Enter to Continue..." << std::endl;

    // Check if there is already a newline or other characters in the buffer
    if (std::cin.rdbuf()->in_avail() > 0) {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Now wait for the user's fresh Enter press
    std::cin.get();
}

inline void dialogue(string text, string color = RESET, int speed = 50) {
    cout << color; 
    for (char c : text) {
        cout << c << flush; 
        this_thread::sleep_for(chrono::milliseconds(speed));
    }
    cout << RESET << endl; 
}

// Helper function to add vertical spacing
inline void clearScreen() {
    // Prints 10 newline characters
    std::cout << std::string(30, '\n');
}

