#include "Customer.h" // Include the header file for the Customer class
#include "Books.h"    // Include the header file for the Books class
#include "Magazine.h"  // Include the header file for the Magazine class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash collected by the cashier

// Default constructor for the Customer class
Customer::Customer() : name("") {}

// Parameterized constructor to initialize the Customer with a name
Customer::Customer(string n) : name(n) {}

// Method to add a book item to the customer's purchase history
void Customer::pushItembook(Books &item, int quantity) {
    // Add the book title and quantity to the purchase history
    purchase_hist.push_back(make_pair(item.getTitle(), quantity));
    // Output a message indicating the customer is checking availability
    cout << name << " checking if " << quantity << " copies of '" << item.getTitle() << "' are available." << endl;
}

// Method to add a magazine item to the customer's purchase history
void Customer::pushItemmag(Magazine &mag, int quantity) {
    // Add the magazine title and quantity to the purchase history
    purchase_hist.push_back(make_pair(mag.getTitle(), quantity));
    // Output a message indicating the customer is checking availability
    cout << name << " checking if " << quantity << " copies of '" << mag.getTitle() << "' are available." << endl;
}

// Method to display the customer's purchase history
void Customer::showPurchase_hist() {
    cout << "Purchase history:" << endl; // Header for the purchase history
    if (purchase_hist.empty()) { // Check if the purchase history is empty
        cout << "Didn't buy anything yet." << endl; // Inform the user if no purchases have been made
        return; // Exit the method
    }
    // Iterate through the purchase history and display each entry
    for (auto &entry : purchase_hist) {
        cout << entry.first << " - " << entry.second << " copies" << endl; // Print the title and quantity
    }
}