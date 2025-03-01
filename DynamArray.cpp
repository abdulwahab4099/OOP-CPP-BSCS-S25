#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	char *pGrades = NULL;
	int size;
	cout<<"Enter size:";
	cin>>size;
	pGrades=new char[size];
	for(int i=0; i<size; i++)
	{
		cout<<"Enter grade #"<<i+1<<":";
		cin>>pGrades[i];
	}
	for(int i=0; i<size; i++)
	{
		
		cout<<pGrades[i]<<" ";
	}
	delete[] pGrades;
	
	return 0;
}
