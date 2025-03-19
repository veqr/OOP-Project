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

bookManagement* currentBooksList = new bookManagement(); //creates new object which holds all the books
Member* memberBooks = new Member(name, author, taken); //creates object which holds the books the member currently logged on is borrowing

vector<string> userEmailVector = {"M","L","A","M M"}; //vector to hold the email data for all user. currently filled with some testing emails
vector<string> userPasswordVector = {"M","L","A","M M"}; //vector to hold the password data for all user. currently filled with some testing passwords
vector<int> userTypeVector = {1,2,3,1}; //vector to hold the account type data for all user. currently filled with some testing types

Member* member1 = new Member(name, author, taken); //this creates a member object
Librarian* librarian1 = new Librarian(); //this creates a librarian object
Admin* admin1 = new Admin(); //this creates an admin object






void bookList() {
    currentBooksList->show(); //this calls to the bookManagement class to run the show function
}

int createMemberAccount() {

    string newemail;
    string newpassword;


    cout << "Please enter an email:\n";
    cin >> newemail;
    cin.clear(); //makes sure spaces do not make the code skip lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //makes sure spaces do not make the code skip lines


    cout << "Please create a password:\n";
    cin >> newpassword;
    cin.clear(); //makes sure spaces do not make the code skip lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //makes sure spaces do not make the code skip lines


    userEmailVector.push_back(newemail); //adding the newly set email to the email vector
    userPasswordVector.push_back(newpassword); //adding the newly made password to the password vector
    userTypeVector.push_back(1); //appending 1 to the account type vector to make the user a member account

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
    if (librarianpassword == "Library123") {//will only let the user create a librarian account if they enter a password provided by the library staff
        cout << "Librarian password recognised. Please proceed.\n";
    }
    else {
        cout << "Librarian password not recognised.\n";
        return 5;
    }

    cout << "Please enter an email:\n";
    cin >> newemail;
    cin.clear();//makes sure spaces do not make the code skip lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//makes sure spaces do not make the code skip lines

    cout << "Please create a password:\n";
    cin >> newpassword;
    cin.clear();//makes sure spaces do not make the code skip lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//makes sure spaces do not make the code skip lines

    userEmailVector.push_back(newemail);//adding the newly set email to the email vector
    userPasswordVector.push_back(newpassword);//adding the newly made password to the password vector
    userTypeVector.push_back(2);//appending 2 to the account type vector to make the user a librarian account

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
    if (adminpassword == "Admin123") {//will only let the user create an admin account if they enter a password provided by the admins
        cout << "Admin password recognised. Please proceed.\n";
    }
    else {
        cout << "Admin password not recognised.\n";
        return 5;
    }

    cout << "Please enter an email:\n";
    cin >> newemail;
    cin.clear();//makes sure spaces do not make the code skip lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//makes sure spaces do not make the code skip lines

    cout << "Please create a password:\n";
    cin >> newpassword;
    cin.clear();//makes sure spaces do not make the code skip lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//makes sure spaces do not make the code skip lines

    userEmailVector.push_back(newemail);//adding the newly set email to the email vector
    userPasswordVector.push_back(newpassword);//adding the newly made password to the password vector
    userTypeVector.push_back(3);//appending 3 to the account type vector to make the user an admin account

    cout << "You have entered the email: " << newemail << ", and the password you entered: " << newpassword << "\n";
    cout << "You are being redirected to the start screen to log in to your new account.\n\n";
    return 3;
}

int login() {

    string email;
    string password;

    int attempts = 0;
    string strattempts;

    while (attempts < 3) {//loops for 3 login attempts

        cout << "Please enter email\n";
        cin >> email;
        cin.clear();//makes sure spaces do not make the code skip lines
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//makes sure spaces do not make the code skip lines

        cout << "Please enter password\n";
        cin >> password;
        cin.clear();//makes sure spaces do not make the code skip lines
        cin.ignore(numeric_limits<streamsize>::max(), '\n');//makes sure spaces do not make the code skip lines

        for (int i = 0; i < userEmailVector.size(); i++) {//loops through all the users
            if (email == userEmailVector[i] && password == userPasswordVector[i]) {//if the email and password that the user has entered matches the vectors then the program proceeds
                cout << "Access Granted!\n";
                if (userTypeVector[i] == 1) {//if the account type is 1 then it will set the member object which was created previously to the details of what the user has just entered

                    member1->setEmail(email);

                    member1->setPassword(password);

                    member1->setAccountType(1);

                    accountType = 1;

                    return 0;
                }
                else if (userTypeVector[i] == 2) {//if the account type is 2 then it will set the librarian object which was created previously to the details of what the user has just entered

                    librarian1->setEmail(email);

                    librarian1->setPassword(password);

                    librarian1->setAccountType(2);

                    accountType = 2;

                    return 0;

                }
                else if (userTypeVector[i] == 3) {//if the account type is 3 then it will set the admin object which was created previously to the details of what the user has just entered

                    admin1->setEmail(email);

                    admin1->setPassword(password);

                    admin1->setAccountType(3);

                    accountType = 3;

                    return 0;
                }
                else {
                    cout << "Invalid";//if the account type number is none of these then the account is invalid
                }
            }
        }

        attempts++;//increments the attempts counter
        strattempts = to_string(attempts) + " attempts made.\n";//tells the user how many attempts they have made

        if (attempts < 3) {
            cout << "Incorrect Login Attempt. Please try again\n";//tells the user that they have not inputted their details correctly
            cout << strattempts;
        }


        if (attempts > 3) {
            cout << "Too many attempts, please try again later.\n";//if the user takes too many attempts they are informed and sent back to the start screen

        }
    }
        

}

void showBorrowedBooks() {

    cout << "You are currently borrowing:\n";
    for (int i = 1; i < memberBooks->borrowedBooks.size(); i++) {//loops through all the books the user currently is borrowing
        string bookname = memberBooks->borrowedBooks[i].name;
        string bookauthor = memberBooks->borrowedBooks[i].author;
        cout << "Name: " << bookname << ", Author: " << bookauthor << ", Borrowed\n";//prints neatly what the name and author of the book is and states that it is being borrowed
    }
}

void showReservedBooks() {

    cout << "You are currently reserving:\n";
    for (int i = 1; i < memberBooks->reservedBooks.size(); i++) {//loops through all the books the user currently is reserving
        string bookname = memberBooks->reservedBooks[i].name;
        string bookauthor = memberBooks->reservedBooks[i].author;
        cout << "Name: " << bookname << ", Author: " << bookauthor << ", Reserved\n";//prints neatly what the name and author of the book is and states that it is being reserved
    }
}

void returnScreen() {

    int bookchoice;
    bool found = false;
    for (int i = 1; i < memberBooks->borrowedBooks.size(); i++) {//loops through all the borrowed books from the user
        string bookname = memberBooks->borrowedBooks[i].name;
        string bookauthor = memberBooks->borrowedBooks[i].author;
        cout << i << ", Name: " << bookname << ", Author: " << bookauthor << ", Borrowed\n";//outputs with a numbered order what books are being borrowed
    }
    cout << "Enter a number from the book list above to return a book.\n";
    cin >> bookchoice;
    cout << "You are returning: " << memberBooks->borrowedBooks[bookchoice].name << "\n";
    for (int v = 1; v < currentBooksList->books.size(); v++) {//loops through the books vector
        if (memberBooks->borrowedBooks[bookchoice].name == currentBooksList->books[v].name) {//checks that the names are the same for an extra layer of accuracy
            currentBooksList->books[v].taken = false;//changes the availability from borrowed to available
            found = true;
        }
    }
    if (found == true) {//if the return is successful the code progresses here
        cout << memberBooks->borrowedBooks[bookchoice].name << " has been returned.\n";//tells the user what book they returned to make sure they returned the correct one
        memberBooks->borrowedBooks.erase(memberBooks->borrowedBooks.begin() + bookchoice);//deletes the book from the member's borrow list
    }
    else {
        cout << "This book has not been found.\n";
    }
}

void searchBooks() {
    
    string booksearch;
    cout << "Please enter the name of a book you wish to search by name or the author you wish to search for, replace any spaces with an underscore.\n";
    cin >> booksearch;
    cin.clear();//makes sure spaces do not make the code skip lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//makes sure spaces do not make the code skip lines

    for (int booknum = 0; booknum < currentBooksList->books.size(); booknum++) {//loops through the books vector
        if (booksearch == currentBooksList->books[booknum].name) {//checks if the name the user entered matches any names in the books vector
            string takentxt;
            if (currentBooksList->books[booknum].taken == 1) {
                takentxt = "Borrowed";//informs the user that the book is currently being borrowed
            }
            else {
                takentxt = "Available";//tells the user that the bnook is available
            }


            cout << "Name: " << currentBooksList->books[booknum].name << ", Author: " << currentBooksList->books[booknum].author << ", Availability: " << takentxt << "\n";//outputs the book that was found
        }//if there are no matches then the code progresses here
        if (booksearch == currentBooksList->books[booknum].author) {//checks if the title the user entered matches any names in the books vector
            string takentxt;
            if (currentBooksList->books[booknum].taken == 1) {
                takentxt = "Borrowed";//informs the user that the book is currently being borrowed
            }
            else {
                takentxt = "Available";//tells the user that the bnook is available
            }


            cout << "Name: " << currentBooksList->books[booknum].name << ", Author: " << currentBooksList->books[booknum].author << ", Availability: " << takentxt << "\n";//outputs the book that was found
        }
    }
}

void borrowScreen() {

    int bookchoice;
    cout << "Enter a number from the book list below to borrow a book.\n";
    bookList();//lists all the books in a numbered order
    cin >> bookchoice;
    Book bookstemp = currentBooksList->books[bookchoice];//temporary vector
    if (bookstemp.taken == false) {//if the book is available
        cout << "You have chosen: " << bookstemp.name << "\n";//tells the user the name of the book they chose
        if (memberBooks->borrowedBooks.size() < borrowLimit + 1) {//checks if the user is at the limit of borrowing books
            bookstemp.taken = true;
            currentBooksList->books[bookchoice].taken = true;//changes the availability to borrowed
            memberBooks->borrowedBooks.emplace_back(bookstemp.name, bookstemp.author, bookstemp.taken);//adds the book to the member's book vector
        }
        else {
            cout << "You are already borrowing 5 books. Please return a book to be able to borrow another.";
        }
        showBorrowedBooks();//shows the user what books they are currently borrowing
    }
}

void reservedScreen() {

    int bookchoice;
    cout << "Enter a number from the book list below to reserve a book.\n";
    bookList();//lists all the books in a numbered order
    cin >> bookchoice;
    Book bookstemp = currentBooksList->books[bookchoice];//temporary vector
    if (bookstemp.taken == true) {//if the book is borrowed
        cout << "You have chosen: " << bookstemp.name << "\n";//tells the user what they chose
        currentBooksList->books[bookchoice].taken = true;
        memberBooks->reservedBooks.emplace_back(bookstemp.name, bookstemp.author, bookstemp.taken);//adds the book to the reserved vector
        showReservedBooks();//shows the books the user is reserving
    }
    else {
        cout << "The book is available so it cannot be reserved.\n";//if the book is available the user cannot reserve it so they must borrow it instead
    }
}

void addBook() {

    string newname;
    string newauthor;
    cout << "Please enter a new book name\n";
    cin >> newname;
    cin.clear();//makes sure spaces do not make the code skip lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//makes sure spaces do not make the code skip lines
    cout << "Please enter a new book author\n";
    cin >> newauthor;
    cin.clear();//makes sure spaces do not make the code skip lines
    cin.ignore(numeric_limits<streamsize>::max(), '\n');//makes sure spaces do not make the code skip lines
    currentBooksList->books.emplace_back(newname, newauthor, false);//adds the new book to the books vector with the parameters which the librarian has entered

    bookList();
}

void removeBook() {
    int delbook;
    cout << "Enter the number to delete a book.\n";
    bookList();//shows the current vector of books
    cin >> delbook;
    currentBooksList->books.erase(currentBooksList->books.begin() + delbook);//deletes the book the librarian entered
    cout << "This is the new list of books:\n\n";
    bookList();//shows the updated vector, books 
}

void updateBook() {
    int updatebook;
    cout << "Enter the number to update a book's status.\n";
    bookList();//shows the current vector of books
    cin >> updatebook;
    if (currentBooksList->books[updatebook].taken == true) {//swaps the bool
        currentBooksList->books[updatebook].taken = false;
    }
    else {
        currentBooksList->books[updatebook].taken = true;
    }
    cout << "Status ahs been updated.\n\n";
    bookList();//shows the updated vector, books 
    
}

void borrowedList() {
    for (int i = 0; i < currentBooksList->books.size(); i++) {//loops through all the books
        if (currentBooksList->books[i].taken == true) {//if the book is being borrowed
            cout << i << ", Name: " << currentBooksList->books[i].name << ", Author: " << currentBooksList->books[i].author << ", Currently being borrowed.\n";//only outputs the books being borrowed
        }
        
    }
}

void setBorrowLimit() {
    int templim;
    cout << "Please enter the borrowing limit\n";
    cin >> templim;
    cout << "The limit has now been set to " << templim;
    borrowLimit = templim + 1;//sets the borrow limit
}

void setLatePenalty() {
    float temppen;
    cout << "Please enter the late penalty.\n";
    cin >> temppen;
    cout << "The late penalty has been set to " << temppen;
    latePenalty = temppen + 1;//sets the late penalty
}

void manageAccounts() {
    int accountDel;
    cout << "Listed below are all the users in a numerical order.\n";
    for (int i = 0; i < userPasswordVector.size(); i++) {//loops through all users
        cout << i << ", " << userPasswordVector[i] << "\n";//lists the users
    }
    cout << "\nPlease enter the number of the user you would like to delete, enter -1 to return to the Admin Screen.\n";
    cin >> accountDel;
    switch (accountDel) {
    case -1://cancellable case since this could be very dangerous
        cout << "Cancelled\n";
    default:
        userEmailVector.erase(userEmailVector.begin() + accountDel);//deletes the email
        userPasswordVector.erase(userPasswordVector.begin() + accountDel);//deletes the password
        userTypeVector.erase(userTypeVector.begin() + accountDel);//deletes the account type
        cout << "Account Deleted\n";
    }
}

void adminScreen() {
    int choice;
    cout << "This is the Admin Screen.\n\n";
    cout << "Please enter the number the select a choice.\n\n1 to change the borrowing limit.\n2 to change the late penalty.\n3 to manage another account.\n";
    cin >> choice;
    switch (choice) {//determines what function is called depending on what the user enters
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
    switch (choice) {//determines what function is called depending on what the user enters
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
    switch (choice) {//determines what function is called depending on what the user enters
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
        if (createMemberAccount() == 1);//if creation is successful,
        startScreen();//go to start screen
    case 2:
        login();
        if (member1->getAccountType() == 1) {//if account type is 1, call memberscreen function
            memberScreen();
        }
        else if(librarian1->getAccountType() == 2) {//if account type is 2, call librarianscreen function
            librarianScreen();
        }
        else if (admin1->getAccountType() == 3) {//if account type is 3, call adminscreen function
            adminScreen();
        }
        else {
            cout << "Invalid account type";
        }
    case 3:
        createLibrarianAccount();//go to create a librarian account
        startScreen();
        
    case 4:
        createAdminAccount();//go to create an admin account
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