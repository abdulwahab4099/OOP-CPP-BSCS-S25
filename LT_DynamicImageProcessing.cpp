
/*
 Image Processing with Dynamic 2D Arrays

 Background: You are developing a simple image processing tool. Images are represented as 2D arrays
 of pixel values (0-255 for grayscale).
 
 Task:
 1. Ask the user to input the dimensions (rows and columns) of the image.
 2. Dynamically allocate a 2D array to represent the image.
 3. Populate the array with random pixel values (0-255).
 4. Implement the following operations:
	 • Flip the image horizontally (swap rows).
	 • Convert the image to its negative (subtract each pixel value from 255).
	 • Crop the image (ask the user for new dimensions and resize the array).
 5. Display the original and processed images (print the 2D arrays).
 6. Deallocate the memory after use.
 
 Real-world connection: This scenario mimics basic image processing tasks, such as flipping, crop
 ping, and applying filters, which are common in graphics software.
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	int rows,columns;

	cout<<"Enter the number of rows for the image:";
	cin>>rows;
	cout<<"\nEnter the number of columns for image:";
	cin>>columns;
	
	int** image=new int*[rows];
	for(int i=0;i<rows;i++)
	{
		image[i]=new int[columns];
	}
	
	//Populate the array with random pixel values
	bool check;
	cout<<"\nEnter random pixel values (0-255):";
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			do
			{
				check=false;
				cout<<"\nEnter value at row "<<i+1<<" and column "<<j+1<<" :";
				
				cin>>image[i][j];
				if(image[i][j]<0 || image[i][j]>255)
				{
					check=true;
					cout<<"\nValue must be between 0 and 255!";
				}
			}while(check);
		}
	}
	
	//Storing original image
	int** originalImage=new int*[rows];
	
	for(int i=0;i<rows;i++)
	{
		originalImage[i]=new int[columns];
	}
	
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			originalImage[i][j]=image[i][j];
		}
	}
	
	/*
	srand(time(0)); // Seed for random numbers
	for (int i = 0; i < rows; i++) 
	{
	    for (int j = 0; j < columns; j++) 
		{
	        image[i][j] = rand() % 256;  // Random values between 0 and 255
	    }
	}
	*/
	char ch;
	/*
	4. Implement the following operations:
	 • Flip the image horizontally (swap rows).
	 • Convert the image to its negative (subtract each pixel value from 255).
	 • Crop the image (ask the user for new dimensions and resize the array).
 5. Display the original and processed images (print the 2D arrays).
	*/
	do
	{
		cout<<"\n======================================================\n";
		cout<<"\nImage Processing Menu \n\n";
		cout<<"\n======================================================\n";
		cout<<"F - Flip the image horizontally.\n";
		cout<<"N - Convert the image to its negative.\n";
		cout<<"C - Crop the image.\n";
		cout<<"D - Display the original and processed images.\n";
		cout<<"E - Exit the program.\n";
		cout<<"\n======================================================\n";
		cout<<"\nEnter your choice :";
		cin>>ch;
		ch=tolower(ch);
		
		
		
		if(ch=='f')
		{
			for(int i=0; i<rows/2;i++)
			{
				for(int j=0;j<columns;j++)
				{
					int temp=image[i][j];
					image[i][j]=image[rows-1-i][j];
					image[rows-1-i][j]=temp;
				}
			}
			cout<<"\nImage flipped horizontally!";
		}
		else if(ch=='n')
		{
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<columns;j++)
				{
					image[i][j]=255-image[i][j];
				}
			}
			cout<<"\nImage converted to negative!";
		}
		else if(ch=='c')
		{
			int nRows, nColumns;
			cout<<"\nEnter new number of rows:";
			cin>>nRows;
			cout<<"\nEnter new number of columns:";
			cin>>nColumns;
			if(nRows>rows || nColumns>columns)
			{
				cout<<"\nCrop size must be smaller than the original image.";

			}
			else
			{
				int**croppedImage=new int*[nRows];
				
				for(int i=0; i<nRows; i++)
				{
					croppedImage[i]=new int[nColumns];
				}
				
				for(int i=0;i<nRows;i++)
				{
					for(int j=0;j<nColumns;j++)
					{
						croppedImage[i][j]=image[i][j];
					}
				}
				
				for(int i=0; i<rows;i++)
				{
					delete[] image[i];
				}
				delete[] image;
				
				image=croppedImage;
				rows=nRows;
				columns=nColumns;
				
				cout<<"\nImage cropped successfully!";
			}
					
		}
		else if(ch=='d')
		{
			int n;
			cout<<"\n1- Un-processed image.";
			cout<<"\n2- Processed image.\n";
			cin>>n;
			if(n==1)
			{
				for(int i=0;i<rows;i++)
				{
					for(int j=0;j<columns;j++)
					{
						cout<<originalImage[i][j]<<"\t";
					}
					cout<<"\n";
				}
			}
			else if(n==2)
			{
				for(int i=0;i<rows;i++)
				{
					for(int j=0;j<columns;j++)
					{
						cout<<image[i][j]<<"\t";
					}
					cout<<"\n";
				}
			}
		}
		else if(ch=='e')
		{
			cout<<"\nExiting...";
		}
		else
		{
			cout<<"\nInvalid choice! Try again.";	
		}
			
	}while(ch!='e');
	
	cout<<"\nProgram terminated.";
	//Deleting pointer storing original image
	for(int i=0;i<rows;i++)
	{
		delete[] originalImage[i];
	}
	delete[] originalImage;
	originalImage=NULL;
	//Deleting main pointer
	for(int i=0;i<rows;i++)
	{
		delete[] image[i];
	}
	delete[] image;
	image=NULL;
	
	return 0;
}
