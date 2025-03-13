#include <iostream>
#include <string>
#include "User.h"
using namespace std;

/*void passwordFunc() {

    string email;
    string password;

    int attempts = 0;
    string strattempts;

    while (attempts < 3) {

        if (email == user1->getemail() && password == user1->getpassword()) {
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
*/

int main()
{
    string email;
    string password;


    User* user1 = new User();
    user1->setemail();
    user1->setpassword();
    user1->getemail();
    user1->getpassword();

    //passwordFunc();
    return 0;

}

