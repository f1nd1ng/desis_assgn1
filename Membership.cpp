#include "Membership.h" // Include the header file for the Membership class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash collected by the cashier

// Method to add a new member to the membership system
void Membership::addMember(Member* member) {
    // Check if the member ID already exists in the members map
    if (members.find(member->getID()) == members.end()) {
        // If not, insert the new member into the map
        members.insert(make_pair(member->getID(), member));
        cout << "Member added: " << member->getName() << ", ID is: " << member->getID() << endl; // Confirmation message
    } else {
        // If the member ID already exists, print an error message
        cout << "Member with ID " << member->getID() << " already exists." << endl;
    }
}

// Method to retrieve a member by their ID
Member* Membership::getMember(int id) {
    // Check if the member ID exists in the members map
    if (members.find(id) != members.end()) {
        return members[id]; // Return the member pointer if found
    }
    return nullptr; // Return nullptr if the member ID does not exist
}

// Method to display all members in the membership system
void Membership::displayMembers() {
    // Check if there are no members in the system
    if (!members.size()) {
        cout << "No members in the system." << endl; // Message indicating no members
        return; // Exit the method
    }

    // Print the number of members
    cout << members.size() << " Members:" << endl;
    // Iterate through the members map and display each member's ID and name
    for (auto pair : members) {
        Member* member = pair.second; // Get the member pointer from the map
        cout << "ID: " << member->getID() << ", Name: " << member->getName() << endl; // Display member details
    }
}