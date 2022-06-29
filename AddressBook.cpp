#include<fstream>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<algorithm>
#include<regex>
#include"AddressBook.h"

using namespace std;

std::string filePath = "Address_Book.txt";

void AddressBook :: addEntry()
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
	file.open(filePath, ios::in | ios::out | ios::app);
	file << m_firstName << " " << m_lastName << " " << m_mobileNumber << endl;;
	cout<<"New Entry Added : ";
	cout<<m_firstName<<" "<<m_lastName<<" "<<m_mobileNumber<<endl;	
	file.close();
}

void AddressBook :: removeEntry()
{
	string input_str;
	cout<<"Please enter First Name/Last Name/Phone Number to remove Entry"<<endl;
	cin>>input_str;
	
	string myLine;
	ifstream file;
	file.open(filePath, ios::in | ios::out | ios::app);
	ofstream temp;
	temp.open("temp.txt");
	if(file.is_open())
	{
		while(getline(file, myLine))
		{
			size_t found = myLine.find(input_str);
			if(found != string::npos)
				cout<<"The input entry removed successfully"<<endl;
			else
				temp << myLine << endl;
		}
	}
	else
		cout<<"Unable to open the File"<<endl;

	temp.close();
	file.close();

	const char *p = filePath.c_str();
	remove(p);
	rename("temp.txt", p);
}

void AddressBook :: retrieveEntrySortByFirstName()
{
	string myLine;
	vector<string> myVec;
	ifstream file;
	file.open(filePath, ios::in | ios::out | ios::app);
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

void AddressBook :: retrieveEntrySortByLastName()
{
	string myLine;
	vector<string> myVec;
	ifstream file;
	file.open(filePath, ios::in | ios::out | ios::app);
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

void AddressBook :: retrieveByMatchCase()
{
	string input_str;
	cout<<"Please enter First Name/Last Name exactly or partially to retrieve"<<endl;
	cin>>input_str;
	
	string myLine;
	ifstream file;
	regex r("\\b" + input_str );
	smatch m;
	file.open(filePath, ios::in | ios::out | ios::app);
	cout<<"Matched Entries are :- "<<endl;
	if(file.is_open())
	{
		while(file)
		{
			getline(file, myLine);
			if(regex_search(myLine,m,r))
				cout<<myLine<<endl;
		}
	}
	else
		cout<<"Unable to open the File"<<endl;

	file.close();
}

void AddressBook :: displayExistingEntry()
{
	string myLine;
	ifstream file;
	file.open(filePath, ios::in | ios::out | ios::app);
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
