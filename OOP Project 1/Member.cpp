#include "Member.h"

void Member::getBorrowed()
{
	string takentxt;
	for (int i = 0;i < 5;i++) {

		if (borrowedtaken[i] == true) {
			takentxt = "Taken";
		}
		else {
			takentxt = "Available";
		}

		string book = "Name: " + borrowedname[i] + ", Author: " + borrowedauthor[i] + ", Availibility: " + takentxt + "\n";

		cout << string(book);

	}
}

void Member::setBorrowed()
{
	borrowedname[borrowvalue] = "pname";
	borrowedauthor[borrowvalue] = "pauthor";
	borrowedtaken[borrowvalue] = 1;
}
