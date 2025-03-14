#pragma once
#include "User.h"
#include <string>
#include <iostream>
#include <Vector>
#include "Book.h"

class Member :
    public User
{
private:
protected:
    vector<Book> borrowedBooks;
    //string reserved[5];
public:
    Member();
    virtual void getBorrowed();
    vector<Book*> setBorrowed();
    int borrowTotal = 0;
};