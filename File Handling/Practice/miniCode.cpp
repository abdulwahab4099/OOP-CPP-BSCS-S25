#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
	string line;
	fstream file("mini code.txt", ios::in | ios::out | ios::trunc);
	if(file)
	{
		cout<<"File named 'mini code' created.\n";
		file<<"Hello QAU, Islamabad!\nWe are here for almost 4 years now.\nBe nice to us.\nBTW, we love you!\nYou're really a nice place.";
		
		file.seekg(0);
		while(getline(file,line))
		{
			cout<<line<<endl;
		}
	}
	else
	{
		cout<<"Error!!";
	}
	file.close();
	
	return 0;

}


