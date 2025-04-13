#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string line;
	fstream file("sample.txt", ios::in | ios::out | ios::trunc);
	if(file.is_open())
	{
		file<<"Hello World!\nMy name is Abdul Wahab.\nIsn't it stupid to learn code when AI can code whole big programs for you?\nIt really doesn't make any sense to me, why we're still struggling and wasting our time learning code.";
	}
	else
	{
		cout<<"Error!";
	}
	
	if (file.good()) // .good() function
	{
	    cout << "File is ready for reading!\n";
	} 
	else 
	{
	    cout << "Something is wrong.\n";
	}
	
	file.seekg(0);
	while (getline(file, line)) 
	{
	    cout << line << endl;
	}
	
	if (file.eof()) 
	{
	    cout << "Reached end of file.\n";
	}
	
	file.close();
	
	ifstream file1("nonexistent.txt");
	
	if (file1.fail()) // .fail() function
	{
	    cout << "Something went wrong (maybe file doesn't exist).\n";
	}
	
	return 0;

}


