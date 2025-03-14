#include "bookManagement.h"

bookManagement::bookManagement()
{
    books = {
    Book("The Stand","Steven King",false),
    Book("The Hunger Games","Suzanne Collins",false),
    Book("Harry Potter and the Sorcerer’s Stone","J.K. Rowling",false),
    Book("Lord of the Flies","George Orwell",false),
    Book("Fifty Shades of Grey","E.L. James",false)

    };
}

void bookManagement::show()
{
    for (const auto& booknum:books) {
        booknum.showBooks();
    }
}
vector<Book*> bookManagement::filterTaken(const bool taken)
{
    vector<Book*> filter;
    for (auto& bookfilter : books) {
        if (bookfilter.taken == false) {
            filter.push_back(&bookfilter);
        }

    }
}