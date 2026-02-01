// Code and Game by Paige Burns
// Started 1/29/2026
// Finished TBD

#include "GameStages.h"
#include "Utils.h"
#include "Inventory.h"

map<string, Item> playerInventory;

int main() {
    initInventory();
    start_menu();
    return 0;
}
