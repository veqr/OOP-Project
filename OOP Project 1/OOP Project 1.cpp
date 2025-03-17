#include <iostream>
#include <string>
#include "User.h"
#include "Member.h"
#include "Book.h"
#include "Librarian.h"
#include "bookManagement.h"
#include <Vector>
#include <functional>
using namespace std;

string name;
string author;
bool taken;
int borrowSize = 6;

bookManagement* currentBooksList = new bookManagement();
Member* memberBooks = new Member(name, author, taken);

vector<string> userEmailVector = {"M","L","A","M M"};
vector<string> userPasswordVector = {"M","L","A","M M"};
vector<int> userTypeVector = {1,2,3,1};

Member* member1 = new Member(name, author, taken);
Librarian* librarian1 = new Librarian();






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

void createAdminAccount() {

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

                    return 1;
                }
                else if (userTypeVector[i] == 2) {
                    return 2;
                }
                else if (userTypeVector[i] == 3) {
                    return 3;
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

void borrowScreen() {
    int bookchoice;
    cout << "Enter a number from the book list below to borrow a book.\n";
    bookList();
    cin >> bookchoice;
    Book bookstest = currentBooksList->books[bookchoice];
    if (bookstest.taken == false) {
        cout << "You have chosen: " << bookstest.name << "\n";
        if (memberBooks->borrowedBooks.size() < borrowSize + 1) {
            bookstest.taken = true;
            currentBooksList->books[bookchoice].taken = true;
            memberBooks->borrowedBooks.emplace_back(bookstest.name, bookstest.author, bookstest.taken);
        }
        else {
            cout << "You are already borrowing 5 books. Please return a book to be able to borrow another.";
        }
        cout << "You are currently borrowing:\n";
        for (int i = 1; i < memberBooks->borrowedBooks.size(); i++) {
            string bookname = memberBooks->borrowedBooks[i].name;
            string bookauthor = memberBooks->borrowedBooks[i].author;
            cout << "Name: " << bookname << ", Author: " << bookauthor << ", Borrowed\n";
        }
    }
}

void reservedScreen() {
    int bookchoice;
    cout << "Enter a number from the book list below to reserve a book.\n";
    bookList();
    cin >> bookchoice;
    Book bookstest = currentBooksList->books[bookchoice];
    if (bookstest.taken == true) {
        cout << "You have chosen: " << bookstest.name << "\n";
        currentBooksList->books[bookchoice].taken = true;
        memberBooks->reservedBooks.emplace_back(bookstest.name, bookstest.author, bookstest.taken);
        
        cout << "You are currently borrowing:\n";
        for (int i = 1; i < memberBooks->reservedBooks.size(); i++) {
            string bookname = memberBooks->reservedBooks[i].name;
            string bookauthor = memberBooks->reservedBooks[i].author;
            cout << "Name: " << bookname << ", Author: " << bookauthor << ", Borrowed\n";
        }
    }
    else {
        cout << "The book is available so it cannot be reserved.\n";
    }
}

void adminScreen() {

}

void librarianScreen() {

}

void memberScreen() {

    int choice;
    cout << "This is the Member Screen.\n\n";
    cout << "Please enter the number to select a choice\n\n1 to show the current list of available books.\n2 to borrow a book.\n3 to reserve a book.\n4 to return a book.\n5 to search for a book.\n6 to exit.\n";
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
    case 5:
    case 6:
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
        if (login() == 1) {
            memberScreen();
        }
        else if (login() == 2) {
            librarianScreen();
        }
        else if (login() == 3) {
            adminScreen();
        }
    case 3:
        if (createLibrarianAccount() == 2) {
            startScreen();
        }
    case 4:
        createAdminAccount();
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