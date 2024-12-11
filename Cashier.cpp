#include "Cashier.h" // Include the header file for the Cashier class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash collected by the cashier

// Default constructor for the Cashier class
Cashier::Cashier() {}

// Method to display the total cash collected by the cashier
void Cashier::displayTotalCash() {
    // Output the total cash in the cashier
    cout << "Total cash in cashier: Rs " << cash << std::endl; // Print the total cash amount
}