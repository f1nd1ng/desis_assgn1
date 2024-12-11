#ifndef BOOKS_H // Include guard to prevent multiple inclusions of this header file
#define BOOKS_H

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

extern double cash; // Declaration of the global variable cash, defined elsewhere

class Books {
protected:
    static int count; // Static counter for generating unique IDs for each book
    int id; // Unique ID for the book
    int stock; // Number of available books in stock
    string title; // Title of the book
    string genre; // Genre of the book
    string author; // Author of the book
    double sell_price; // Selling price for the customer
    double store_price; // Store price of the book

public:
    // Default constructor
    Books();

    // Parameterized constructor to initialize a book with specific attributes
    Books(int stockCount, string titleName, string genreType, string authorName, double sellingPrice, double storePrice);

    // Getter method to retrieve the title of the book
    string getTitle();

    // Getter method to retrieve the unique ID of the book
    int getID();

    // Getter method to retrieve the author of the book
    string getAuthor();

    // Getter method to retrieve the selling price of the book
    double getPrice();

    // Getter method to retrieve the current stock of the book
    int getStock();

    // Getter method to retrieve the genre of the book
    string getGenre();

    // Getter method to retrieve the store price of the book
    double getStorePrice();

    // Method to check if the requested quantity of the book is available in stock
    bool checkavailability(int quantity);

    // Method to sell a specified quantity of the book
    void sellbook(int quantity);

    // Method to add stock of the book
    void addStock(int quantity);
};

#endif // End of include guard