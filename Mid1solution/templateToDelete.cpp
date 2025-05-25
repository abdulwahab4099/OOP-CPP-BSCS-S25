/*
Write a function template that will delete a particular element in a given array of size 10. Also display the array 
before and after deletion from the array. Also call the function in main as well. 
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

template <class T>
void delfunc(T arr1[],int &b, T c);


int main()
{
	int size=10;
	int arr[size]={1,2,3,4,5,6,7,8,9,10};
	cout<<"Original Array:\n";
	for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<"\t";
	}
	int a;
	cout<<"\nEnter the element you want to delete:";
	
	cin>>a;
	delfunc(arr,size,a);
	
	
	cout<<"\nProgram end!";
}
template <class T>
void  delfunc(T arr1[],int &b, T c)
{
	int k;
	bool found=false;
	for(int i=0;i<b;i++)
	{
		if(c==arr1[i])
		{
			cout<<"\nElement found in the array, will be deleted now.";
			found=true;
			k=i;
			//break;
		}
	}
	if(!found)
	{
		cout<<"\nElement not found in the array.\nDeletion can not be performed.\n";
		
	}
	if(found)
	{
		for(int j=k;j<b;j++)
			{
				arr1[j]=arr1[j+1];
			}
		b--;
		
		for(int j=0;j<b;j++)
		{
			cout<<"\n"<<arr1[j]<<"\t";
		}
	}
	
	//arr1[b-1]==;
	
	
}
