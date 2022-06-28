#include<fstream>
#include<iostream>

using namespace std;

class AddressBook
{
	public:
    	std::string m_firstName;
    	std::string m_lastName;
    	long m_mobileNumber;
	void addEntry()
	{
		std::string p_first, p_last;
        	long p_number;
        	cout<<"Please Enter First Name"<<endl;
        	cin>>p_first;
        	cout<<"Please Enter Last Name"<<endl;
        	cin>>p_last;
        	cout<<"Please Enter Phone Number"<<endl;
        	cin>>p_number;
		m_firstName = p_first;
		m_lastName = p_last;
		m_mobileNumber = p_number;
	}
	void displayRecord()
	{
		cout<<"First Name : "<<m_firstName<<" Last Name : "<<m_lastName<<" Mobile Number : "<<m_mobileNumber<<endl;	
	}	
    	void removeEntryByFirstName(std::string p_first);
    	void retrieveEntrySortByFirstName();
	void retrieveEntrySortByLastName();
	void retrieveByMatchCase(std::string p_name);
	friend istream& operator>>(istream& is, AddressBook& en);
	friend ostream& operator<<(ostream& os, AddressBook& en);
};

	istream& operator>>(istream& is, AddressBook& en)
	{
		is >> en.m_firstName;
		is >> en.m_lastName;
		is >> en.m_mobileNumber;
    		return is;
	}

	ostream& operator<<(ostream& os, AddressBook& en)
	{
		cout<<en.m_firstName<<endl;
    		os << en.m_firstName; // << " " << en.m_lastName << " " << en.m_mobileNumber;
    		return os;
	}

int main () 
{
	ofstream file1;
   	file1.open("Address_Book.txt");

	int opt;
	//system("CLS");
	//AddressBook Obj;
	do
	{
		cout<<"\nFoundry Address Book"<<endl;
		cout<<"Please enter your option";
		cout<<"\n0. Exit the Application.\n1. Add an entry.\n2. Remove an entry.\n3. Retrieve entries in alphabetical order, sorted by first name.\n4. Retrieve entries in alphabetical order, sorted by last name.\n5. Retrieve entries whose first or last name exactly or partially match."<<endl;
		cin>>opt;
		AddressBook Record;

		switch(opt) 
		{
			case 0:
				cout<<"Thank you for using Foundry Address Book. Closing the Application"<<endl;
				exit(1);
			case 1:
				Record.addEntry();
				//Record.displayRecord();
				file1 << Record;
				break;
			case 2:
				//removeEntry();
				break;
			default:
				cout<<"Wrong Input. Please Try again or Press 0 for exit the application."<<endl;
		}
	}while(1);


  file1.close();
  return 0;
}
