#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	fstream f1; 
	// fstream f1("File1.txt", ios::in|ios::out)
	f1.open("File1.txt", ios::in | ios::out |ios::trunc);
	if(f1)
	{
		string line;
		//Writing to files
		f1<<"Hello World";
		f1<<"\nHey there! \nI'm practing file handling today.";
		
		
		
		cout<<"\nFile created successfully!";
		cout<<"\nContent of File:";
		
		f1.seekg(0);
		while(getline(f1, line)) 
		{
    		cout << line << endl;
		}
	}
	else
		cout<<"Error!";
	
	f1.close();
	
	return 0;
}