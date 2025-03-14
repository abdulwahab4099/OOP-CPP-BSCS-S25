#include <iostream>
#include<fstream>


#include<cstring>

using namespace std;

int main()
{
	string x;
	ofstream f;
	f.open("file.txt");
	if(f)
	{
		//cout<<"\nEnter data in file:";//Displaying output
		f<<"This is first time I've created a file using C++.\n";//writing data to file
		f<<"My name is Abdul Wahab.\n";
		f<<"I'm a computer science undergraduate at Quaid-i-Azam University, Islamabad.\n";
		f<<"I'm from Faisalabad.\n";
		f<<"Right now, I'm learning to code in C++.\n";
		
		f.close();
		
		cout<<"Data written to file successfully!";
		
	}
	else
	{
		cout<<"\nFile creation failed.";
		return 0;
	}
	ifstream file("file.txt", ios::in);
	if(file)
	{
		cout<<"\nFile content:\n";
		while(file)
		{
			getline(file,x);
			cout<<x<<endl;
		}
		file.close();	
	}
	
	else
	{
		cout<<"\nCould not open the file.";
		return 0;
	}
	cout<<"\nAppending to file:";
	ofstream appfile("file.txt", ios::app);
	if(appfile)
	{
		appfile<<"I'm passionate about Artificial Intelligence and Innovation.\n";
		appfile<<"I'm learning and improving my skills day by day.\n";
		appfile.close();
	}
	else
	{
		cout<<"\nCouldn't open the file.";
		return 0;
	}
	cout<<"\nDisplaying data after appending:";
	ifstream file1("file.txt", ios::in);
	if(file1)
	{
		cout<<"\nFile content:\n";
		while(file1)
		{
			getline(file1,x);
			cout<<x<<endl;
		}
		file1.close();	
	}
	
	else
	{
		cout<<"\nCould not open the file.";
		return 0;
	}
		
	return 0;
}
