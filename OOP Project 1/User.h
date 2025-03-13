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
	virtual void setPassword();
	virtual void setEmail();
	virtual string getPassword();
	virtual string getEmail();
	virtual ~User();

};