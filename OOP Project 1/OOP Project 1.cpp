#include <iostream>
#include <string>
#include "User.h"
#include "Member.h"
#include "Book.h"
#include <Vector>
using namespace std;



vector<Book> books;


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

void test1() {
    cout << "You may now use the program.\n";
}

void test2() {
    cout << "Your access has been restricted from this program.\n";
    exit(0);
}

int main()
{
    string email;
    string password;


    Member* member1 = new Member();
    member1->setEmail();
    member1->setPassword();
    email = member1->getEmail();
    password = member1->getPassword();

    if (passwordFunc(email, password) == 1) {
        test1();
    }
    else {
        test2();
    }
    //delete member1;
    //member1 = nullptr;

    return 0;

}
