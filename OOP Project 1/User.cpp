#include "User.h"

void User::setPassword(string password)
{
	this->userpassword = password;
}

void User::setEmail(string email)
{
	this->useremail = email;
}

string User::getPassword()
{
	return string(userpassword);
}

string User::getEmail()
{
	return string(useremail);
}

User::~User()
{
	cout << "User has been deleted\n";
}