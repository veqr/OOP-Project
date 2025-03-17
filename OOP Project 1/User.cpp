#include "User.h"

void User::setPassword(string password)
{
	this->userpassword = password;
}

void User::setEmail(string email)
{
	this->useremail = email;
}

void User::setAccountType(int type)
{
	this->userType = type;
}

string User::getPassword()
{
	return string(userpassword);
}

string User::getEmail()
{
	return string(useremail);
}

int User::getAccountType()
{
	return(userType);
}

User::~User()
{
	//cout << "User has been deleted\n";
}