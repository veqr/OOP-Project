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
	int filterTaken(const bool taken);
	virtual ~bookManagement();
};
