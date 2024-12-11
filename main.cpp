#include "Inventory.h" // Include the header file for the Inventory class
#include "Membership.h" // Include the header file for the Membership class
#include "Cashier.h" // Include the header file for the Cashier class
#include "Books.h" // Include the header file for the Books class
#include "Magazine.h" // Include the header file for the Magazine class
#include "Customer.h" // Include the header file for the Customer class
#include "Member.h" // Include the header file for the Member class

#include <bits/stdc++.h> // Include standard libraries
using namespace std;

double cash; // Global variable to hold the total cash collected by the cashier

// Function to get the current year
int getCurrentYear() {
    time_t now = time(0); // Get the current time
    tm *ltm = localtime(&now); // Convert to local time structure
    return 1900 + ltm->tm_year; // Return the current year
}

// Function to count the number of digits in an integer
int count_digit(int number) {
   int count = 0; // Initialize digit count
   while(number != 0) { // Loop until the number becomes 0
      number = number / 10; // Remove the last digit
      count++; // Increment the count
   }
   return count; // Return the total count of digits
}

// Function to display the member menu and handle member-related actions
void memberMenu(Inventory &inventory, Member* member) {
    Magazine mag; // Create a Magazine object
    int choice; // Variable to store user choice
    do {
        // Display member menu options
        cout << "\nMember Menu:\n";
        cout << "1. Membership Details\n"; // update password, view purchase history
        cout << "2. Books\n"; // display all books, buy a book, view a particular books details
        cout << "3. Magazines\n"; //display all magazines, buy a magazine, subscribe to a magazine, view a particular magazines details
        cout << "4. Search\n"; //search book by name, author or genre
        cout << "5. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get user choice

        switch (choice) {
        case 1: // Membership Details
            {
                member->viewMembershipDetails(); // Display membership details
                cout << "1. Update Password\n";
                cout << "2. View your purchase history\n";
                cout << "Enter your choice: \n";
                int subChoice; // Variable for sub-choice
                cin >> subChoice; // Get sub-choice
                if (subChoice == 1) {
                    string newPassword; // Variable for new password
                    cout << "Enter new password: ";
                    cin >> newPassword; // Get new password
                    member->updatePassword(newPassword); // Update password
                } else if (subChoice == 2) {
                    member->Customer::showPurchase_hist(); // Show purchase history
                } else {
                    cout << "Wrong choice"; // Invalid choice message
                }
                break;
            }

        case 2: // Books
            {
                inventory.displayallbooks(); // Display all books
                cout << "1. Buy a book\n";
                cout << "2. Display book details\n";
                cout << "Enter your choice: \n";
                int subChoice; cin >> subChoice; // Get sub-choice
                if (subChoice == 1) {
                    cout << "Please enter book name:\n";
                    string na; getline(cin >> ws, na); // Get book name
                    cout << "Please enter the number of copies of book needed:\n";
                    int copies; cin >> copies; // Get number of copies
                    cout << "Please enter member id again: \n";
                    int id; cin >> id; // Get member ID
                    inventory.pushBook(na, copies, member); // Push book to member's purchase history
                    inventory.sellBook(id, copies, na, member); // Sell the book
                } else if (subChoice == 2) {
                    cout << "Enter title of book: \n";
                    string title; getline(cin >> ws, title); // Get book title
                    inventory.displayDetailsbook(title); // Display book details
                } else {
                    cout << "Wrong choice"; // Invalid choice message
                }
                break;
            }

        case 3: // Magazines
            {
                inventory.displayallmag(); // Display all magazines
                cout << "1. Buy a magazine\n";
                cout << "2. Subscribe to a magazine\n";
                cout << "3. Display magazine details\n";
                cout << "Enter your choice: \n";
                int subChoice; cin >> subChoice; // Get sub-choice
                if (subChoice == 1) {
                    cout << "Please enter magazine name:\n";
                    string na; getline(cin >> ws, na); // Get magazine name
                    cout << "Please enter the number of copies of magazine needed:\n";
                    int copies; cin >> copies; // Get number of copies
                    inventory.displayDetailsmag(na); // Display magazine details
                    inventory.sellMagazine(copies, na); // Sell the magazine
                    inventory.pushMag(na, copies, member); // Push magazine to member's purchase history
                } else if (subChoice == 2) {
                    cout << "Enter your name:\n";
                    string na; cin >> na; // Get subscriber's name
                    cout << "Enter company of magazine to subscribe to\n";
                    string c; getline(cin >> ws, c); // Get magazine company name
                    cout << "Enter your contact number:\n";
                    long n; cin >> n; // Get contact number
                    if (count_digit(n) != 10) // Validate contact number
                        cout << "Invalid Number";
                    else
                        mag.addSubscriber(na, c, n); // Add subscriber
                } else if (subChoice == 3) {
                    cout << "Enter company of magazine whose details are to be displayed:\n";
                    string na; getline(cin >> ws, na); // Get magazine company name
                    inventory.displayDetailsmag(na); // Display magazine details
                } else {
                    cout << "Wrong choice"; // Invalid choice message
                }
                break;
            }
        case 4: // Search
            {
                cout << "1. Search by Book Name\n";
                cout << "2. Search by Author Name\n";
                cout << "3. Search by Genre\n";
                cout << "Enter your choice:\n";
                int subChoice; cin >> subChoice; // Get sub-choice
                if (subChoice == 1) {
                    cout << "Enter title of book: \n";
                    string title; getline(cin >> ws, title); // Get book title
                    inventory.displayDetailsbook(title); // Display book details
                } else if (subChoice == 2) {
                    cout << "Enter author name: \n";
                    string author; getline(cin >> ws, author); // Get author name
                    inventory.searchBooksByAuthor(author); // Search books by author
                } else if (subChoice == 3){
                    cout << "Enter genre: \n";
                    string genre; getline(cin >> ws, genre); // Get genre
                    inventory.searchBooksByGenre(genre); // Search books by genre
                } else {
                    cout << "Wrong choice"; // Invalid choice message
                }
                break;
            }
        case 5: // Logout
            {
                cout << "Logging out...\n"; // Logout message
                break;
            }
        default: // Invalid choice
            {
                cout << "Invalid choice. Try again.\n"; // Invalid choice message
            }
        }
    } while (choice != 5); // Repeat until user chooses to logout
}

// Function to display the admin menu and handle admin-related actions
void adminMenu(Inventory &inventory, Membership &membership) {
    Magazine mag; // Create a Magazine object
    int choice; // Variable to store user choice
    do {
        // Display admin menu options
        cout << "\nAdmin Menu:\n";
        cout << "1. View Member List\n"; 
        cout << "2. View magazine Subscribers List\n";
        cout << "3. Search\n"; //search book by name, author or genre
        cout << "4. Add Book\n";
        cout << "5. Add Magazine\n";
        cout << "6. View All Books\n";
        cout << "7. View All Magazines\n";
        cout << "8. Logout\n";
        cout << "Enter your choice: ";
        cin >> choice; // Get user choice

        switch (choice) {
        case 1: // View Member List
            {
                membership.displayMembers(); // Display all members
                break;
            }
        case 2: // View magazine Subscribers List
            {
                mag.displaySubscribers(); // Display all magazine subscribers
                break;
            }
        case 3: // Search
            {
                cout << "1. Search by Book Name\n";
                cout << "2. Search by Author Name\n";
                cout << "3. Search by Genre\n";
                cout << "Enter your choice:\n";
                int subChoice; cin >> subChoice; // Get sub-choice
                if (subChoice == 1) {
                    cout << "Enter title of book: \n";
                    string title; getline(cin >> ws, title); // Get book title
                    inventory.displayDetailsbook(title); // Display book details
                } else if (subChoice == 2) {
                    cout << "Enter author name: \n";
                    string author; getline(cin >> ws, author); // Get author name
                    inventory.searchBooksByAuthor(author); // Search books by author
                } else if (subChoice == 3){
                    cout << "Enter genre: \n";
                    string genre; getline(cin >> ws, genre); // Get genre
                    inventory.searchBooksByGenre(genre); // Search books by genre
                } else {
                    cout << "Wrong choice"; // Invalid choice message
                }
                break;
            }
        case 4: // Add Book
            {
                cout << "Name of book to be added:\n";
                string na; getline(cin >> ws, na); // Get book name
                cout << "Genre of book:\n";
                string genre; getline(cin >> ws, genre); // Get book genre
                cout << "Name of author of the book\n";
                string author; getline(cin >> ws, author); // Get author's name
                cout << "Copies of book:\n";
                int copies; cin >> copies; // Get number of copies
                cout << "Enter selling price and store price: ";
                double sell_p, store_p; cin >> sell_p >> store_p; // Get selling and store prices
                Books* book1 = new Books(copies, na, genre, author, sell_p, store_p); // Create a new book object
                inventory.addItem_book(book1); // Add the book to inventory
                break;
            }
        case 5: // Add Magazine
            {
                cout << "Name of company of magazine to be added:\n";
                string title; getline(cin >> ws, title); // Get magazine company name
                cout << "Name of magazine\n";
                string name; getline(cin >> ws, name); // Get magazine name
                cout << "Copies of magazine:\n";
                int copies; cin >> copies; // Get number of copies
                cout << "Genre of magazine\n";
                string genre; getline(cin >> ws, genre); // Get magazine genre
                cout << "Author of magazine\n";
                string author; getline(cin >> ws, author); // Get author's name
                cout << "Enter selling price and store price: ";
                double sell_p, store_p; cin >> sell_p >> store_p; // Get selling and store prices
                // Create a new magazine object
                Magazine* mag1 = new Magazine(title, copies, name, genre, author, sell_p, store_p);
                inventory.addItem_mag(mag1); // Add the magazine to inventory
                break;
            }
        case 6: // View All Books
            {
                inventory.displayallbooks(); // Display all books
                cout << "Do you want to see any book details: yes, no\n";
                string yn; cin >> yn; // Get user response
                if (yn == "yes") {
                    cout << "Enter title of book: ";
                    string title; getline(cin >> ws, title); // Get book title
                    inventory.displayDetailsbook(title); // Display book details
                }
                break;
            }
        case 7: // View All Magazines
            {
                inventory.displayallmag(); // Display all magazines
                cout << "Do you want to see any magazine details (yes, no):\n";
                string yn; cin >> yn; // Get user response
                if (yn == "yes") {
                    cout << "Enter company of magazine whose details are to be displayed:\n";
                    string na; getline(cin >> ws, na); // Get magazine company name
                    inventory.displayDetailsmag(na); // Display magazine details
                }
                break;
            }
        case 8: // Logout
            {
                cout << "Logging out...\n"; // Logout message
                break;
            }
        default: // Invalid choice
            {
                cout << "Invalid choice. Try again.\n"; // Invalid choice message
            }
        }
    } while (choice != 8); // Repeat until user chooses to logout
}

// Cashier class to handle cash-related operations
class Cashier {
public:
    Cashier() {} // Default constructor
    void displayTotalCash() {
        // Display total cash collected by the cashier
        cout << "Total cash in cashier: Rs" << cash << endl; // Show total cash
    }
};

// Main function to run the program
int main() {
    Inventory inventory; // Create an Inventory object
    Membership membership; // Create a Membership object

    // Pre-populate some data for testing
    // Adding books to inventory
    inventory.addItem_book(new Books(10, "The Alchemist", "Fiction", "Paulo Coelho", 300.0, 300.0));
    inventory.addItem_book(new Books(5, "1984", "Dystopian", "George Orwell", 250.0, 250.0));
    inventory.addItem_book(new Books(12, "To Kill a Mockingbird", "Classic", "Harper Lee", 350.0, 350.0));
    // ... (additional books added here)

    // Adding magazines to inventory
    inventory.addItem_mag(new Magazine("TechWorld Publishing", 20, "TechWorld", "Technology", "Editorial Team", 150.0, 150.0));
    inventory.addItem_mag(new Magazine("Fashion Inc.", 15, "Fashion Inc.", "Fashion", "Editorial Team", 120.0, 120.0));
    inventory.addItem_mag(new Magazine("Science Publications", 25, "Science Today", "Science", "Editorial Team", 200.0, 200.0));
    // ... (additional magazines added here)

    // Creating members and activating their memberships
    Member* member1 = new Member("Alice", "password123", "01-15"); 
    membership.addMember(member1);
    member1->activateMembership(500.0);
    Member* member2 = new Member("Bob", "securepass", "12-25"); 
    membership.addMember(member2);
    member2->activateMembership(500.0);
    // ... (additional members added here)

    string role; // Variable to store user role
    cout << "Enter role (member/admin/none-sign up to become a member)\n ";
    cin >> role; // Get user role
    
    if (role == "member") { // If user is a member
        string memberPassword; // Variable for member password
        cout << "Enter member password: ";
        cin >> memberPassword; // Get member password

        // Assume a static password "member123" for simplicity
        if (memberPassword == "member123") {
            int memberId; // Variable for member ID
            cout << "Enter your Member ID: ";
            cin >> memberId; // Get member ID

            auto member = membership.getMember(memberId); // Retrieve member by ID
            if (member) {
                memberMenu(inventory, member); // Show member menu
            } else {
                cout << "Invalid Member ID.\n"; // Invalid ID message
            }
        } else {
            cout << "Invalid password.\n"; // Invalid password message
        }
    } else if (role == "admin") { // If user is an admin
        string adminPassword; // Variable for admin password
        cout << "Enter admin password: ";
        cin >> adminPassword; // Get admin password

        // Assume a static password "admin123" for simplicity
        if (adminPassword == "admin123") {
            adminMenu(inventory, membership); // Show admin menu
        } else {
            cout << "Invalid password.\n"; // Invalid password message
        }
    } else if (role == "none") { // If user wants to sign up
        cout << "To become a member for 2 years you need to pay a fee of Rs 500." << endl 
             << "Benefits of becoming a member are:" << endl 
             << "Members get a regular discount of 5% on their purchase on books and 15% discount if they purchase on their birthday month.\n";
        cout << "Enter your name:\n";
        string na; cin >> na; // Get name for new member
        cout << "Enter your date of birth: (Format:MM-DD)\n";
        string c; cin >> c; // Get date of birth
        cout << "Enter password: ";
        string p; cin >> p; // Get password
        Member* member1 = new Member(na, p, c); // Create new member
        membership.addMember(member1); // Add member to membership
        member1->activateMembership(500.0); // Activate membership

        // Prompt for member login after sign-up
        string memberPassword; 
        cout << "Enter member password: ";
        cin >> memberPassword; // Get member password

        // Assume a static password "member123" for simplicity
        if (memberPassword == "member123") {
            int memberId; // Variable for member ID
            cout << "Enter your Member ID: ";
            cin >> memberId; // Get member ID

            auto member = membership.getMember(memberId); // Retrieve member by ID
            if (member) {
                memberMenu(inventory, member); // Show member menu
            } else {
                cout << "Invalid Member ID.\n"; // Invalid ID message
            }
        } else {
            cout << "Invalid password.\n"; // Invalid password message
        }
    }

    Cashier cashier; // Create Cashier object
    cashier.displayTotalCash(); // Display total cash collected
    return 0; // End of program
}