#include "Book.h"

Book::Book(string name, string author, bool taken):name(name),author(author),taken(taken){}

void Book::showBooks() const
{
	string takentxt;
	if (taken == true) {
		takentxt = "Taken";
	}
	else {
		takentxt = "Available";
	}
	cout << "Name: " << name << ", Author: " << author << ", Availability: " << takentxt <<"\n";

}

Book::~Book()
{
	//cout << "Book object destroyed\n";
}
