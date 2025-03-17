#pragma once
#include "Book.h"
#include <Vector>
#include <string>
#include <iostream>

class bookManagement
{
private:
protected:
public:
	vector<Book> books;
	bookManagement();
	virtual void show();
	int filterTaken(const bool taken);
	virtual ~bookManagement();
};
