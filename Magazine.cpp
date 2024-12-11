#include "Magazine.h" // Include the header file for the Magazine class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash collected by the cashier

// Default constructor for the Magazine class, initializing base class and company name
Magazine::Magazine() : Books(), company("") {}

// Parameterized constructor for the Magazine class
Magazine::Magazine(string companyName, int stockCount, string titleName, string genreType, string authorName, double sellingPrice, double storePrice)
    : Books(stockCount, titleName, genreType, authorName, sellingPrice, storePrice), company(companyName) {}

// Method to get the title of the magazine (returns the company name)
string Magazine::getTitle() { return company; }

// Method to sell a specified quantity of the magazine
void Magazine::sellMagazine(int quantity) {
    // Check if the requested quantity is available
    if (checkavailability(quantity)) {
        stock -= quantity; // Reduce the stock by the quantity sold
        cout << quantity << " copies of magazine \"" << company << "\" sold." << endl;
    } else {
        cout << "Sorry, magazine \"" << company << "\" is out of stock." << endl; // Notify if out of stock
    }
}

// Method to add a subscriber to the magazine
void Magazine::addSubscriber(string name, string magazineName, int contact) {
    // Insert the subscriber's details into the subscribers map
    subscribers.insert(make_pair(name, make_pair(magazineName, contact)));
    cout << name << " subscribed to \"" << magazineName << "\" company magazine." << endl; // Confirmation message
}

// Method to display all subscribers of the magazine
void Magazine::displaySubscribers() {
    // Check if there are no subscribers
    if (subscribers.empty()) {
        cout << "No subscribers :(" << endl; // Notify if there are no subscribers
        return;
    }
    // Iterate through the subscribers map and display each subscriber's details
    for (const auto& item : subscribers) {
        cout << "Magazine: " << item.second.first << ", Subscriber name: " << item.first << ", Subscriber contact number: " << item.second.second << endl;
    }
}