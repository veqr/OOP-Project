#include "Book.h"


void Book::show()
{
	string takentxt;
	if (taken == true) {
		takentxt = "Taken";
	}
	else {
		takentxt = "Available";
	}
	cout << "Name: " << name << ", Author: " << author << ", Availability: " << takentxt;

}

Book::Book(string name, string author, bool taken):name(name),author(author),taken(taken){}