/*
Dynamic Matrix Calculator (2D Dynamic Arrays)

 Background: You are building a matrix calculator for a math application. The matrices can vary in
 size, and you need to perform operations dynamically.
 
 
 Task:
 1. Ask the user to input the dimensions of two matrices.
 2. Dynamically allocate memory for both matrices.
 3. Populate the matrices with user-provided values.
 4. Implement the following operations:
	 • Matrix addition.
	 • Matrix multiplication.
	 • Transpose of a matrix.
 5. Display the results of each operation.
 6. Deallocate the memory after use.
 
 
 Real-world connection: This scenario simulates real-world matrix calculations used in engineering,
 physics, and computer graphics applications
*/


#include <iostream>
using namespace std;
//int addition(int** arr1,int** arr2, int r1, int r2, int c1, int c2);
int main()
{
	int row1,row2,column1,column2;
	cout<<"Enter the number of rows of first matrix:";
	cin>>row1;
	cout<<"\nEnter the number of columns of first matrix:";
	cin>>column1;
	
	
	int** matrix1=new int*[row1];
	
	for(int i=0;i<row1;i++)
	{
		matrix1[i]=new int[column1];
	}
	
	cout<<"\nEnter the number of rows of second matrix:";
	cin>>row2;
	cout<<"\nEnter the number of columns of second matrix:";
	cin>>column2;
	
	int** matrix2=new int*[row2];
	
	for(int i=0;i<row2;i++)
	{
		matrix2[i]=new int[column2];
	}
	
	cout<<"\nEnter the valuse for first matrix...";
	for(int i=0;i<row1;i++)
	{
		for(int j=0;j<column1;j++)
		{
			cout<<"\nEnter value in row "<<i+1<<" and column "<<j+1<<" of first matrix :";
			cin>>matrix1[i][j];
		}
	}
	
	cout<<"\nEnter the valuse for second matrix...";
	for(int i=0;i<row2;i++)
	{
		for(int j=0;j<column2;j++)
		{
			cout<<"\nEnter value in row "<<i+1<<" and column "<<j+1<<" of second matrix :";
			cin>>matrix2[i][j];
		}
	}
	
	int** result= NULL;
	
	char ch;
	do
	{
		cout<<"\n======================================================\n";
		cout<<"\nChoose one of the following options... \n\n";
		cout<<"A - Addition of matrices.\n";
		cout<<"M - Multiplication of matrices.\n";
		cout<<"T - Transpose of matrices.\n";
		cout<<"E - Exit the program.\n";
		cout<<"\n======================================================\n";
		cout<<"Enter your choice :";
		cin>>ch;
		ch=tolower(ch);
		
		if(ch=='a')
		{
			if(row1==row2 && column1==column2)
			{
				result=new int*[row1];
				for(int i=0;i<row1;i++)
				{
					result[i]=new int[column1];
				}
				
				for(int i=0;i<row1;i++)
				{
					for(int j=0;j<column1; j++)
					{
						result[i][j]=matrix1[i][j] + matrix2[i][j];
					}
				}
				
				cout<<"\nResultant matrix(Addition):\n";
				for(int i=0;i<row1;i++)
				{
					for(int j=0;j<column1; j++)
					{
						cout<<result[i][j]<<"\t";
					}
					cout<<"\n";
				}
			}
			else
			{
				cout<<"\nAddition can not be performed.";
			}
		}
		else if(ch=='m')
		{
			if(column1==row2)
			{
				
				result=new int*[row1];
				for(int i=0;i<row1;i++)
				{
					result[i]=new int[column2]();
				}
				
				for(int i=0; i<row1;i++)
				{
					for(int j=0; j<column2;j++)
					{
						for(int k=0;k<column1;k++)
						{
							result[i][j]+= matrix1[i][k]*matrix2[k][j];
						}
					}
				}
				cout<<"\nResultant matrix(Multiplication):\n";
				for(int i=0;i<row1;i++)
				{
					for(int j=0;j<column2; j++)
					{
						cout<<result[i][j]<<"\t";
					}
					cout<<"\n";
				}
				
				
			}
			else
			{
				cout<<"\nMultiplication can not be performed.";
			}
		}
		
		else if(ch=='t')
		{
			int** transpose;
			int trows,tcols,choice;
			cout<<"\nTranspose of Matrix(1 or 2):\n";
			cin>>choice;
			
			if(choice==1)
			{
				trows=column1;
				tcols=row1;
				transpose=new int*[trows];
				for(int i=0; i<trows;i++)
				{
					transpose[i]=new int[tcols];
				}
				for(int i=0;i<row1;i++)
				{
					for(int j=0;j<column1;j++)
					{
						transpose[j][i]=matrix1[i][j];
					}
				}
			}
			else if(choice==2)
			{
				trows=column2;
				tcols=row2;
				transpose=new int*[trows];
				for(int i=0; i<trows;i++)
				{
					transpose[i]=new int[tcols];
				}
				for(int i=0;i<row2;i++)
				{
					for(int j=0;j<column2;j++)
					{
						transpose[j][i]=matrix2[i][j];
					}
				}
			}
			else
			{
				cout<<"\nInvalid input!";
				continue;
			}
			cout<<"\nResultant Matrix(Transpose):\n";
			for(int i=0;i<trows;i++)
			{
				for(int j=0;j<tcols;j++)
				{
					cout<<transpose[i][j]<<"\t";
					
				}
				cout<<"\n";
			}
			for(int i=0;i<trows;i++)
			{
				delete[] transpose[i];
			}
			delete[] transpose;
		}
		else if(ch=='e')
		{
			cout<<"\nExiting...";
		}
		else
		{
			cout<<"\nInvalid input. Try again!";
		}
		//Deleting result
		if(result!=NULL)
		{
			for(int i=0;i<row1;i++)
			{
				delete[] result[i];
			}
			delete[] result;
			result=NULL;
		}
		
	}while(ch !='e');
	/////////////////////////////////////////////////
	for(int i=0;i<row1;i++)
	{
		delete [] matrix1[i];
	}
	
	delete [] matrix1;
	/////////////////////////////////////////////////
	for(int i=0;i<row2;i++)
	{
		delete [] matrix2[i];
	}
	
	delete [] matrix2;
	
	return 0;
	
	
}

// Addtion funtion
//int addition(int** arr1,int** arr2, int r1, int r2, int c1, int c2)
//{
//	
//}
