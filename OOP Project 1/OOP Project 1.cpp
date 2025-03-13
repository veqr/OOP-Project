#include <iostream>
#include <string>
#include "User.h"
using namespace std;

int passwordFunc(string uemail, string upassword) {

    string email;
    string password;

    int attempts = 0;
    string strattempts;

    while (attempts < 3) {

        cout << "Please enter email";
        cin >> email;
        cout << "Please enter password";
        cin >> password;

        if (email == uemail && password == upassword) {
            cout << "Access Granted!\n";
            return 1;
        }
        else {
            cout << "Incorrect Login Attempt. Please try again\n";
            attempts++;
            strattempts = to_string(attempts) + " attempts made.\n";
            cout << strattempts;
        }

    }
    if (attempts == 3) {
        cout << "Too many attempts, please try again later.\n";
        return 2;
    }

}

void test1() {
    cout << "1";
}

void test2() {
    cout << "test2";
}

int main()
{
    string email;
    string password;


    User* user1 = new User();
    user1->setemail();
    user1->setpassword();
    email = user1->getemail();
    password = user1->getpassword();

    if (passwordFunc(email, password) == 2) {
        test1();
    }
    else {
        test2();
    }

    return 0;

}
