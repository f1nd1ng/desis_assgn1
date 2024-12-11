# desis_assgn1


###### Bookstore Inventory Management System

### Overview

The Bookstore Inventory Management System is a C++ application designed to manage the inventory of a bookstore while also providing features for managing members. This system allows bookstore owners to efficiently track books, manage member information, and handle sales transactions.

### Important information to run the program:

  -admin password:admin123
  
  -member password:member123
  
### Structure:
  BookstoreManagementSystem
  
    ├── main.cpp
    ├── Books.h
    ├── Books.cpp
    ├── Magazine.h
    ├── Magazine.cpp
    ├── Customer.h
    ├── Customer.cpp
    ├── Member.h
    ├── Member.cpp
    ├── Membership.h
    ├── Membership.cpp
    ├── Inventory.h
    ├── Inventory.cpp
    ├── Cashier.h
    ├── Cashier.cpp
    
### Features

  Different features are available for admin(store manager) and for a member(customer).
  
  -Admin:store manager incharge of adding books/magazines to the inventory.
  
    ##admin password: admin123
    -Can view the list of members.
    -Can view the list of subscribers of magazines.
    -Can search book by name, author or genre.
    -Can add a book/magazine to the inventory.
      -Can all specifically view for a given book/magazine via their title/company name.
    -Can view all books/magazines from the inventory. 

  -Member:A customer who pays Rs 500 to become a member. A member's benifits include getting flat 5% discount on their purchase and                15% discount in thier birthday month.
  
    ##member password: member123
    -Can view membership details and also view their purchase history.
    -View all books, buy a book, view a particular books details.
    -View all magazines, buy a magazine, subscribe to a magazine, view a particular magazines details.
    -Can search book by name, author or genre.

### Technologies Used

- **Programming Language:** C++
- **Data Structures:** Unordered maps, pairs and vectors for efficient member management.

### Getting Started

#### Prerequisites

- A C++ compiler (e.g., g++, clang++)
- C++11 or later

#### Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/bookstore-inventory-management-system.git
