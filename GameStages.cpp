#include "GameStages.h"
#include "Utils.h"
#include "Inventory.h"
#include <chrono>
#include <thread>

using namespace std;


// START MENU
void start_menu() {
    int start;
    cout << "********************************************************************" << endl;
    cout << "Start Game = 1" << endl;
    cout << "Exit Game = 0" << endl;
    cout << "********************************************************************" << endl;
    cin >> start;

    if (start == 1) {
        clearScreen();
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


//SAMMY HOUSE
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
        clearScreen();
        computer();
        
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        sam_house();
    }

}


//COMPUTER
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
        clearScreen();
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



//EMAIL
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
    dialogue("Samantha 'Sammy' Madison: Sammy... please call me Sammy...", SAMMY,100);
    cout << "********************************************************************" << endl;

    cout << endl << "Attend Funeral? (Y/N)" << endl;
    cin >> funeral;
    string funeral_L = toLowerStr(funeral);
    clearInputBuffer();

    if (funeral_L == "y") {
        clearScreen();
        funeral_room();
    }
    else {
        abort();
    }
}


//FUNERAL
void funeral_room() {
    int funeral_decision;
    cout << endl << "********************************************************************" << endl;
    cout << TIME << "Funeral 14:00 4/16/2024" << RESET << endl;
    cout << "********************************************************************" << endl;
    cout << "Who do you speak to?" << endl << "1. Relatives" << endl << "2. Ava Pearson" << endl;

    cin >> funeral_decision;
    

    if (funeral_decision == 1) {
        clearScreen();
        funeral_relative();
    }
    else if (funeral_decision == 2) {
        clearScreen();
        funeral_ava();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        funeral_room();
    }
}


// SPEAK TO RELATIVES
void funeral_relative() {
    int relative;
    cout << endl << "********************************************************************" << endl;
    cout << "There are numerous cousins, aunts, uncles, and some people you have never meet spread throughout the room." << endl <<
        "Your attention is drawn to your parents, who seem to be talking to a great-aunt you meet once." << endl <<
        "You can also see your favorite aunt and uncle, who appear to have only just arrived." << endl;
    cout << "********************************************************************" << endl;
    cout << "Who should you speak to?" << endl << "1. Mother" << endl << "2. Father" << endl << "3. Aunt" << endl << "4. Uncle" << endl << "5. Return" << endl;
    cin >> relative;

    if (relative == 1) {
        cout << endl << "********************************************************************" << endl;
        dialogue("Mom: Sammy, how are you doing baby?", NPC);
        dialogue("Sammy Madison: Hi Mom. I'm doing ok, how are you doing?", SAMMY);
        dialogue("Mom: Oh, fine, your Father and I have been busy. Your Grandmother never wanted a big funeral. We tried to keep everything small, funerals are so expensive these days though.", NPC);
        dialogue("Mom: It was more expensive than your Grandfather's funeral at least.", NPC);
        cout << "********************************************************************" << endl;
        continue_program();
        funeral_relative();
    }
    else if (relative == 2) {
        cout << endl << "********************************************************************" << endl;
        dialogue("Dad: Hey Sammy, you doing alright?", NPC);
        dialogue("Sammy Madison: Hi Dad. Ya I'm ok. What about you?", SAMMY);
        dialogue("Dad: I'm doing alright. Just trying to be there for your Mother. Did the Estate Attorney talk to you yet?", NPC);
        dialogue("Sammy Madison: Ya we spoke on the phone. Grandma gave me the house. I plan on checking it out tomorrow, and staying there... to look through everything.", SAMMY);
        dialogue("Dad: Let me know if you need any help.", NPC);
        cout << "********************************************************************" << endl;
        continue_program();
        funeral_relative();
    }
    else if (relative == 3) {
        cout << endl << "********************************************************************" << endl;
        dialogue("Aunt Caroline: Sammy! How are you doing sweetheart?", NPC);
        dialogue("Sammy Madison: Hi Auntie Carol. I'm doing... ok.", SAMMY);
        dialogue("Aunt Caroline: Oh, honey, I know this is probably so difficult for you. I know it is for me and your Mother.", NPC);
        dialogue("Sammy Madison: Ya... ya...", SAMMY,100);
        cout << "********************************************************************" << endl;
        continue_program();
        funeral_relative();
    }
    else if (relative == 4) {
        cout << endl << "********************************************************************" << endl;
        dialogue("Uncle Morris: Hey Sam, how're you holding up? I know you two were close. Closer than your cousins were to her.", NPC);
        dialogue("Sammy Madison: I guess I'm doing alright. I'm just mad that I didn't get to say good-bye... Y'know?", SAMMY);
        dialogue("Uncle Morris: Ya that's understandable.", NPC);
        dialogue("Uncle Morris: Look kid... I'm sure she knew. That you would've wanted to be there. Her goddamn caretaker didn't tell any of us. She knows we ALL would've been there if we were told about how... bad... she was doing.", NPC);
        dialogue("Sammy Madison: ...", SAMMY,100);
        cout << "********************************************************************" << endl;
        continue_program();
        funeral_relative();
    }
    else if (relative == 5) {
        clearScreen();
        funeral_room();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        funeral_relative();
    }
}


//SPEAK TO AVA
void funeral_ava() {
    cout << endl << "********************************************************************" << endl;
    dialogue("Ava Pearson: Ms. Madison, I see you've arrived. Would you like to discuss the letter now?", AVA);
    dialogue("Sammy Madison: Yes, please.", SAMMY);
    dialogue("Ava Pearson: Alright.", AVA);
    dialogue("Ava Pearson: She left you this envelope. The keys to her house are inside. She also gave me explicit instructions that you should open the letter after the funeral.", AVA);
    dialogue("Sammy Madison: Oh. I see. Thank you...", SAMMY);
    dialogue("Ava Pearson: I am sorry for your loss Ms. Madison. Let me know if I can assist you in any manner regarding the property or the things inside.", AVA);
    cout << "********************************************************************" << endl;
    continue_program();
    
    playerInventory["Grandma's Letter"].hasItem = true;
    cout << "You have recieved " << ITEM << "Grandma's Letter" << RESET << "!" << endl;
   

    cout << endl << "You can now enter the property." << endl;
    continue_program();
    clearScreen();
    grand_house();

}

//GRANDMAS HOUSE MENU

void grand_main() {
    int grand_move;
    cout << endl << "********************************************************************" << endl;
    cout << "What will you do now?" << endl << "1. Front Room" << endl << "2. Bed Room" << endl << "3. Attic" << endl << "4. Basement" << endl << "5. Check Inventory" << endl;
    cout << "********************************************************************" << endl;
    cin >> grand_move;

    if (grand_move == 1) {
        clearScreen();
        grand_house();
    }
    else if (grand_move == 2) {
        clearScreen();
        grand_bed();
    }
    else if (grand_move == 3) {
        if (playerInventory["Attic Key"].hasItem) {
            clearScreen();
            grand_attic();
        }
        else {
            cout << "You try to open the door but it's locked." << endl;
            continue_program();
            grand_main();
        }
    }
    else if (grand_move == 4) {
        if (playerInventory["Basement Key"].hasItem) {
            clearScreen();
            //grand_basement();
        }
        else {
            cout << "The door doesn't budge. It's locked." << endl;
            continue_program();
            grand_main();
        }
    }
    else if (grand_move == 5) {
        showInventory();
        grand_main();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        grand_main();
    }
}

//MAIN ENTRANCE

void grand_house() {
    string key_grab;
    
   
    cout << endl << "********************************************************************" << endl;
    cout << "You enter into your Grandmother's house. It's the same as you remember from the last time you visited." << endl;
    cout << "Infront of you is the Entry Table. Ontop are TWO keys, one is silver and the other is copper." << endl;
    cout << "********************************************************************" << endl;
    cout << "Grab the Keys? (Y/N)" << endl;
    cin >> key_grab;
    string key_L = toLowerStr(key_grab);
    clearInputBuffer();

    if (key_L == "y") {
        if (playerInventory["Basement Key"].hasItem) {
            clearScreen();
            cout << ITEM << "There isn't anything to pick up. You already have the keys she left you." << RESET << endl;
            continue_program();
            clearScreen();
            cout << "You leave the Front Room and walk into the Main Hall." << endl;
            continue_program();
            clearScreen();
            grand_main();
        }
        else {
            clearScreen();
            cout << "You have recieved " << ITEM << "Basement Key" << RESET << "!" << endl;
            cout << "You have recieved " << ITEM << "Attic Key" << RESET << "!" << endl;
            playerInventory["Basement Key"].hasItem = true;
            playerInventory["Attic Key"].hasItem = true;
            continue_program();
            clearScreen();
            cout << "You leave the Front Room and walk into the Main Hall." << endl;
            continue_program();
            clearScreen();
            grand_main();
        }
        
    }
    else if (key_L == "n") {
        cout << "You leave the Front Room and walk into the Main Hall." << endl;
        continue_program();
        clearScreen();
        grand_main();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        grand_house();
    }
}

//BEDROOM

void grand_bed() {
    int sleep;
    
    cout << endl << "********************************************************************" << endl;
    cout << "You enter your Grandmother's Bedroom. This is where you will be sleeping during your stay." << endl;
    cout << "The bed is neatly made, and it still smells like her." << endl;
    cout << "********************************************************************" << endl;
    cout << "What do you want to do?" << endl << "1. Sleep" << endl << "2. Return" << endl;
    cin >> sleep;

    if (sleep == 1) {
        if (playerInventory["Flashlight"].hasItem) {
            //next day
        }
        else {
            cout << "You can't sleep yet. You feel like your missing something." << endl;
            grand_bed();
        }
    }
    else if (sleep == 2) {
        clearScreen();
        grand_main();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        grand_bed();
    }

}

//ATTIC

void grand_attic() {
    int searchA;

    cout << endl << "********************************************************************" << endl;
    cout << "You enter into the Attic. Dust motes are visible in the sunlight that comes from the single window that faces the front of the house."<< endl;
    cout << "There are boxes littering the place, but luckily they seem to be organized and labeled." << endl;
    cout << "********************************************************************" << endl;
    cout << "Where will you search?"<< endl << "1. 'Pilot' Boxes"<< endl << "2. 'Kids' Boxes" << endl << "3. 'Richard' Boxes"<< endl<< "4. Return"<< endl;
    cin >> searchA;

    if (searchA == 1) {
        clearScreen();
        pilot_box();
    }
    else if (searchA == 2) {
        clearScreen();
        kids_box();
    }
    else if (searchA == 3) {
        clearScreen();
        rich_box();
    }
    else if (searchA == 4) {
        clearScreen();
        grand_main();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        grand_attic();
    }
}

//PILOT BOXES ATTIC
void pilot_box() {
    int p_search;
    
    cout << endl << "********************************************************************" << endl;
    cout << "There are three boxes, taped and labeled as 'Pilot'. " << endl;
    cout << SAMMY << "I remember that Grandma told me about a cartoon she had worked on when my Mom was little. This must be the stuff they used to make the pilot episode of the show." << RESET << endl;
    cout << "********************************************************************" << endl;
    cout << "Which box should I search?" << endl << "1" << endl << "2" << endl << "3" << endl << "0. Return" << endl;
    cin >> p_search;

    if (p_search == 1) {
        cout << endl << "The box is filled with paper, pencils, and very old paint. There doesn't appear to be much here except for what was used to make the first episode." << endl;
        cout << SAMMY << "I wonder if there are more episodes in the Basement?" << RESET << endl;
        continue_program();
        pilot_box();
    }
    else if (p_search == 2) {

        if (playerInventory["Andy's Journal"].hasItem) {
            cout << endl << "You already grabbed the journal. There isn't anything else of interest in this box." << endl;
            pilot_box();
        }
        else {
            cout << endl << "After a quick search, you find a journal with a name you don't recognize on it. 'Andy' is not the name of any relative that you know of... " << endl;
            playerInventory["Andy's Journal"].hasItem = true;
            cout << "You have picked up " << ITEM << "Andy's Journal" << RESET << "!" << endl;
            continue_program();
            pilot_box();
        }

    }
    else if (p_search == 3) {

        if (playerInventory["Cassette"].hasItem) {
            cout << endl << "You grabbed the Cassette from this box already. There isn't anything else of interest." << endl;
            pilot_box();
        }
        else {
            cout << endl << "Sitting at the top of the box is a cassette tape labeled as 'Pilot'. This must be the acutal cartoon your Grandmother made!" << endl;
            playerInventory["Cassette"].hasItem = true;
            cout << "You have picked up " << ITEM << "Cassette" << RESET << "!" << endl;
            continue_program();
            pilot_box();
        }
    }
    else if (p_search == 0) {
        clearScreen();
        grand_attic();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        pilot_box();
    }

}

//KIDS BOXES ATTIC
void kids_box() {
    int k_search;
    
    cout << endl << "********************************************************************" << endl;
    cout << "There are four boxes, taped and labeled as 'Kids'. " << endl;
    cout << SAMMY << "These must be Mom and Aunt Caroline's things from when they were younger. I know they took alot of their stuff with them when they moved out, so this must be the rest of the things they left." << RESET<< endl;
    cout << "********************************************************************" << endl;
    cout << "Which box should I search?" << endl << "1" << endl << "2" << endl << "3" << endl << "4" << endl << "0. Return" << endl;
    cin >> k_search;

    if (k_search == 1) {

        if (playerInventory["Book Scrap 1"].hasItem) {
            cout << endl << "You already found the ripped out page of a book in here." << endl;
            kids_box();
        }
        else {
            cout << endl << "You find the page of a children's book that has very clearly been ripped out. The page is ripped in half, leaving just the text." << endl;
            playerInventory["Book Scrap 1"].hasItem = true;
            cout << "You have picked up " << ITEM << "Book Scrap 1" << RESET << "!" << endl;
            continue_program();
            kids_box();
        }

    }
    else if (k_search == 2) {
        cout << endl << "This box doesn't appear to have anything interesting inside. It does have some old doll clothes though!" << endl;
        cout << SAMMY << "I wonder if Mom would want these back?" << RESET << endl;
        continue_program();
        kids_box();
    }
    else if (k_search == 3) {
        cout << endl << "Nothing of importance here, except for Aunt Caroline's baby photos. She looked so cute!" << endl;
        cout << SAMMY << "I think I should give these back to her." << RESET << endl;
        continue_program();
        kids_box();
    }
    else if (k_search == 4) {
        
        if (playerInventory["Gaming Magazine"].hasItem) {
            cout << endl << "You already found the magazine in this box. Moving deeper in, however, you find an Atari. Neat!" << endl;
            kids_box();
        }
        else {
            cout << endl << "In the box are toys and books. However, at the bottom you find a gaming magazine. You can't recognize the game from the front page but it looks like its giving readers a cheat code to skip past a hard level!" << endl;
            playerInventory["Gaming Magazine"].hasItem = true;
            cout << "You have picked up " << ITEM << "Gaming Magazine" << RESET << "!" << endl;
            continue_program();
            kids_box();
        }

    }
    else if (k_search == 0) {
        clearScreen();
        grand_attic();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        kids_box();
    }

}


//RICHARDS BOXES ATTIC
void rich_box() {
    int r_search;
    
    cout << endl << "********************************************************************" << endl;
    cout << "There are two boxes, taped and labeled as 'Richard'. That's my Grandfather's name, these must be his belongings. " << endl;
    cout << SAMMY << "Grandma took it so hard when he died. I think Dad and Uncle Morris moved his things up here for her." << RESET << endl;
    cout << "********************************************************************" << endl;
    cout << "Which box should I search?" << endl << "1" << endl << "2" << endl << "0. Return" << endl;
    cin >> r_search;

    if (r_search == 1) {
       
        cout << endl << "There are pictures of your Grandfather in this box. Some are just of him, while others have the whole family." << endl;
        cout << SAMMY << "I think I'll take this box home with me." << RESET << endl;
        continue_program();
        rich_box();
    }
    else if (r_search == 2) {

        if (playerInventory["Obituaries"].hasItem) {
            cout << endl << "You already found the obituaries in this box. You can look at them in better detail later." << endl;
            rich_box();
        }
        else {
            cout << endl << "In your Grandfather's belongings are two pieces of paper. They appear to be obituaries, possibly for friends of his?" << endl;
            playerInventory["Obituaries"].hasItem = true;
            cout << "You have picked up " << ITEM << "Obituaries" << RESET << "!" << endl;
            continue_program();
            rich_box();
        }

    }
    else if (r_search == 0) {
        clearScreen();
        grand_attic();
    }
    else {
        cout << INVALID << "Invalid Choice." << RESET << endl;
        rich_box();
    }
}
