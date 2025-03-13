#include "User.h"



void User::setpassword()
{
	cout << "Please create a password";
	cin >> userpassword;
}

void User::setemail()
{
	cout << "Please enter an email";
	cin >> useremail;
}

string User::getpassword()
{
	return string(userpassword);
}

string User::getemail()
{
	return string(useremail);
}

/*User::getpassword()
{
	return userpassword;
}

User::getemail()
{
	return useremail;
}

User::~User()
{
}
*/
