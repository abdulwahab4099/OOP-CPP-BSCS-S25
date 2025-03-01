/*
Dynamic 2D Arrays in C++
In C++, a dynamic 2D array is allocated on the heap instead of the stack. 
Unlike static 2D arrays (int arr[rows][cols]), dynamic 2D arrays allow flexible memory allocation.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int rows=3, cols=4;
    
    
    // Creating an array of pointers (each pointing to a row)
    int **arr=new int*[rows];

    // Allocating memory for each row
    for(int i=0; i<rows; i++) 
	{
        arr[i]=new int[cols];
    }

    // Initializing values
    for (int i=0; i<rows; i++) 
	{
        for (int j=0; j<cols; j++) 
		{
            arr[i][j] = i*cols+j;
        }
    }

    // Printing values
    for (int i=0; i<rows; i++) 
	{
        for (int j=0; j<cols; j++) 
		{
            cout<<arr[i][j]<< " ";
        }
        cout<<endl;
    }

    // Deallocate memory
    for (int i=0; i<rows; i++) 
	{
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

