#include <iostream>
using namespace std;
int max(int list[],int num)
{
	
	if(num==0)
	{
		return list[0];
	}
	else
	{
		return 
	}
}
int main()
{
	int size;
	cout<<"Enter size of the array:";
	cin>>size;
	int arr[size]={};
	cout<<"\nEnter values in array: \n";
	for(int i=0; i<size;i++)
	{
		cout<<"\nValue at index '"<<i<<"' :";
		cin>>arr[i];
	}
	cout<<"\n[";
	for(int i=0; i<size;i++)
	{
		cout<<"\t"<<arr[i];
	}
	cout<<"]";
	
	
}
