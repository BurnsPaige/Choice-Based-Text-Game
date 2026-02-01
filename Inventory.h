#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

struct Item {
    bool hasItem = false;
    std::string description;
};

// Declares the map exists elsewhere
extern std::map<std::string, Item> playerInventory;

void initInventory();
void showInventory();

#endif
