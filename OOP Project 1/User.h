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
	void setpassword();
	void setemail();
	string getpassword();
	string getemail();
	//virtual ~User();

};

