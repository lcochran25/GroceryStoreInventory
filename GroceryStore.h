/**
 * Author: Lukas Cochran
 * Date: June 19th, 2025
 *
 * This header file contains public and private members for the Grocery Store class. Here we create a constructor that takes a name
 * and quantity argument. We also set up accessors and mutators.
 */

#ifndef GROCERYSTORE_H
#define GROCERYSTORE_H

#include <string>

class GroceryStore {
public:
    // Constructor
    GroceryStore(std::string name, int quantity);

    // Accessors
    std::string getItemName();
    int getItemQuantity();

    // Mutators
    void setItemName(std::string itemName);
    void setItemQuantity(int itemQuantity);

private:
    std::string name;
    int quantity;
};




#endif //GROCERYSTORE_H
