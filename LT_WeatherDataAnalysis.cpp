/*
 Lab Task

 Weather Data Analysis (2D Dynamic Array)
 
 Background: You are working on a program to analyze weather data for a city. The data is collected
 daily for a month, and you need to store and process it.
 
 Task:
 1. Ask the user to input the number of days in the month (e.g., 28, 30, or 31).
 2. Dynamically allocate a 2D array to store the temperature data for each day 
 	(rows = days, columns= 3 for min, max, and average temperature).
 3. Populate the array with user-provided temperature data.
 4. Perform the following analysis:
	 � Find the hottest and coldest day of the month.
	 � Calculate the monthly average temperature.
	 � Display the temperature trends (e.g., days with increasing max temperature).
 5. Deallocate the memory after use.
 
 Real-world connection: This scenario simulates real-world weather data analysis, where data is
 stored in a tabular format and processed for insights
*/




#include <iostream>
#include<new>
using namespace std;
int main()
{
	int days;
	cout<<"Enter the number of days in the month (e.g., 28,29,30 or 31) : ";
	cin>>days;
	/*
	Dynamically allocate a 2D array to store the temperature data for each day 
 	(rows = days, columns= 3 for min, max, and average temperature).
	*/
	float ** temperature=new float*[days];
	for(int i=0;i<days;i++)
	{
		temperature[i]=new float[3]; //as we have 3 number of columns in each row
		
	}
	cout<<"\nEnter temperatures...\n";
	
	for(int i=0;i<days;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(j==0)
			{
				cout<<"Day "<<i+1<<" min : ";
				cin>>temperature[i][j];
			}
			if(j==1)
			{
				cout<<"Day "<<i+1<<" max : ";
				cin>>temperature[i][j];
			}
			if(j==2)
			{
				cout<<"Day "<<i+1<<" avg : ";
				cin>>temperature[i][j];
			}
			
		}
	}
	
	//Find the hottest and coldest day of the month.
	float hottest=temperature[0][1], coldest=temperature[0][0],n=0,m=0;
	for(int i=0; i<days;i++)
	{
		for (int j=1;j<2 ;j++ )
		{
			if(hottest<temperature[i][j])
			{
				hottest=temperature[i][j];
				n=i;
			}
		}
		for (int j=0;j<1 ;j++ )
		{
			if(coldest>temperature[i][j])
			{
				coldest=temperature[i][j];
				m=i;
			}
		}
	}
	cout<<"\n\nHottest temperature of the month is "<<hottest <<" at day "<<n+1<<".";
	cout<<"\nColdest temperature of the month is "<<coldest <<" at day "<<m+1<<".";
	
	//Calculate the monthly average temperature.
	float sumAvg=0,monthlyAvg=0;
	
	for(int i=0; i<days;i++)
	{
		for (int j=2;j<3 ;j++ )
		{
			sumAvg+=temperature[i][j];
		}
	}
	monthlyAvg=sumAvg/days;
	cout<<"\n\nMonthly average temperature is "<<monthlyAvg<<".";
	
	//Display the temperature trends (e.g., days with increasing max temperature).
	bool trendfound= false;
	for(int i=1;i<days;i++)
	{
		if(temperature[i][1]>temperature[i-1][1])
		{
			trendfound=true;
			cout<<"\n\nDay "<<i+1 <<" temperature "<<temperature[i][1]<<" �C > Day "<<i<<" temperature "<<temperature[i-1][1]<<" �C.";
		}
	}
	if(!trendfound)
	{
		cout<<"\nNo trend found!";
	}
	
	for(int i=0;i<days;i++)
	{
		delete[] temperature[i];
	}
	delete[] temperature;
	
	return 0;
	
}
