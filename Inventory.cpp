#include "Inventory.h"
#include "Utils.h"

using namespace std;

// DEFINITION: creates the map in memory
extern map<string, Item> playerInventory;

void initInventory() {
    playerInventory["Cassette"] = { false, "There is tape stuck to the front. It Reads: 'Pilot'." };
    playerInventory["Attic Key"] = { false, "A Copper Key, it looks like it fits into the ATTIC lock." };
    playerInventory["Basement Key"] = { false, "A small, silver key that looks like it fits into the BASEMENT lock." };
    playerInventory["Book Scrap 1"] = { false, " It Reads: 'The next day, a wolf happened to pass by the lane where the three little pigs lived and he saw the straw house, and he smelled the pig inside. He thought the pig would make a mighty fine meal and his mouth began to water.'" };
    playerInventory["Grandma's Letter"] = { false, "A letter instructing you to stay in her house for a few days, before deciding on selling it or not." };
    playerInventory["Book Scrap 2"] = { false, "It Reads: 'So he knocked on the door and said: Little pig! Little pig! Let me in! Let me in! But the little pig saw the wolf's big paws through the keyhole, so he answered back: '" };
    playerInventory["Sticky Note"] = { false, "(208) 886-0178" };
    playerInventory["Flashlight"] = { false, "This seems like it'll come in handy!" };
    playerInventory["Gaming Magazine"] = { false, "The front page reads PUT DIRECTIONS HERE." };
    playerInventory["Andy's Journal"] = { false, "The pages at the back... are strange to say the least." };
    playerInventory["Obituaries"] = { false, "Two obituaries, the first man died in 1979 the other died in 1980." };

}

void showInventory() {
    // 1. Clear buffer junk
    cin.clear();
    while (cin.rdbuf()->in_avail() > 0) cin.ignore();

    cout << "\n--- CURRENT INVENTORY ---" << endl;

    vector<string> itemsInPockets;
    for (auto const& pair : playerInventory) {
        if (pair.second.hasItem) {
            itemsInPockets.push_back(pair.first);
        }
    }

    if (itemsInPockets.empty()) {
        cout << "(Your pockets are empty)" << endl;
        cout << "-------------------------\n" << endl;
        cout << "Press Enter to return...";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Wait for Enter
        cin.get();
        return;
    } // Braced fixed here

    for (int i = 0; i < (int)itemsInPockets.size(); i++) {
        cout << i + 1 << ". " << itemsInPockets[i] << endl;
    }
    cout << "-------------------------\n" << endl;

    cout << "Enter a number to examine (or 0 to exit): ";
    int choice;
    if (!(cin >> choice)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (choice > 0 && choice <= (int)itemsInPockets.size()) {
        string selectedName = itemsInPockets[choice - 1];
        clearScreen();
        cout << "\n=================================================================" << endl;
        cout << "NAME: " << selectedName << endl;
        cout << "DESCRIPTION: " << playerInventory[selectedName].description << endl;
        cout << "=================================================================" << endl;

        // This makes sure they can READ it before the screen wipes
        continue_program();

        // Return to inventory list so they can see other items
        showInventory();
    }
}
