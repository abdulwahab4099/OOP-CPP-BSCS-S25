//Recursion
//Recursive Function
#include <iostream>
using namespace std;

int factorial(int n)
{
	if(n==0)
	{
		return 1;
	}
	return n * factorial(n-1);
}

int main()
{
	int num;
	cout<<"Enter a number: ";
	cin>>num;
	cout<<"\nThe factorial of "<<num<<" is :"<<factorial(num);
	cout<<"\nThe term in fibonacci sequence at position "<<num<<" is "<<fibonacci(num);
	return 0;
	
}

