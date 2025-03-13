#include <iostream>
#include <string>
#include "User.h"
using namespace std;


void passwordFunc() {


    int attempts = 0;
    string strattempts;
    string userpassword;
    string email;

    while (attempts < 3) {

        cout << "Please enter email\n";
        cin >> email;
        cout << "Please enter password\n";
        cin >> userpassword;

        if (email == "temp@gmail.com" && userpassword == "1234") {
            cout << "Access Granted!\n";
            break;
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
    }

}

int main()
{
    passwordFunc();


}
