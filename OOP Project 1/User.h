#pragma once
#include <string>
#include <iostream>
using namespace std;

class User
{
private:
	string userpassword;
	string useremail;
public:
	virtual void setpassword();
	virtual void setemail();
	virtual string getpassword();
	virtual string getemail();
	//virtual ~User();

};

