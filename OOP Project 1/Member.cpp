#include "Member.h"
#include "bookManagement.h"


Member::Member()
{
	borrowedBooks = {};
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
    if (borrowedBooks.size() == 5) {
        cout << "Cannot borrow more than 5 books at once.";
    }
    else {
        //borrowedBooks.push_back("FILL THIS IN");
    }
}

Member::~Member()
{
    cout << "Member\n";
}
