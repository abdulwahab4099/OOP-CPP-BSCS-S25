#include <iostream>
using namespace std;
int pow(int x, int y)
{
	if(y==0)
		return 1;
	else
		return x* pow(x,y-1);
	
}
int main()
{
	int base, exp;
	cout<<"Enter a number :";
	cin>>base;
	cout<<"\nEnter power :";
	cin>>exp;
	cout<<"\nNumber "<<base<<" with power "<<exp<<" : "<<pow(base,exp);
	return 0;
}
