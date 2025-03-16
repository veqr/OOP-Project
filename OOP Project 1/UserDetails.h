#pragma once
#include <iostream>
#include <Vector>
using namespace std;

class UserDetails
{
private:
protected:
public:
	vector<UserDetails> userDetailsVector;
	string storedEmail;
	string storedPassword;
	UserDetails(string storedEmail, string storedPassword);
	virtual void userDetailsList() const;
	virtual ~UserDetails();
};

