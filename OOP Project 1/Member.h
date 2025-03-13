#pragma once
#include "User.h"
#include <string>
#include <iostream>
class Member :
    public User
{
private:
protected:
    string borrowed[5];
    string reserved[5];
public:
    int borrowingtotal;
    virtual string getBorrowed();
};