#include<iostream>

using namespace std;

class AddressBook
{
	string m_firstName;
	string m_lastName;
	long m_mobileNumber;
public:
	void addEntry();
	void removeEntry();
	void retrieveEntrySortByFirstName();
	void retrieveEntrySortByLastName();
	void retrieveByMatchCase();
	void displayExistingEntry();
};
