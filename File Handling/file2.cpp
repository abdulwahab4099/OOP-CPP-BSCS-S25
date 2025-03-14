#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ifstream fin;
	fin.open("zoom.txt");
	char c;
	//fin>>c;
	c=fin.get();
	while(!fin.eof())
	{
		cout<<c;
		//fin>>c;
		c=fin.get();
	}
	fin.close();
}
