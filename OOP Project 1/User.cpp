#include "User.h"



void User::setpassword()
{
	cout << "Please create a password:\n";
	cin >> userpassword;
}

void User::setemail()
{
	cout << "Please enter an email:\n";
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
