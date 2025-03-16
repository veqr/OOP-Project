#pragma once
#include <iostream>
using namespace std;

class Book
{
private:
protected:
public:
	bool taken;
	string name;
	string author;
	Book(string name, string author, bool taken);
	virtual void showBooks() const;
	virtual ~Book();
};

