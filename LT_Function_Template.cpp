/*
Lab Task
Function Template
*/
#include <iostream>
#include <new>
#include <string>
#include <cstring>
using namespace std;
template <class T>
T swapValues(T n1, T n2)
{
	T temp;
	temp=n1;
	n1=n2;
	n2=temp;
	cout<<"First variable has:"<<n1<<endl;
	cout<<"Second variable has:"<<n2<<endl;
	
}
int main()
{
	cout<<swapValues<int>(3,7)<<endl;
	cout<<swapValues<char>('A','Z')<<endl;
	cout<<swapValues<float>(6.764,653.76432)<<endl;
	return 0;
	
}
