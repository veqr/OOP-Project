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

bookManagement* currentBooksList = new bookManagement();
Member* memberBooks = new Member(name, author, taken);

vector<string> userEmailVector = {"M","L","A"};
vector<string> userPasswordVector = {"M","L","A"};
vector<int> userTypeVector = {1,2,3};

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


    cout << "Please create a password:\n";
    cin >> newpassword;


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

    cout << "Please create a password:\n";
    cin >> newpassword;

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
        cout << "Please enter password\n";
        cin >> password;

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
            }
        }

        attempts++;
        strattempts = to_string(attempts) + " attempts made.\n";

        if (attempts < 3) {
            cout << "Incorrect Login Attempt. Please try again\n";
            cout << strattempts;
        }


        if (attempts == 3) {
            cout << "Too many attempts, please try again later.\n";

        }
    }
        

}

void borrowScreen() {
    int bookchoice;
    cout << "Enter a number from the book list below to select a book.\n";
    //cout << bookstest.name << " " << bookstest.author << " " << bookstest.taken;
    bookList();
    cin >> bookchoice;
    Book bookstest = currentBooksList->books[bookchoice];
    cout << "You have chosen: " << bookstest.name << "\n";
    //cout << books.name;
    memberBooks->borrowedBooks.emplace_back(bookstest.name, bookstest.author, bookstest.taken);
    //cout << memberBooks->borrowedBooks[1].name << "\n";

}

void adminScreen() {

}

void librarianScreen() {

}

void memberScreen() {

    int choice;
    int bookchoice;
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

    case 3:
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