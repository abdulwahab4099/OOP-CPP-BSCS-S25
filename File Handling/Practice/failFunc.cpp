#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	ifstream file("nonexistent.txt");
	
	if (file.fail()) 
	{
	    cout << "Something went wrong (maybe file doesn't exist).\n";
	}
	
	

}


