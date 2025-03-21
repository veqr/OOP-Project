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
    int userType = 1;
    //string reserved[5];
public:
    bool taken;
    string name;
    string author;
    vector<Book> borrowedBooks;
    vector<Book> reservedBooks;
    Member(string name, string author, bool taken);
    virtual void getBorrowed();
    void setBorrowed();
    int borrowTotal = 0;
    virtual ~Member();//detructor
};