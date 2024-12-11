#ifndef INVENTORY_H // Include guard to prevent multiple inclusions of this header file
#define INVENTORY_H

#include "Member.h"   // Include the header file for the Member class
#include "Books.h"    // Include the header file for the Books class
#include "Magazine.h"  // Include the header file for the Magazine class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

extern double cash; // Declaration of the global variable cash, defined elsewhere

class Inventory {
private:
    // Maps to store books and magazines with their titles as keys
    unordered_map<string, Books*> items; // Maps book titles to Book pointers
    unordered_map<string, Magazine*> magazines; // Maps magazine titles to Magazine pointers

public:
    // Method to add a book item to the inventory
    void addItem_book(Books* item);

    // Method to add a magazine item to the inventory
    void addItem_mag(Magazine* magazine);

    // Method to display details of a specific book
    void displayDetailsbook(string& title);

    // Method to display details of a specific magazine
    void displayDetailsmag(string& title);

    // Method to display all books in the inventory
    void displayallbooks();

    // Method to display all magazines in the inventory
    void displayallmag();

    // Method to sell a book to a member
    void sellBook(int memberID, int quantity, string title, Member* member);

    // Method to sell a magazine
    void sellMagazine(int quantity, string title);

    // Method to push a book item to a member's purchase history
    void pushBook(string title, int quantity, Member* member);

    // Method to push a magazine item to a member's purchase history
    void pushMag(string title, int quantity, Member* member);

    // Method to search for books by a specific author
    void searchBooksByAuthor(const string& author);

    // Method to search for books by a specific genre
    void searchBooksByGenre(const string& genre);

    // Destructor to clean up dynamically allocated memory
    ~Inventory();
};

#endif // End of include guard