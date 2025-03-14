#pragma once
#include "Book.h"
#include <Vector>
#include <string>
#include <iostream>

class bookManagement
{
private:
	vector<Book> books;
protected:
public:
	bookManagement();
	virtual void show();
	vector<Book*> filterTaken(const bool taken);
};
