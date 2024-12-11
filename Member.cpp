#include "Member.h" // Include the header file for the Member class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash collected by the cashier

// Static member variable to keep track of the number of Member instances
int Member::count = 0;

// Function to get the current year
int getCurrentYear() {
    time_t now = time(0); // Get the current time
    tm *ltm = localtime(&now); // Convert to local time structure
    return 1900 + ltm->tm_year; // Return the current year
}

// Constructor for the Member class
Member::Member(string n, string p, string db) 
    : Customer(n), // Initialize the base class Customer with the name
      password(p), // Initialize the password
      dob(db), // Initialize the date of birth
      member(false), // Initialize membership status to false
      discountRate(0.05), // Set the regular discount rate to 5%
      birthdayDiscountRate(0.15), // Set the birthday discount rate to 15%
      membershipExpiryYear(0) { // Initialize membership expiry year to 0
    id = ++count; // Increment the count and assign it to the member ID
}

// Method to get the member ID
int Member::getID() { 
    return id; 
}

// Method to get the member's name
string Member::getName() { 
    return name; 
}

// Method to check if the membership has expired
bool Member::membershipExpired() {
    return getCurrentYear() > membershipExpiryYear; // Return true if the current year is greater than the expiry year
}

// Method to activate the membership
void Member::activateMembership(double membershipFee) {
    // Check if the membership is expired or not already a member
    if (membershipExpired() || !member) {
        member = true; // Set membership status to true
        membershipExpiryYear = getCurrentYear() + 2; // Set membership valid for 2 years
        cout << name << " has activated membership! Paid fee: Rs" << membershipFee 
             << ". Membership expires in " << membershipExpiryYear << "." << endl;
        cash += membershipFee; // Add the membership fee to the total cash
    } else {
        cout << name << " already has an active membership until " << membershipExpiryYear << "." << endl;
    }
}

// Method to update the member's password
void Member::updatePassword(string newPassword) {
    password = newPassword; // Update the password
    cout << "Password updated successfully for " << name << ".\n"; // Confirmation message
}

// Method to get the membership status
bool Member::getMembershipStatus() {
    return member && !membershipExpired(); // Return true if the member is active and not expired
}

// Method to view membership details
void Member::viewMembershipDetails() {
    cout << "Membership Details for " << name << ":\n";
    cout << "ID: " << id << ", Active: " << (getMembershipStatus() ? "Yes" : "No") 
         << ", Expiry Year: " << membershipExpiryYear << ".\n"; // Display membership details
}

// Method to get the discount rate for the member
double Member::getDiscountRate() {
    // Check if the membership is valid
    if (!getMembershipStatus()) {
        cout << name << "'s membership has expired or is not a member. Become a member to access discounts." << endl;
        return 0.0; // No discount if membership is not valid
    }

    // Check if it's the member's birthday month
    time_t now = time(0);
    tm *ltm = localtime(&now);
    string currentMonth = to_string(1 + ltm->tm_mon); // Get current month (1-12)

    // Check if the current month matches the member's birthday month
    if (dob.substr(0, 2) == (currentMonth.length() == 1 ? "0" + currentMonth : currentMonth)) {
        return birthdayDiscountRate; // Return birthday discount rate
    }
    return discountRate; // Return regular discount rate
}