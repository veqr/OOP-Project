#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
protected:
	string userpassword;
	string useremail;
	int userType = 0;
public:
	virtual void setPassword(string password);
	virtual void setEmail(string email);
	virtual void setAccountType(int type);
	virtual string getPassword();
	virtual string getEmail();
	virtual int getAccountType();
	virtual ~User();//detructor

};