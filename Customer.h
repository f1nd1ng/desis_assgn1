#ifndef CUSTOMER_H // Include guard to prevent multiple inclusions of this header file
#define CUSTOMER_H

#include "Magazine.h" // Include the header file for the Magazine class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

extern double cash; // Declaration of the global variable cash, defined elsewhere

class Books; // Forward declaration of the Books class to be used in the Customer class

class Customer {
protected:
    string name; // Customer's name
    int quant; // Quantity of items (not used in the provided code)
    vector<pair<string, int>> purchase_hist; // Vector to store purchase history as pairs of item titles and quantities

public:
    // Default constructor for the Customer class
    Customer();

    // Parameterized constructor to initialize the Customer with a name
    Customer(string n);

    // Virtual method to add a book item to the customer's purchase history
    virtual void pushItembook(Books &item, int quantity);

    // Virtual method to add a magazine item to the customer's purchase history
    virtual void pushItemmag(Magazine &mag, int quantity);

    // Virtual method to display the customer's purchase history
    virtual void showPurchase_hist();
};

#endif // End of include guard