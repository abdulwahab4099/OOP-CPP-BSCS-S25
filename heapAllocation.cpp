#include <iostream>
#include <new>

using namespace std;
int main()
{
	int *ptr = new int;
	cout<<ptr<<endl;
	*ptr=5;
	cout<<*ptr<<endl;
	
	float *ptr1 = new float;
	cout<<ptr1<<endl;
	*ptr1=5.67;
	cout<<*ptr1;
	int n;
	cout<<"\nEnter array size:";
	cin>>n;
	int *p= new int[n];
	
	for(int i=0; i<n;i++)
	{
		p[i]=i+1;
	}
	
	for(int i=0; i<n;i++)
	{
		cout<<"\n"<<p[i];
	}
	
	delete ptr;
	delete ptr1;
	delete p;
	return 0;
}
