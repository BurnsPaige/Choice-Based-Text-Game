#include "GameStages.h"
#include "Utils.h"
#include <chrono>
#include <thread>

using namespace std;

void start_menu() {
    int start;
    cout << "********************************************************************" << endl;
    cout << "Start Game = 1" << endl;
    cout << "Exit Game = 0" << endl;
    cout << "********************************************************************" << endl;
    cin >> start;

    if (start == 1) {
        sam_house();
    }
    else if (start == 0) {
        abort();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        start_menu();
    }
}

void sam_house() {
    int action_1;
    
    cout << endl << "********************************************************************" << endl;
    cout << "You wake up in your room. Sun filtering in past your curtains. Your eyes still sting from crying." << endl;
    cout << "********************************************************************" << endl;
    cout << "1. Check Inventory" << endl << "2. Use Computer" << endl;
    cin >> action_1;

    if (action_1 == 1) {
        showInventory();
        sam_house();
    }
    else if (action_1) {
        computer();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        sam_house();
    }

}

void computer() {
    string email;
    
    cout << endl << "********************************************************************" << endl;
    cout << "You have 1 new email." << endl;
    cout << "********************************************************************" << endl;
    cout << "Check Email? (Y/N)" << endl;
    cin >> email;
    string email_L = toLowerStr(email);
    clearInputBuffer();

    if (email_L == "y") {
        call_1();
    }
    else if (email_L == "n") {
        sam_house();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        computer();
    }
}


void call_1() {
    string funeral;
    cout << endl << "********************************************************************" << endl;
    cout << "New Message: " << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Subject: Samantha Moore's Will" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    cout << "Hello, " << endl << "I am Ava Pearson, your grandmother's estate attorney. I am contacting you about the house you have recieved in your grandmother's will. The property at 989 6th St, Welstead, Idaho, which has been willed to you." << endl << "Please contact me at (***) ***-**** to set up a meeting time so we can discuss this portion of the estate left to you." << endl;
    cout << "Sincerely," << endl << "Ava Pearson" << endl;
    cout << "********************************************************************" << endl;
    continue_program();
    cout << "********************************************************************" << endl;
    dialogue("Samantha 'Sammy' Madison: So... she left me the house and EVERYTHING inside?", SAMMY);
    dialogue("Ava Pearson: Yes, she also left you a note, in the will, she wanted me to give it to you in person.", AVA);
    dialogue("Samantha 'Sammy' Madison: Her funeral is in 3 days. It's in the next town over from where the property is... I think... I can meet you there.", SAMMY);
    dialogue("Ava Pearson: That sounds alright to me. I'll see you then Ms. Samantha.", AVA);
    dialogue("Samantha 'Sammy' Madison: Sammy... please call me Sammy...", SAMMY);
    cout << "********************************************************************" << endl;

    cout << endl << "Attend Funeral? Y/N" << endl;
    cin >> funeral;
    string funeral_L = toLowerStr(funeral);
    clearInputBuffer();

    if (funeral_L == "y") {
        funeral_room();
    }
    else {
        abort();
    }
}

void funeral_room() {
    string funeral_decision;
    cout << endl << "********************************************************************" << endl;
    cout << TIME << "Funeral 14:00 4/16/2024" << RESET << endl;
    cout << "********************************************************************" << endl;
    cout << "Who do you speak to?" << endl << "Relative" << endl << "Ava Pearson" << endl;

    getline(cin >> ws, funeral_decision);
    string funeral_DL = toLowerStr(funeral_decision);

    if (funeral_DL == "relative") {
        // Add relative logic here
    }
    else if (funeral_DL == "ava" || funeral_DL == "ava pearson") {
        // Add ava logic here
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        funeral_room();
    }
}

void funeral_relative() {
    int relative;

}
