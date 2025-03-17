#include "Member.h"
#include "bookManagement.h"


Member::Member(string name, string author, bool taken) : name(name), author(author), taken(taken) {
    {
        borrowedBooks = {
            Book("Name","Author",false)
        };
        reservedBooks = {
            Book("Name","Author",false)
        };
    }
}

void Member::getBorrowed()
{
    string takentxt;
    for (const auto& booknum:borrowedBooks) {

        if (booknum.taken == true) {
            takentxt = "Taken";
        }
        else {
            takentxt = "Available";
        }

        string bookoutput = "Name: " + booknum.name + ", Author: " + booknum.author + ", Availibility: " + takentxt + "\n";

        cout << string(bookoutput);

    }
}

void Member::setBorrowed()
{
    if (borrowedBooks.size() == 6) {
        cout << "Cannot borrow more than 5 books at once.";
    }
    else {
        //borrowedBooks.push_back("FILL THIS IN");
    }
}

Member::~Member()
{
    //cout << "Member\n";
}
