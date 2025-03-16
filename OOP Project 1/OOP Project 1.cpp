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

bookManagement* currentBooksList = new bookManagement();

vector<string> userEmailVector = {"test"};
vector<string> userPasswordVector = {"test"};
vector<int> userTypeVector = {1};

void bookList() {
    currentBooksList->show();
}

int createMemberAccount() {

    string email;
    string password;
    string newemail;
    string newpassword;

    Member* member1 = new Member();

    cout << "Please enter an email:\n";
    cin >> newemail;

    member1->setEmail(newemail);

    cout << "Please create a password:\n";
    cin >> newpassword;

    member1->setPassword(newpassword);

    email = member1->getEmail();
    userEmailVector.push_back(email);
    password = member1->getPassword();
    userPasswordVector.push_back(password);
    member1->setAccountType(1);
    userTypeVector.push_back(1);
    cout << "You have entered the email: " << email << ", and the password you entered: " << password << "\n";
    cout << "You are being redirected to the start screen to log in to your new account.\n\n";
    return 1;

}

void createLibrarianAccount() {

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

                    Member* member2 = new Member();

                    member2->setEmail("test1");

                    member2->setPassword("test1");

                    member2->setAccountType(1);

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

void adminScreen() {

}

void librarianScreen() {

}

void memberScreen() {
    bookList();
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

        }
        else if (login() == 3) {

        }
    case 3:
        createLibrarianAccount();
    case 4:
        createAdminAccount();
    case 5:
        exit(0);
    default:
        cout << "Invalid input, please try again.\n";
        startScreen();
    }
}

/*
int passwordFunc(string uemail, string upassword) {

    string email;
    string password;

    int attempts = 0;
    string strattempts;

    while (attempts < 3) {

        cout << "Please enter email\n";
        cin >> email;
        cout << "Please enter password\n";
        cin >> password;

        if (email == uemail && password == upassword) {
            cout << "Access Granted!\n";
            return 1;
        }
        else {
            attempts++;
            strattempts = to_string(attempts) + " attempts made.\n";
            if (attempts < 3) {
                cout << "Incorrect Login Attempt. Please try again\n";
            }

            cout << strattempts;
        }

    }
    if (attempts == 3) {
        cout << "Too many attempts, please try again later.\n";
        return 2;
    }

}
*/


int main()
{

    startScreen();

    return 0;

}
