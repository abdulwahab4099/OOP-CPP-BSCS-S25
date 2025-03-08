#include <iostream>
using namespace std;
int fibonacci(int n)
{
	if(n<2 && n>-1)
	{
		return 1;
	}
	return fibonacci(n-2)+fibonacci(n-1);
}
int main()
{
	int num;
	cout<<"Enter a number: ";
	cin>>num;
	
	cout<<"\nThe term in fibonacci sequence at position "<<num<<" is "<<fibonacci(num);
	return 0;
	
}
