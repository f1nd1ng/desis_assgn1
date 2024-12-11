#include "Books.h" // Include the header file for the Books class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash

// Initialize the static counter for generating unique IDs
int Books::count = 0;

// Default constructor for the Books class
Books::Books() : id(++count), stock(0), sell_price(0.0), store_price(0.0) {}

// Parameterized constructor for the Books class
Books::Books(int stockCount, string titleName, string genreType, string authorName, double sellingPrice, double storePrice)
    : id(++count), stock(stockCount), title(titleName), genre(genreType), author(authorName), sell_price(sellingPrice), store_price(storePrice) {}

// Getter method to retrieve the title of the book
string Books::getTitle() { return title; }

// Getter method to retrieve the unique ID of the book
int Books::getID() { return id; }

// Getter method to retrieve the author of the book
string Books::getAuthor() { return author; }

// Getter method to retrieve the selling price of the book
double Books::getPrice() { return sell_price; }

// Getter method to retrieve the current stock of the book
int Books::getStock() { return stock; }

// Getter method to retrieve the genre of the book
string Books::getGenre() { return genre; }

// Getter method to retrieve the store price of the book
double Books::getStorePrice() { return store_price; }

// Method to check if the requested quantity of the book is available in stock
bool Books::checkavailability(int quantity) {
    return stock >= quantity; // Return true if stock is sufficient, otherwise false
}

// Method to sell a specified quantity of the book
void Books::sellbook(int quantity) {
    if (checkavailability(quantity)) { // Check if the requested quantity is available
        stock -= quantity; // Deduct the sold quantity from stock
        cout << quantity << " copies of " << title << " sold." << endl; // Inform the user of the sale
        cout << "Remaining no. of copies: " << stock << endl; // Show remaining stock
    } else {
        cout << "Not enough stock for " << title << "." << endl; // Inform the user of insufficient stock
    }
}

// Method to add stock of the book
void Books::addStock(int quantity) {
    stock += quantity; // Increase the stock by the specified quantity
    cout << "No of copies left: " << stock << endl; // Show the updated stock
}