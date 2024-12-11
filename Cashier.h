#ifndef CASHIER_H // Include guard to prevent multiple inclusions of this header file
#define CASHIER_H

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

extern double cash; // Declaration of the global variable cash, defined elsewhere

class Cashier {
public:
    // Default constructor for the Cashier class
    Cashier();

    // Method to display the total cash collected by the cashier
    void displayTotalCash();
};

#endif // End of include guard