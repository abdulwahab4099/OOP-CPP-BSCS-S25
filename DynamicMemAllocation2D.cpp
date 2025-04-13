#include <iostream>
#include <new>

using namespace std;
int main()
{
	int n,m;
	int *ptr1=new int[4];
	int *ptr2=new int[4];
	int *ptr3=new int[4];
	int *ptr4=new int[4];
	int *ptr5=new int[4];
	
	// the above is not a very good method of using pointers cuz it can make our code bulky.
	//*ptr => single dimensional pointer
	//**ptr => double dimensional pointer
	//***ptr => three dimensional pointer
	
	cout<<"\nNumber of rows(one dimensional arrays):";
	cin>>n;
	cout<<"Number of columns(indexes in arrays):";
	cin>>m;
//	
	int **ptr=new int* [n];
	for (int i=0; i<n; i++)
	{
		ptr[i]=new int[m];
	}
//	
	for (int i=0; i<n; i++)
	{
		for(int j=0; j<m; j++)
		{
			cout<<"\nValue at row "<<i+1<<" and column "<<j+1<<" :";
			cin>>ptr[i][j];
		}
		
	}
//	
	for(int i=0; i<n; i++)
	{
		for (int j=0; j<m; j++)
		{
			cout<<"\nValue at row "<<i+1<<" and column "<<j+1<<" : " <<ptr[i][j];
		}
	}
//	delete [] ptr;
	
	for (int i=0;i<n;i++)
	{
		delete [] ptr[i];
	}
//	//	
	return 0;
 }
