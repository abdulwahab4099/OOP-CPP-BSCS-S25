/*
The point-to-point concept generally refers to direct connections between memory locations using pointers. 
In C++, this applies when dynamically allocating and managing arrays using pointers.
*/
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a = 10;
	int *ptr1 = &a;  // Pointer to an integer
	int **ptr2 = &ptr1;  // Pointer to a pointer
	
	cout<<a<<endl;
	cout<<&a<<endl;
	cout<<ptr1<<endl;
	cout<<ptr2<<endl;
	cout<<*ptr1<<endl;
	cout<<*ptr2<<endl;
	cout<<**ptr2<<endl;
	
	return 0;
}
