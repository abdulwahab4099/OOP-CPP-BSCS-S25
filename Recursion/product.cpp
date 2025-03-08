#include <iostream>
using namespace std;
int product(int n1,int n2)
{

	
	if(n2==1)
	{
		return n1;
	}
	else
	{
		return n1+=product(n1,n2-1);
	}
	
	
}
int main()
{
	int x,y;
	cout<<"Enter first number :";
	cin>>x;
	cout<<"\nEnter second number :";
	cin>>y;
	if(x==0 || y==0)
	{
		
		cout<<"You entered 0. So product is 0";
	}
	if(x<0 || y<0)
	{
		cout<<"Enter number greater than 0.";
	}
	else
	{
		cout<<"\nProduct of numbers "<<x <<" and "<<y<<" is :"<<product(x,y);
	}
	
	return 0;
}
