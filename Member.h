#ifndef MEMBER_H // Include guard to prevent multiple inclusions of this header file
#define MEMBER_H

#include "Customer.h" // Include the header file for the Customer class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash collected by the cashier

// Member class inherits from the Customer class
class Member : public Customer {
private:
    static int count; // Static counter for generating unique member IDs
    int id; // Unique ID for each member
    string dob; // Date of birth in MM-DD format
    string password; // Password for member authentication
    bool member; // Membership status (active or inactive)
    double discountRate; // Regular discount rate for members (5%)
    double birthdayDiscountRate; // Discount rate for members during their birthday month (15%)
    int membershipExpiryYear; // Year when the membership expires

public:
    // Constructor to initialize a Member object with name, password, and date of birth
    Member(std::string n, string p, string db);

    // Method to get the member's unique ID
    int getID();

    // Method to get the member's name
    string getName();

    // Method to check if the membership has expired
    bool membershipExpired();

    // Method to activate the membership and set the expiry year
    void activateMembership(double membershipFee);

    // Method to update the member's password
    void updatePassword(std::string newPassword);

    // Method to get the current membership status (active or inactive)
    bool getMembershipStatus();

    // Method to view the member's membership details
    void viewMembershipDetails();

    // Method to get the applicable discount rate for the member
    double getDiscountRate();
};

#endif // End of include guard