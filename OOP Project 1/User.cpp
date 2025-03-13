#include "User.h"

void User::setPassword()
{
	cout << "Please create a password:\n";
	cin >> userpassword;
}

void User::setEmail()
{
	cout << "Please enter an email:\n";
	cin >> useremail;
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