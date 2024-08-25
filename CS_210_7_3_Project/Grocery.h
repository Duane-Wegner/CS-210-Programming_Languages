/**
 * This program will manage grocery item frequencies, allow users to query item frequencies,
 * print all frequencies, and display a histogram of item frequencies. It will also backup
 * the data to a file.
 * Author: Duane Wegner
 * Date: August 13, 2024
 */

#ifndef GROCERY_H
#define GROCERY_H

#include <map>
#include <string>

using namespace std;

class Grocery {
private:
    map<string, int> itemFrequency;  // Map to store the frequency of each grocery item

    /**
     * This method reads data from a file and updates the frequency count of each item.
     * Parameter filename, The name of the file to read data from. (string)
     * Return, This method does not return a value.
     */
    void readDataFromFile(const string& filename);

    /**
     * This method writes the item frequencies to a backup file.
     * Parameter filename, The name of the backup file to write to. (string)
     * Return, This method does not return a value.
     */
    void writeBackupFile(const string& filename);

public:
    /**
     * This constructor initializes the Grocery object by reading data from the input file
     * and writing to the backup file.
     * Return, This constructor does not return a value.
     */
    Grocery();

    /**
     * This method prints the frequency of a specific item.
     * Parameter item, The name of the item to query. (string)
     * Return, This method does not return a value.
     */
    void printItemFrequency(const string& item) const;

    /**
     * This method prints the frequencies of all items.
     * Return, This method does not return a value.
     */
    void printAllFrequencies() const;

    /**
     * This method prints a histogram of item frequencies.
     * Return, This method does not return a value.
     */
    void printHistogram() const;
};

#endif // GROCERY_H
