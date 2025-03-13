#include "Book.h"

string Book::show()
{
	string takentxt;
	if (taken == 1) {
		takentxt = "Taken";
	}
	else {
		takentxt = "Available";
	}
	cout << "Name: " << name << ", Author: " << author << ", Availability: " << takentxt;

	//return string();
}
