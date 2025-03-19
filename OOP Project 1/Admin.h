#pragma once
#include "User.h"
class Admin :
    public User
{
private:
protected:
    int userType = 3;
public:
    virtual ~Admin();//detructor
};

