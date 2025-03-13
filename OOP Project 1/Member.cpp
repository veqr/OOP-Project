#include "Member.h"

string Member::getBorrowed()
{
	for (int i = 0;i < 5;i++) {
		return string(borrowed[i]);
	}
}
