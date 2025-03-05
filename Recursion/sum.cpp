#include <iostream>
using namespace std;
int sum(int n1,int n2)
{
	if(n2==0)
	{
		return n1;
	}
	
	return sum(n1+1,n2-1);
}
int main()
{
	int n,m;
	cout<<"Enter first  :";
	cin>>n;
	cout<<"\nEnter second number :";
	cin>>m;
	if(n<0)
		n=n*(-1);
	
	if(m<0)
		m=m*(-1);
	
	cout<<"\nThe sum of two numbers |"<<n<<"| and |"<<m<<"| is :"<<sum(n,m);
	return 0;
}
