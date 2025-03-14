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
	virtual void show();
	Book(string name, string author, bool taken);
};

