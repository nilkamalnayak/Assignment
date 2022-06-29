#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class AddressBook
{
    	std::string m_firstName;
    	std::string m_lastName;
    	long m_mobileNumber;
	public:
		void addEntry()
		{
			std::string p_first, p_last;
        	long p_number;
        	cout<<"Please enter below Details : "<<endl;
        	cout<<"First Name : ";
        	cin>>p_first;
        	cout<<"Last Name : ";
        	cin>>p_last;
        	cout<<"Mobile Number : ";
        	cin>>p_number;
			m_firstName = p_first;
			m_lastName = p_last;
			m_mobileNumber = p_number;
			ofstream file;
			file.open("Address_Book.txt", ios::in | ios::out | ios::app);
			file << m_firstName << " " << m_lastName << " " << m_mobileNumber << endl;;
			cout<<"New Entry Added : ";
			cout<<m_firstName<<" "<<m_lastName<<" "<<m_mobileNumber<<endl;	
			file.close();
		}
    	void removeEntry()
		{
			string input_str;
        	cout<<"Please enter First Name or Last Name or Phone Number to remove Entry"<<endl;
			cin>>input_str;
		/*	
			string line;
			ifstream file;
			file.open("Address_Book.txt");
			ofstream temp;
			temp.open("temp.txt");
			while(getline(file,line))
			{
				if(line != input_str)
					temp << line <<endl;
			}
			temp.close();
			file.close();

			const char *p = "Address_Book.txt";
			remove(p);
			rename("temp.txt", p);
		*/	
			string myLine;
			ifstream file;
			file.open("Address_Book.txt", ios::in | ios::out | ios::app);
			if(file.is_open())
			{
				while(getline(file, myLine))
				{
					cout<<"NILA : "<<myLine<<endl;
					while(true)
					{
						size_t found = myLine.find(input_str);
						if(found != string::npos)
						{
							cout<<"found"<<endl;
							myLine.replace(found, input_str.length(), "acronis");
							//myLine.replace(myLine.find(input_str), input_str.length(), "acronis");
						}
						else
							break;
					}
					cout<<"myLine : "<<myLine<<endl;
				}
			}
			else
				cout<<"Unable to open the File"<<endl;

			file.close();
		}
    	void retrieveEntrySortByFirstName()
		{
			string myLine;
			vector<string> myVec;
			ifstream file;
			file.open("Address_Book.txt", ios::in | ios::out | ios::app);
			if(file.is_open())
			{
				while(file)
				{
					getline(file, myLine);
					myVec.push_back(myLine);
				}
			}
			else
				cout<<"Unable to open the File"<<endl;
			sort(myVec.begin(), myVec.end());
			for(auto x : myVec)
				cout<<x<<"\n";
			file.close();
		}
		void retrieveEntrySortByLastName()
		{
			string myLine;
			vector<string> myVec;
			ifstream file;
			file.open("Address_Book.txt", ios::in | ios::out | ios::app);
			if(file.is_open())
			{
				while(file)
				{
					getline(file, myLine);
					string word, temp;
					int count = 0;
					istringstream str(myLine);
					string final_str;
					while(str >> word)
					{
						if(count == 1)
							temp = word;
						else
							final_str = final_str +" " +  word;
						count++;
					}
					final_str.insert(0, temp);
					myVec.push_back(final_str);
				}
			}
			else
				cout<<"Unable to open the File"<<endl;
			sort(myVec.begin(), myVec.end());
			for(auto x : myVec)
				cout<<x<<"\n";
			file.close();
			
		}
		void retrieveByMatchCase(std::string p_name);
		void displayExistingEntry()
		{
			string myLine;
			ifstream file;
			file.open("Address_Book.txt", ios::in | ios::out | ios::app);
			if(file.is_open())
			{
				while(file)
				{
					getline(file, myLine);
					cout<<myLine<<endl;
				}
			}
			else
				cout<<"Unable to open the File"<<endl;

			file.close();
		}
};

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
				//retrieveByMatchCase(std::string p_name)
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
