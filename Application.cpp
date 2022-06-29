#include<iostream>
#include"AddressBook.h"

using namespace std;

int main () 
{
	int opt;
	char c;
	//system("CLS");
	do
	{
		cout<<"-------------------------------START-------------------------------"<<endl;
		cout<<"Welcome to Foundry Address Book"<<endl; 
		cout<<"Please choose from below options :- "<<endl;;
		cout<<"0. Exit the Application.\n1. Add an entry.\n2. Remove an entry.\n3. Retrieve entries in alphabetical order, sorted by first name.\n4. Retrieve entries in alphabetical order, sorted by last name.\n5. Retrieve entries whose first or last name exactly or partially match.\n6. Display Existing Entry."<<endl;
		cout<<"-----------------------------END------------------------------------"<<endl;
		cin>>opt;
		AddressBook Record;

		switch(opt) 
		{
			case 0:
				cout<<"Thank you for using Foundry Address Book. Closing the Application"<<endl;
				exit(1);
			case 1:
				Record.addEntry();
				break;
			case 2:
				Record.removeEntry();
				break;
			case 3:
				Record.retrieveEntrySortByFirstName();
				break;
			case 4:
				Record.retrieveEntrySortByLastName();
				break;
			case 5:
				Record.retrieveByMatchCase();
				break;
			case 6:
				Record.displayExistingEntry();
				break;
			default:
				cout<<"Wrong Input. Please Try again or Press 0 for exit the application."<<endl;
		}
		cout<<"\nPlease press 'y' or 'Y' to continue, otherwise press any other key"<<endl;
		cin>>c;
	}while(c == 'y' || c == 'Y');

  return 0;
}
