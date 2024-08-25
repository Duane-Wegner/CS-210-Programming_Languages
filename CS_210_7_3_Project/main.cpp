/**
 * This program will manage grocery item frequencies, allow users to query item frequencies,
 * print all frequencies, and display a histogram of item frequencies. It will also backup
 * the data to a file.
 * Author: Duane Wegner
 * Date: August 13, 2024
 */

#include "Grocery.h"
#include <iostream>

int main() {
    Grocery grocery;  // Create a Grocery object which reads data and writes backup

    int choice;  // Variable to store user menu choice
    string item;  // Variable to store the item name for querying

    do {
        cout << "Menu:" << endl;
        cout << "1. Look up an item's frequency" << endl;
        cout << "2. Print all item frequencies" << endl;
        cout << "3. Print item frequency histogram" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;  // Get user choice

        switch (choice) {
        case 1:
            cout << "Enter the item: ";
            cin >> item;  // Get the item name from user
            grocery.printItemFrequency(item);  // Print the frequency of the item
            break;
        case 2:
            grocery.printAllFrequencies();  // Print all item frequencies
            break;
        case 3:
            grocery.printHistogram();  // Print the histogram of item frequencies
            break;
        case 4:
            cout << "Exiting the program." << endl;  // Exit message
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;  // Error message for invalid choice
            break;
        }
    } while (choice != 4);  // Repeat the menu until the user chooses to exit

    return 0;  // End of the program
}
