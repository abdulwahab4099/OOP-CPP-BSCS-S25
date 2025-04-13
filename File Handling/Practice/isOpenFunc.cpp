#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	fstream file;
	file.open("mydata.txt", ios::in);
	
	if (file.is_open()) 
	{
	    cout << "File opened successfully!\n";
	} 
	else 
	{
	    cout << "Failed to open file.\n";
	}
}


