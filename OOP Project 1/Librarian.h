#pragma once
#include "User.h"
class Librarian :
    public User
{
private:
protected:
    int userType = 2;
public:
    virtual ~Librarian();//detructor


};