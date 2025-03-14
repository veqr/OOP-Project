#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
protected:
	string userpassword;
	string useremail;
	int type;
public:
	virtual void setPassword(string password);
	virtual void setEmail(string email);
	virtual string getPassword();
	virtual string getEmail();
	virtual ~User();

};