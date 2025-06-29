/**
 * Author: Lukas Cochran
 * Date: June 19th, 2025
 *
 * This main file contains the main function that operates the program with switch statements. There includes multiple
 * functions that interact with the main function to create data files and count items in files.
 *
 */

#include "GroceryStore.cpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <fstream>
#include <vector>


using namespace std;

vector<GroceryStore> list;

std::string startHelper(int num){
    std:: string result;
    for (int i = 0; i < num; i++)
    {
        result += "$";
    }

    return result;
}

/**
 * Function creates the backup file "frequency.dat". This holds the name and quantity values.
 * @param list
 * @returns creates .txt file list
 */
void backupData(const std::vector<GroceryStore>& list) {
    std::ofstream outFile("frequency.dat");  // specifies name of the backup file
    if (outFile.is_open()) {
        for (auto item : list) {  // iterates through the list then adds the values to the file
            outFile << item.getItemName() << " " << item.getItemQuantity() << "\n";
        }
    } else { // print error if no file was opened
        cout << "Error creating backup file." << endl;
    }
}

/**
 * This iterates through each line of the file, counts the number of times each name appears.
 * @param filename
 * @returns GroceriesList
 *
 */
std::vector<GroceryStore> readGroceriesFromFile(const std::string filename) {
  std::vector<GroceryStore> GroceriesList; // declares list of groceries
  std::map<std::string, int> frequencyMap; // declares map

  std::ifstream file(filename);

  if (file.is_open()) {
    std::string line;
    while (std::getline(file, line)) { // iterates through each line then adds 1 each time a related value is found
      frequencyMap[line]++;
    }

    for (auto pair : frequencyMap) { // constructs a Grocery object
      GroceriesList.push_back({pair.first, pair.second});
    }
  } else { // output error if file not found
    std::cerr << "Error: could not open file " << filename << std::endl;
  }

  return GroceriesList; // returns the list of Grocery objects from the input file
}

/**
 *
 * @param list
 * @param name
 * @returns the item with corresponding name
 */
GroceryStore findItem(vector<GroceryStore> list, std::string name){
    for (int i = 0; i<list.size(); i++) { // linear search that returns a Grocery object
        if (list[i].getItemName() == name) {
        return list[i];
        }
    }
    return GroceryStore("notfound", 0); // catches error if string is not found
}

/**
 *
 * Main function that displays menu and handles inputs from user. Also handles input from .txt file.
 * No parameters
 *
 */
int main() {
    vector<GroceryStore> list = readGroceriesFromFile("CS_210_ProjectThreeInputFile.txt"); // initializes and constructs list

    backupData(list); // backs up the data
    std::string input;
    int choice;

    while (choice != 4) {
        cout << "\nMENU SELECTIONS\n";
        cout << "*********************\n";
        cout << "1. Search for an item\n";
        cout << "2. Print frequency list\n";
        cout << "3. Print histogram\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;
        switch (choice) {
            case 1: {
                std::string item;
                cout << "Enter item to search for: ";
                cin >> item;
                int index = 0;
                GroceryStore listItem = findItem(list, item);
                if (listItem.getItemName() == item)
                {
                    cout << listItem.getItemQuantity()<< " times" << endl; // lists quantity available of item entered
                }
                else
                {
                    cout << "Error Item not Found" << endl; // if item does not exist in the list
                }
                break;

            }
            case 2: {
                // writes all groceries and the number of times they are listed in the file
                for(auto item : list)
                {
                    cout << setw(12) << item.getItemName() << setw(5) << item.getItemQuantity() << endl;

                }
                break;
            }
            // writes all groceries and the number of times they were listed in the file by using the "$" symbol
            case 3: {
                for(auto item: list)
                    cout << item.getItemName() << " " << startHelper(item.getItemQuantity()) << endl;
                break;
            }
            case 4: {
                cout << "Exiting program.\n";
                break;
            }
            default: { // catches invalid input
                cout << "Invalid choice. Try again.\n";
                continue;
            }
        }
    }
}