#include "UserDetails.h"

UserDetails::UserDetails(string storedEmail, string storedPassword):storedEmail(storedEmail),storedPassword(storedPassword){
	userDetailsVector = {
		UserDetails("test","test")
	};
}

void UserDetails::userDetailsList() const
{
	for (const auto& detailsnum : userDetailsVector) {
		//cout << userDetailsVector;
	}
}

UserDetails::~UserDetails()
{
	cout << "UserDetails\n";
}
