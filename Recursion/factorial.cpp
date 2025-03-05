#include <iostream>
using namespace std;
int fact(int n)
{
	if(n==0)
	{
		return 1;
	}
	return n*fact(n-1);
}
int main()
{
	int a;
	cout<<"Enter a number :";
	cin>>a;
	cout<<"\nThe factorial of number '"<<a<<"' is :"<<fact(a);
	return 0;
}
