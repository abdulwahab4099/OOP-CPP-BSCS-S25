#include <iostream>
using namespace std;
const int MAX=5;
int main()
{
	void centimize(double* , int);
	double varray[MAX]={10.0, 20.0, 30.0, 40.0, 50.0};
	centimize(varray, MAX);
	for(int i=0;i<MAX; i++)
	{
		cout<<"Value at "<<i<<" index is :"<<varray[i]<<"\n";
	}

	
	return 0;
}
void centimize(double* ptr1, int a)
{
	
	for(int i=0; i<a; i++)
	{
		*ptr1++ *=2.54;
	}
	
}