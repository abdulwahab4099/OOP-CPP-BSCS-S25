#include <iostream>
using namespace std;

int sumDig(int num)
{
	if(num<10 && num>=0)
	{
		return num;
	}
	else
	{
		return num%10 + sumDig(num/10);
		//return sum+=sumDig(num%10);
	}
}

int main()
{
	int n;
	cout<<"Enter the number:";
	cin>>n;
	cout<<"Sum of digits :"<<sumDig(n);
	return 0;
	
}
