#include "bookManagement.h"

bookManagement::bookManagement()
{
    books = {
    Book("The_Stand","Steven_King",false),
    Book("The_Hunger Games","Suzanne_Collins",false),
    Book("Harry_Potter_and_the_Sorcerer's_Stone","J.K._Rowling",false),
    Book("Lord_of_the_Flies","George_Orwell",false),
    Book("Fifty_Shades_of_Grey","E.L._James",false)

    };
}

void bookManagement::show()
{
    int i = 0;
    for (const auto& booknum:books) {
        cout << "Book: " << i << ", ";
        booknum.showBooks();
        i++;
    }
}
int bookManagement::filterTaken(const bool taken)
{
    vector<Book*> filter;
    for (auto& bookfilter : books) {
        if (bookfilter.taken == false) {
            filter.push_back(&bookfilter);
        }

    }
    return 0;
}

bookManagement::~bookManagement()
{
    //cout << "Book Management Object has been destroyed\n";
}
