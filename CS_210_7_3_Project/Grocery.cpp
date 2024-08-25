/**
 * This program will manage grocery item frequencies, allow users to query item frequencies,
 * print all frequencies, and display a histogram of item frequencies. It will also backup
 * the data to a file.
 * Author: Duane Wegner
 * Date: August 13, 2024
 */

#include "Grocery.h"
#include <fstream>
#include <iostream>

Grocery::Grocery() {
    readDataFromFile("CS210_Project_Three_Input_File.txt");  // Read data from input file
    writeBackupFile("frequency.dat");  // Write data to backup file
}

void Grocery::readDataFromFile(const string& filename) {
    ifstream file(filename);  // Open the file with the given filename
    if (!file) {  // Check if the file was successfully opened
        cerr << "Error: Could not open the file " << filename << endl;  // Print error message
        return;  // Exit the method if file cannot be opened
    }
    string item;
    while (file >> item) {  // Read each item from the file
        itemFrequency[item]++;  // Increment the frequency count for the item
    }
    file.close();  // Close the file
}

void Grocery::writeBackupFile(const string& filename) {
    ofstream file(filename);  // Open the file to write the backup
    for (const auto& entry : itemFrequency) {  // Iterate through all items in the map
        file << entry.first << ' ' << entry.second << endl;  // Write item and its frequency to the file
    }
    file.close();  // Close the file
}

void Grocery::printItemFrequency(const string& item) const {
    auto it = itemFrequency.find(item);  // Find the item in the map
    if (it != itemFrequency.end()) {  // Check if the item was found
        cout << item << ": " << it->second << endl;  // Print the item and its frequency
    }
    else {
        cout << item << " not found." << endl;  // Print message if the item is not found
    }
}

void Grocery::printAllFrequencies() const {
    for (const auto& entry : itemFrequency) {  // Iterate through all items in the map
        cout << entry.first << ": " << entry.second << endl;  // Print each item and its frequency
    }
}

void Grocery::printHistogram() const {
    for (const auto& entry : itemFrequency) {  // Iterate through all items in the map
        cout << entry.first << ' ';  // Print the item name
        for (int i = 0; i < entry.second; i++) {  // Loop to print the asterisks based on frequency
            cout << '*';  // Print an asterisk
        }
        cout << endl;  // Move to the next line after printing all asterisks
    }
}
