#include <iostream>
#include <string>
#include "User.h"
#include "Member.h"
#include "Book.h"
#include "Librarian.h"
#include "bookManagement.h"
#include <Vector>
using namespace std;


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

void bookList() {
    
    vector<Book> books;

    books = {
        Book("The Stand","Steven King",false),
        Book("The Hunger Games","Suzanne Collins",false),
        Book("Harry Potter and the Sorcererís Stone","J.K. Rowling",false),
        Book("Lord of the Flies","George Orwell",false),
        Book("Fifty Shades of Grey","E.L. James",false)

    };
}

void test1() {
    //cout << "You may now use the program.\n";
}

void test2() {
    cout << "Your access has been restricted from this program.\n";
    exit(0);
}

int main()
{



    string email;
    string password;
    string newemail;
    string newpassword;

/*
    Member* member1 = new Member();
    
    cout << "Please enter an email:\n";
    cin >> newemail;
    
    member1->setEmail(newemail);

    cout << "Please create a password:\n";
    cin >> newpassword;

    member1->setPassword(newpassword);

    email = member1->getEmail();
    password = member1->getPassword();
    cout << email << ", " << password << "\n";
*/

    Member* member2 = new Member();
    member2->setEmail("test");
    member2->setPassword("test");
/*
    if (passwordFunc(email, password) == 1) {
        member1->setBorrowed();
        member1->getBorrowed();
        test1();
    }
    else {
        test2();
    }
*/
    //delete member1;
    //member1 = nullptr;

    return 0;

}
