// In line Function:  
//A function is used to reduce code redundancy as well as to save the memory space. When a function is invoked a bunch of task is performed.
//When a function is declared inline, the function body is replicated at function calling place.


#include <iostream>
#include <conio.h>
using namespace std;
inline int square(int a);
inline int cube(int a);

// to make a function inline use keyword inline before the function.
inline int square(int a)
{
	return a*a;
}
inline int cube(int a)
{
	return a*a*a;
}
int main()
{
	cout<<"\nSquare of 5 = "<<square(5);
	cout<<"\nCube of 5 = "<<cube(5);
}
