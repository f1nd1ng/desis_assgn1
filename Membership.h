#ifndef MEMBERSHIP_H // Include guard to prevent multiple inclusions of this header file
#define MEMBERSHIP_H

#include "Member.h" // Include the header file for the Member class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash collected by the cashier

// Membership class to manage a collection of Member objects
class Membership {
private:
    unordered_map<int, Member*> members; // Map to store members with their ID as the key and a pointer to the Member object as the value

public:
    // Method to add a new member to the membership system
    void addMember(Member* member);

    // Method to retrieve a member by their ID
    Member* getMember(int id);

    // Method to display all members in the membership system
    void displayMembers();
};

#endif // End of include guard