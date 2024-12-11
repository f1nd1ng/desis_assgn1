#include "Inventory.h" // Include the header file for the Inventory class
#include "Member.h"    // Include the header file for the Member class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash collected by the cashier

// Method to add a book item to the inventory
void Inventory::addItem_book(Books* item) {
    cout << "Adding book: '" << item->getTitle() << "'" << endl;
    // Check if the book already exists in the inventory
    if (items.find(item->getTitle()) == items.end()) {
        items[item->getTitle()] = item; // Add the new book to the inventory
        cout << "'" << item->getTitle() << "' added to the inventory." << endl;
    } else {
        cout << "'" << item->getTitle() << "' already exists. Updating stock." << endl;
        items[item->getTitle()]->addStock(item->getStock()); // Update the stock of the existing book
    }
}

// Method to add a magazine item to the inventory
void Inventory::addItem_mag(Magazine* magazine) {
    // Check if the magazine already exists in the inventory
    if (magazines.find(magazine->getTitle()) == magazines.end()) {
        magazines[magazine->getTitle()] = magazine; // Add the new magazine to the inventory
        cout << "'" << magazine->getTitle() << "' added to the inventory." << endl;
    } else {
        cout << "'" << magazine->getTitle() << "' already exists. Updating stock." << endl;
        magazines[magazine->getTitle()]->addStock(magazine->getStock()); // Update the stock of the existing magazine
    }
}

// Method to display details of a specific book
void Inventory::displayDetailsbook(string& title) {
    cout << "Searching for book: '" << title << "'" << endl;
    // Check if the book exists in the inventory
    if (items.find(title) == items.end()) {
        cout << "Sorry!! No such book available in store." << endl;
    } else {
        Books* item = items[title]; // Retrieve the book from the inventory
        cout << "Details: \n";
        cout << "Title: " << item->getTitle() << endl;
        cout << "Author: " << item->getAuthor() << endl;
        cout << "Genre: " << item->getGenre() << endl;
        cout << "Number of copies present: " << item->getStock() << endl;
        cout << "Price: " << item->getPrice() << endl;
    }
}

// Method to display details of a specific magazine
void Inventory::displayDetailsmag(string& title) {
    // Check if the magazine exists in the inventory
    if (magazines.find(title) == magazines.end()) {
        cout << "Sorry!! No such magazine available in store." << endl;
    } else {
        Magazine* magazine = magazines[title]; // Retrieve the magazine from the inventory
        cout << "Details: \n";
        cout << "Title: " << title << endl;
        cout << "Number of copies present: " << magazine->getStock() << endl;
        cout << "Price: " << magazine->getPrice() << endl;
    }
}

// Method to display all books in the inventory
void Inventory::displayallbooks() {
    cout << "Inventory of books:" << endl;
    for (const auto& pair : items) {
        Books* book = pair.second; // Retrieve each book from the inventory
        cout << "ID: " << book->getID() << ", ";
        cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor() << ", ";
        cout << "Genre: " << book->getGenre() << ", ";
        cout << "Stock: " << book->getStock() << ", ";
        cout << "Price: " << book->getPrice() << endl;
    }
}

// Method to display all magazines in the inventory
void Inventory::displayallmag() {
    cout << "Inventory of magazines:" << endl;
    for (const auto& pair : magazines) {
        Magazine* magazine = pair.second; // Retrieve each magazine from the inventory
        cout << "Company: " << magazine->getTitle() << ", ";
        cout << "Stock: " << magazine->getStock() << ", ";
        cout << "Price: " << magazine->getPrice() << endl;
    }
}

// Method to sell a book to a member
void Inventory::sellBook(int memberID, int quantity, string title, Member* member) {
    // Check if the book exists in the inventory
    if (items.find(title) == items.end()) {
        cout << "Book not found in inventory!" << endl;
        return; // Exit if the book is not found
    }

    Books* book = items[title]; // Retrieve the book from the inventory
    // Check if the requested quantity is available
    if (!book->checkavailability(quantity)) {
        cout << "Not enough stock available for " << book->getTitle() << endl;
        return; // Exit if there is insufficient stock
    }

    double price = book->getPrice() * quantity; // Calculate total price for the requested quantity

    // Check for membership discounts
    if (member != nullptr && member->getMembershipStatus()) {
        double discount = price * member->getDiscountRate(); // Calculate discount based on member's rate
        price -= discount; // Apply discount to the total price
        cout << "Discount applied: Rs" << discount << endl;
    } else if (member != nullptr && member->membershipExpired()) {
        cout << "Not a member: " << member->getName() << ". No discounts applied." << endl;
    }
    cout << "Sold " << quantity << " copies of '" << book->getTitle() << "' for Rs" << price << endl;
    cash += price; // Update total cash collected
    book->sellbook(quantity); // Update the stock of the book after sale
}

// Method to sell a magazine
void Inventory::sellMagazine(int quantity, string title) {
    // Check if the magazine exists in the inventory
    if (magazines.find(title) == magazines.end()) {
        cout << "Magazine not found in inventory!" << endl;
        return; // Exit if the magazine is not found
    }
    Magazine* magazine = magazines[title]; // Retrieve the magazine from the inventory
    // Check if the requested quantity is available
    if (!magazine->checkavailability(quantity)) {
        cout << "Not enough stock available for " << magazine->getTitle() << endl;
        return; // Exit if there is insufficient stock
    }
    double p = magazine->getPrice() * quantity; // Calculate total price for the requested quantity
    cout << "Total amount to be paid: " << p << endl;
    cash += p; // Update total cash collected
}

// Method to push a book item to a member's purchase history
void Inventory::pushBook(string title, int quantity, Member* member) {
    Books* item = items[title]; // Retrieve the book from the inventory
    // Create a new book object with the specified quantity and details
    Books book1(quantity, title, item->getGenre(), item->getAuthor(), item->getPrice(), item->getStorePrice());
    member->pushItembook(book1, quantity); // Add the book to the member's purchase history
}

// Method to push a magazine item to a member's purchase history
void Inventory::pushMag(string title, int quantity, Member* member) {
    Magazine* item = magazines[title]; // Retrieve the magazine from the inventory
    // Create a new magazine object with the specified quantity and details
    Magazine mag1(title, quantity, item->getTitle(), item->getGenre(), item->getAuthor(), item->getPrice(), item->getStorePrice());
    member->pushItemmag(mag1, quantity); // Add the magazine to the member's purchase history
}

// Method to search for books by a specific author
void Inventory::searchBooksByAuthor(const string& author) {
    cout << "Searching for books by author: '" << author << "'" << endl;

    bool found = false; // Flag to check if any books are found
    for (const auto& pair : items) {
        Books* book = pair.second; // Retrieve each book from the inventory
        // Check if the book's author matches the search criteria
        if (book->getAuthor() == author) {
            found = true; // Set flag to true if a match is found
            cout << "Title: " << book->getTitle() << ", Genre: " << book->getGenre()
                      << ", Stock: " << book->getStock() << ", Price: Rs" << book->getPrice() << endl;
        }
    }

    if (!found) {
        cout << "No books found by author: '" << author << "'" << endl; // Message if no books are found
    }
}

// Method to search for books by specific genre
void Inventory::searchBooksByGenre(const string& genre) {
    cout << "Searching for books by genre: '" << genre << "'" <<endl;

    bool found = false; // Flag to check if any books are found
    for (const auto& pair : items) {
        Books* book = pair.second; // Retrieve each book from the inventory
        // Check if the book's genre matches the search criteria
        if (book->getGenre() == genre) {
            found = true; // Set flag to true if a match is found
            cout << "Title: " << book->getTitle() << ", Author: " << book->getAuthor()
                      << ", Stock: " << book->getStock() << ", Price: Rs" << book->getPrice() << endl;
        }
    }

    if (!found) {
        cout << "No books found of genre : '" << genre << "'" << endl; // Message if no books are found
    }
}

// Destructor to clean up dynamically allocated memory
Inventory::~Inventory() {
    for (auto& pair : items) {
        delete pair.second; // Delete each book object in the inventory
    }
    for (auto& pair : magazines) {
        delete pair.second; // Delete each magazine object in the inventory
    }
}