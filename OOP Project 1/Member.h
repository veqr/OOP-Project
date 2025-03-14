#pragma once
#include "User.h"
#include <string>
#include <iostream>
class Member :
    public User
{
private:
protected:
    string borrowedname[5];
    string borrowedauthor[5];
    bool borrowedtaken[5];
    string reserved[5];
public:
    int borrowingtotal;
    int borrowvalue;
    string borrowname;
    string borrowauthor;
    bool borrowtaken;
    virtual void getBorrowed();
    virtual void setBorrowed();
};