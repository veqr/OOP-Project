#pragma once
#include "User.h"
class Librarian :
    public User
{
private:
protected:
    int userType = 2;
public:
    virtual void addBook();
    virtual void removeBook();
    virtual void updateBook();
    virtual void borrowBook();
    virtual void reserveBook();
    virtual ~Librarian();


};