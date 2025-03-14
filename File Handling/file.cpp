#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;
int main()
{
	ofstream fout;
	fout.open("z1.txt");
	fout<<"Hello Quaidians!";
	fout<<"\nThis is Abdul Wahab.";
	fout<<"\nI'm from Faisalabad, currently living in Islamabad.";
	fout.close();
	
	ifstream fin;
	fin.open("z1.txt");
	string line;
	while(getline(fin,line))
	{
		cout<<line<<endl;
	}
	fin.close();
	
	return 0;
}

