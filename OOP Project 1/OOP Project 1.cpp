#include <iostream>
#include <string>
#include "User.h"
#include "Member.h"
#include "Book.h"
#include "Librarian.h"
#include "bookManagement.h"
#include "Admin.h"
#include <Vector>
#include <functional>
using namespace std;

string name;
string author;
bool taken;

int accountType;

int borrowLimit = 6;
int day = 0;
float latePenalty = 2;

bookManagement* currentBooksList = new bookManagement();
Member* memberBooks = new Member(name, author, taken);

vector<string> userEmailVector = {"M","L","A","M M"};
vector<string> userPasswordVector = {"M","L","A","M M"};
vector<int> userTypeVector = {1,2,3,1};

Member* member1 = new Member(name, author, taken);
Librarian* librarian1 = new Librarian();
Admin* admin1 = new Admin();






void bookList() {
    currentBooksList->show();
}

int createMemberAccount() {

    string newemail;
    string newpassword;


    cout << "Please enter an email:\n";
    cin >> newemail;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    cout << "Please create a password:\n";
    cin >> newpassword;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');


    userEmailVector.push_back(newemail);
    userPasswordVector.push_back(newpassword);
    userTypeVector.push_back(1);

    cout << "You have entered the email: " << newemail << ", and the password you entered: " << newpassword << "\n";
    cout << "You are being redirected to the start screen to log in to your new account.\n\n";
    return 1;

}

int createLibrarianAccount() {

    string librarianpassword;
    string newemail;
    string newpassword;

    cout << "Please enter the Librarian password.\n";
    cin >> librarianpassword;
    if (librarianpassword == "Library123") {
        cout << "Librarian password recognised. Please proceed.\n";
    }
    else {
        cout << "Librarian password not recognised, the program will now terminate.\n";
        return 5;
    }

    cout << "Please enter an email:\n";
    cin >> newemail;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Please create a password:\n";
    cin >> newpassword;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    userEmailVector.push_back(newemail);
    userPasswordVector.push_back(newpassword);
    userTypeVector.push_back(2);

    cout << "You have entered the email: " << newemail << ", and the password you entered: " << newpassword << "\n";
    cout << "You are being redirected to the start screen to log in to your new account.\n\n";
    return 2;

}

int createAdminAccount() {
    string adminpassword;
    string newemail;
    string newpassword;

    cout << "Please enter the Admin password.\n";
    cin >> adminpassword;
    if (adminpassword == "Admin123") {
        cout << "Admin password recognised. Please proceed.\n";
    }
    else {
        cout << "Admin password not recognised, the program will now terminate.\n";
        return 5;
    }

    cout << "Please enter an email:\n";
    cin >> newemail;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Please create a password:\n";
    cin >> newpassword;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    userEmailVector.push_back(newemail);
    userPasswordVector.push_back(newpassword);
    userTypeVector.push_back(3);

    cout << "You have entered the email: " << newemail << ", and the password you entered: " << newpassword << "\n";
    cout << "You are being redirected to the start screen to log in to your new account.\n\n";
    return 3;
}

int login() {

    string email;
    string password;

    int tempattempts = 0;
    int attempts = 0;
    string strattempts;

    while (attempts < 3) {

        cout << "Please enter email\n";
        cin >> email;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Please enter password\n";
        cin >> password;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < userEmailVector.size(); i++) {
            if (email == userEmailVector[i] && password == userPasswordVector[i]) {
                cout << "Access Granted!\n";
                if (userTypeVector[i] == 1) {

                    member1->setEmail(email);

                    member1->setPassword(password);

                    member1->setAccountType(1);

                    accountType = 1;

                    return 0;
                }
                else if (userTypeVector[i] == 2) {

                    librarian1->setEmail(email);

                    librarian1->setPassword(password);

                    librarian1->setAccountType(2);

                    accountType = 2;

                    return 0;

                }
                else if (userTypeVector[i] == 3) {

                    admin1->setEmail(email);

                    admin1->setPassword(password);

                    admin1->setAccountType(3);

                    accountType = 3;

                    return 0;
                }
                else {
                    cout << "Invalid";
                }
            }
        }

        attempts++;
        strattempts = to_string(attempts) + " attempts made.\n";

        if (attempts < 3) {
            cout << "Incorrect Login Attempt. Please try again\n";
            cout << strattempts;
        }


        if (attempts > 3) {
            cout << "Too many attempts, please try again later.\n";

        }
    }
        

}

void showBorrowedBooks() {

    cout << "You are currently borrowing:\n";
    for (int i = 1; i < memberBooks->borrowedBooks.size(); i++) {
        string bookname = memberBooks->borrowedBooks[i].name;
        string bookauthor = memberBooks->borrowedBooks[i].author;
        cout << "Name: " << bookname << ", Author: " << bookauthor << ", Borrowed\n";
    }
}

void showReservedBooks() {

    cout << "You are currently reserving:\n";
    for (int i = 1; i < memberBooks->reservedBooks.size(); i++) {
        string bookname = memberBooks->reservedBooks[i].name;
        string bookauthor = memberBooks->reservedBooks[i].author;
        cout << "Name: " << bookname << ", Author: " << bookauthor << ", Borrowed\n";
    }
}

void returnScreen() {

    int bookchoice;
    bool found = false;
    for (int i = 1; i < memberBooks->borrowedBooks.size(); i++) {
        string bookname = memberBooks->borrowedBooks[i].name;
        string bookauthor = memberBooks->borrowedBooks[i].author;
        cout << i << ", Name: " << bookname << ", Author: " << bookauthor << ", Borrowed\n";
    }
    cout << "Enter a number from the book list above to return a book.\n";
    cin >> bookchoice;
    cout << "You are returning: " << memberBooks->borrowedBooks[bookchoice].name << "\n";
    for (int v = 1; v < currentBooksList->books.size(); v++) {
        if (memberBooks->borrowedBooks[bookchoice].name == currentBooksList->books[v].name) {
            currentBooksList->books[v].taken = false;
            found = true;
        }
    }
    if (found == true) {
        cout << memberBooks->borrowedBooks[bookchoice].name << " has been returned.\n";
        memberBooks->borrowedBooks.erase(memberBooks->borrowedBooks.begin() + bookchoice);
    }
    else {
        cout << "This book has not been found.\n";
    }
}

void searchBooks() {
    
    string booksearch;
    cout << "Please enter the name of a book you wish to search by name or the author you wish to search for, replace any spaces with an underscore.\n";
    cin >> booksearch;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int booknum = 0; booknum < currentBooksList->books.size(); booknum++) {
        if (booksearch == currentBooksList->books[booknum].name) {
            string takentxt;
            if (currentBooksList->books[booknum].taken == 1) {
                takentxt = "Borrowed";
            }
            else {
                takentxt = "Available";
            }


            cout << "Name: " << currentBooksList->books[booknum].name << ", Author: " << currentBooksList->books[booknum].author << ", Availability: " << takentxt << "\n";
        }
        if (booksearch == currentBooksList->books[booknum].author) {
            string takentxt;
            if (currentBooksList->books[booknum].taken == 1) {
                takentxt = "Borrowed";
            }
            else {
                takentxt = "Available";
            }


            cout << "Name: " << currentBooksList->books[booknum].name << ", Author: " << currentBooksList->books[booknum].author << ", Availability: " << takentxt << "\n";
        }
    }
}

void borrowScreen() {

    int bookchoice;
    cout << "Enter a number from the book list below to borrow a book.\n";
    bookList();
    cin >> bookchoice;
    Book bookstemp = currentBooksList->books[bookchoice];
    if (bookstemp.taken == false) {
        cout << "You have chosen: " << bookstemp.name << "\n";
        if (memberBooks->borrowedBooks.size() < borrowLimit + 1) {
            bookstemp.taken = true;
            currentBooksList->books[bookchoice].taken = true;
            memberBooks->borrowedBooks.emplace_back(bookstemp.name, bookstemp.author, bookstemp.taken);
        }
        else {
            cout << "You are already borrowing 5 books. Please return a book to be able to borrow another.";
        }
        showBorrowedBooks();
    }
}

void reservedScreen() {

    int bookchoice;
    cout << "Enter a number from the book list below to reserve a book.\n";
    bookList();
    cin >> bookchoice;
    Book bookstemp = currentBooksList->books[bookchoice];
    if (bookstemp.taken == true) {
        cout << "You have chosen: " << bookstemp.name << "\n";
        currentBooksList->books[bookchoice].taken = true;
        memberBooks->reservedBooks.emplace_back(bookstemp.name, bookstemp.author, bookstemp.taken);
        showReservedBooks();
    }
    else {
        cout << "The book is available so it cannot be reserved.\n";
    }
}

void addBook() {

    string newname;
    string newauthor;
    cout << "Please enter a new book name\n";
    cin >> newname;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Please enter a new book author\n";
    cin >> newauthor;
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    currentBooksList->books.emplace_back(newname, newauthor, false);

    bookList();
}

void removeBook() {
    int delbook;
    cout << "Enter the number to delete a book.\n";
    for (int i = 0; i < currentBooksList->books.size(); i++) {
        cout << i << ", Name: " << currentBooksList->books[i].name << ", Author: " << currentBooksList->books[i].author << "\n";
    }
    cin >> delbook;
    currentBooksList->books.erase(currentBooksList->books.begin() + delbook);
    cout << "This is the new list of books:\n\n";
    bookList();
}

void updateBook() {
    int updatebook;
    cout << "Enter the number to update a book's status.\n";
    for (int i = 0; i < currentBooksList->books.size(); i++) {
        cout << i << ", Name: " << currentBooksList->books[i].name << ", Author: " << currentBooksList->books[i].author;
    }
    cin >> updatebook;
    currentBooksList->books[updatebook].taken != currentBooksList->books[updatebook].taken;
    cout << "Status ahs been updated.\n\n";
    bookList();
    
}

void borrowedList() {
    for (int i = 0; i < currentBooksList->books.size(); i++) {
        if (currentBooksList->books[i].taken == true) {
            cout << i << ", Name: " << currentBooksList->books[i].name << ", Author: " << currentBooksList->books[i].author << ", Currently being borrowed.\n";
        }
        
    }
}

void setBorrowLimit() {
    int templim;
    cout << "Please enter the borrowing limit\n";
    cin >> templim;
    cout << "The limit has now been set to " << templim;
    borrowLimit = templim + 1;
}

void setLatePenalty() {
    float temppen;
    cout << "Please enter the late penalty.\n";
    cin >> temppen;
    cout << "The late penalty has been set to " << temppen;
    latePenalty = temppen + 1;
}

void manageAccounts() {
    int accountDel;
    cout << "Listed below are all the users in a numerical order.\n";
    for (int i = 0; i < userPasswordVector.size(); i++) {
        cout << i << ", " << userPasswordVector[i] << "\n";
    }
    cout << "\nPlease enter the number of the user you would like to delete, enter -1 to return to the Admin Screen.\n";
    cin >> accountDel;
    switch (accountDel) {
    case -1:
        cout << "Cancelled\n";
    default:
        userEmailVector.erase(userEmailVector.begin() + accountDel);
        userPasswordVector.erase(userPasswordVector.begin() + accountDel);
        userTypeVector.erase(userTypeVector.begin() + accountDel);
        cout << "Account Deleted\n";
    }
}

void adminScreen() {
    int choice;
    cout << "This is the Admin Screen.\n\n";
    cout << "Please enter the number the select a choice.\n\n1 to change the borrowing limit.\n2 to change the late penalty.\n3 to manage another account.\n";
    cin >> choice;
    switch (choice) {
    case 1:
        setBorrowLimit();
        adminScreen();
    case 2:
        setLatePenalty();
        adminScreen();
    case 3:
        manageAccounts();
        adminScreen();
    default:
        cout << "Invalid input.\n";
    }
}

void librarianScreen() {
    int choice;
    cout << "This is the Librarian Screen.\n\n";
    cout << "Please enter the number to select a choice.\n\n1 to add a book.\n2 to remove a book.\n3 to update a book.\n4 to get a list of all borrowed books\n";
    cin >> choice;
    switch (choice) {
    case 1:
        addBook();
        librarianScreen();
    case 2:
        removeBook();
        librarianScreen();
    case 3:
        updateBook();
        librarianScreen();
    case 4:
        borrowedList();
        librarianScreen();
    default:
        cout << "Invalid choice";
    }
}

void memberScreen() {

    int choice;
    cout << "This is the Member Screen.\n\n";
    cout << "Please enter the number to select a choice\n\n1 to show the current list of available books.\n2 to borrow a book.\n3 to reserve a book.\n4 to return a book.\n5 to search for a book.\n6 to show what books you are currently borrowing.\n7 to show what books you are currently reserving.\n8 to exit.\n";
    cin >> choice;
    switch (choice) {
    case 1:
        bookList();
        cout << "\n";
        memberScreen();
    case 2:
        borrowScreen();
        memberScreen();

    case 3:
        reservedScreen();
        memberScreen();

    case 4:
        returnScreen();
        memberScreen();
    case 5:
        searchBooks();
        memberScreen();
    case 6:
        showBorrowedBooks();
        memberScreen();
    case 7:
        showReservedBooks();
        memberScreen();
    case 8:
        exit(0);
    default:
        cout << "Invalid input, please try again.\n";
        memberScreen();
    }
}

void startScreen() {
    int choice;
    cout << "Welcome to the Smart Library Management System\n\n";
    cout << "Please enter the number to select a choice\n\n1 to create a member account.\n2 to login.\n3 to create a librarian account(librarian password needed).\n4 to create an admin account(admin password needed).\n";
    cin >> choice;
    switch (choice) {
    case 1:
        if (createMemberAccount() == 1);
        startScreen();
    case 2:
        login();
        if (accountType == 1) {
            memberScreen();
        }
        else if(accountType == 2) {
            librarianScreen();
        }
        else if (accountType == 3) {
            adminScreen();
        }
        else {
            cout << "Invalid account type";
        }
    case 3:
        createLibrarianAccount();
        startScreen();
        
    case 4:
        createAdminAccount();
        startScreen();
    case 5:
        exit(0);
    default:
        cout << "Invalid input, please try again.\n";
        startScreen();
    }
}

int main()
{

    startScreen();

    return 0;

}