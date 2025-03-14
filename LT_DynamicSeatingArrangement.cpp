/*
Dynamic Seating Arrangement for an Event (2D Dynamic Array)

 Background: You are organizing a conference and need to manage the seating arrangement. The
 number of attendees and seating layout can change dynamically.
 
 Task:
 1. Ask the user to input the number of rows and columns for the seating arrangement.
 2. Dynamically allocate a 2D array to represent the seating layout.
 3. Populate the array with attendee names (or IDs) as they register.
 4. Implement the following features:
	 • Add a new attendee (resize the array if needed).
	 • Remove an attendee (mark their seat as empty).
	 • Display the current seating arrangement.
	 • Find and display the location of a specific attendee.
 5. Deallocate the memory after use.
 
 Real-world connection: This scenario reflects real-world event management systems where seating
 arrangements need to be dynamically updated based on attendee registrations.
*/

#include <iostream>
#include <new>
using namespace std;
int add(int**& arr,int& row, int&column, int ID);
//int remove(int**& arr,int& row, int&column, int search);
void display(int** arr, int row, int column);
//int find(int** arr, int row, int column);


int main()
{
	int rows,columns,search;
	cout<<"Enter number of rows:";
	cin>>rows;
	cout<<"\nEnter number of columns:";
	cin>>columns;
	int** seats= new int*[rows];
	for(int i=0;i<rows;i++)
	{
		seats[i]=new int[columns]; 
	}
	
	cout<<"\nIf a seat is empty, input '-1'.";
	for(int i=0; i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			int f;
			int id;
			do
			{
				f=0;
				cout<<"\nEnter ID of attendee in row '"<<i+1<<"' and column '"<<j+1<<"' :";
				
				
				cin>>id;
				
				for(int x=0;x<rows;x++)
                {
                    for(int y=0;y<columns;y++)
                    {
                        if(seats[x][y]==id)
                        {
                            f++;
                            cout<<"\nAttendee's' ID already exists. Please enter a unique ID.\n";
                            break;
                        }
                        if(id==0)
                        {
                        	f++;
							cout<<"\nAttendee's ID can't be '0'. Please enter a non-zero ID.";
                        	break;
						}
                    }
                    if (f) 
						break;
            	}
			}while(f);
			seats[i][j]=id;
			
		}
	}
	
	char ch;
	do
	{
		cout<<"\n======================================================\n";
		cout<<"\nChoose one of the following options... \n\n";
		cout<<"A - Add a new attendee (resize the array if needed).\n";
		cout<<"R - Remove an attendee (mark their seat as empty).\n";
		cout<<"D - Display the current seating arrangement.\n";
		cout<<"F - Find and display the location of a specific attendee.\n";
		cout<<"E - Exit the program.\n";
		cout<<"\n======================================================\n";
		cout<<"Enter your choice :";
		cin>>ch;
		ch=tolower(ch);
		
		switch(ch)
		{
			case 'a':
				{
					//Calling add Function
					int Id;
					int found;
					
					do
					{
						found=0;
						cout<<"\nEnter ID of new attendee :";
						
						cin>>Id;
						for(int x=0;x<rows;x++)
		                {
		                    for(int y=0;y<columns;y++)
		                    {
		                        if(seats[x][y]==Id)
		                        {
		                            found++;
		                            cout<<"\nAttendee ID already exists. Please enter a unique ID.\n";
		                            break;
		                        }
		                    }
		                    if (found) 
								break;
		            	}
					}while(found);
					
					add(seats,rows,columns,Id);
					break;
				}
			case 'r':
				{
					//Calling Remove function
					
					cout<<"\nEnter the Id you want to remove:";
					cin>>search;
					for (int i=0;i<rows;i++)
					{
						for(int j=0;j<columns;j++)
						{
							if(search==seats[i][j])
							{
								//remove(seats,rows,columns,search);
								seats[i][j]=-1;
							}
							else
							{
								cout<<"\nAttendee with ID '"<<search<<"' not found.";
							}
						}
					}
					
					
					break;
				}
			case 'd':
				{
					//Calling Display Function.
					display(seats,rows,columns);
					break;
				}
			case 'f':
				{
					//Calling find function.
					cout<<"\nEnter the ID of the attendee:";
					cin>>search;
					bool f1=false;
					for (int i=0;i<rows;i++)
					{
						for(int j=0;j<columns;j++)
						{
							if(search==seats[i][j])
							{
								cout<<"\nAttendee with ID '"<<search<<"' found in the row '"<<i+1<<"'and column '"<<j+1<<"'.";
								f1=true;
							}
						}
					}
					if(!f1)
					{
						cout<<"\nAttendee with ID '"<<search<<"' not found.";
					}
					break;
				}
				
			case 'e':
				{
					cout<<"\nExiting...";
					break;
				}
			default:
				{
					cout<<"\nInvalid input. Please try again!";
					break;
				}
			
		}
	}while(ch !='e');
	for(int i=0;i<rows;i++)
	{
		delete[] seats[i];
	}
	delete[] seats;
	return 0;
}

//Display Function.
void display(int** arr, int row, int column)
{
	for(int i=0; i<row;i++)
	{
		for(int j=0; j<column;j++)
		{
			if(arr[i][j]!=-1)
			{
				cout<<"\nAttendee with ID '"<<arr[i][j]<<"' is sitting in row '"<<i+1<<"' and column '"<<j+1<<"' .";
			}
			
		}
	}
	
}

// Add function
int add(int**& arr,int& row, int&column, int ID)
{
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			if(arr[i][j]==-1)
			{
				arr[i][j]=ID;
				return 1;
			}
		}
		
	}
	
	
	int** newSeats=new int*[row+1];
	
	for(int i=0;i<row+1;i++)
	{
		newSeats[i]=new int[column];
	}
	
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<column;j++)
		{
			newSeats[i][j]=arr[i][j];
		}
		
	}
	
	for(int j=0;j<column;j++)
	{
		newSeats[row][j]=-1;// marking empty
	}
	
	newSeats[row][0]=ID;
	
	for(int i=0;i<row;i++)
	{
		delete[] arr[i];
	}
	delete[] arr;
	
	arr=newSeats;
	
	row++;
	return 1;
	
	
}

//Remove Function
//int remove(int**& arr,int& row, int&column, int search)
//{
//	for (int i=0;i<row;i++)
//					{
//						for(int j=0;j<columns;j++)
//						{
//							if(search==arr[i][j])
//							{
//								arr[i][j]=-1;
//								return 1;
//							}
//						}
//					}
//}
