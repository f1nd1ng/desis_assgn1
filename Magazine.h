#ifndef MAGAZINE_H // Include guard to prevent multiple inclusions of this header file
#define MAGAZINE_H

#include "Books.h" // Include the header file for the Books class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

extern double cash; // Declaration of the global variable cash, defined elsewhere

// Magazine class inherits from the Books class
class Magazine : public Books {
private:
    string company; // The company name that publishes the magazine
    // Map to store subscribers with their name as the key and a pair of magazine name and phone number as the value
    unordered_map<string, pair<string, int>> subscribers; // name of subscriber, name of magazine, phone number of subscriber

public:
    // Default constructor for the Magazine class
    Magazine();

    // Parameterized constructor for the Magazine class
    Magazine(string companyName, int stockCount, string titleName, string genreType, string authorName, double sellingPrice, double storePrice);

    // Method to get the title of the magazine (returns the company name)
    string getTitle();

    // Method to sell a specified quantity of the magazine
    void sellMagazine(int quantity);

    // Method to add a subscriber to the magazine
    void addSubscriber(string name, string magazineName, int contact);

    // Method to display all subscribers of the magazine
    void displaySubscribers();
};

#endif // End of include guard