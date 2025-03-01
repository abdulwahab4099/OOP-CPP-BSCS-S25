/*
Lab Task
Function Overloading
*/

#include <iostream>
#include <new>
using namespace std;
int calculate (int,int);
int calculate (int,int,int);
float calculate (float,float);

int calculate (int n1, int n2)
{
	cout<<"Sum of the two numbers:" <<n1+n2<<endl;
}

int calculate (int n1,int n2, int n3)
{
	cout<<"Product of the three numbers:"<<n1*n2*n3<<endl;
}

float calculate (float n4, float n5)
{
	cout<<"Average of the two float numbers:"<<(n4+n5)/2<<endl;
}
int main()
{
	int num1,num2,num3;
	float num4, num5;
	cout<<"Enter a number:";
	cin>>num1;
	cout<<"Enter 2nd number:";
	cin>>num2;
	cout<<"Enter 3rd number:";
	cin>>num3;
	cout<<"Enter 4th number:";
	cin>>num4;
	cout<<"Enter 5th number:";
	cin>>num5;
	
	calculate(num1,num2);
	calculate(num1,num2,num3);
	calculate(num4,num5);
	return 0;
	
	
	
}
