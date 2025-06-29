/**
 * Author: Lukas Cochran
 * Date: June 19th, 2025
 *
 * This file instantiates the mutators and accessors so we can set and get the name and quantity for items
 * on the list.
 *
 */

#include "GroceryStore.h"
#include <sstream>
#include <string>

using namespace std;

// Constructor
GroceryStore::GroceryStore(string itemName, int itemQuantity) {
    name = itemName;
    quantity = itemQuantity;
}

// Accessors
std::string GroceryStore::getItemName() {
    return name;
}

int GroceryStore::getItemQuantity() {
    return quantity;
}

// Mutators
void GroceryStore::setItemName(std::string itemName) {
    name = itemName;
}

void GroceryStore::setItemQuantity(int itemQuantity) {
    quantity = itemQuantity;
}