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
	 • Find the hottest and coldest day of the month.
	 • Calculate the monthly average temperature.
	 • Display the temperature trends (e.g., days with increasing max temperature).
 5. Deallocate the memory after use.
 
 Real-world connection: This scenario simulates real-world weather data analysis, where data is
 stored in a tabular format and processed for insights
*/

#include <iostream>
#include <new>
using namespace std;

int main() 
{
    int days;
    
    // Step 1: Ask for the number of days
    cout << "Enter the number of days in the month (28, 30, or 31): ";
    cin >> days;

    // Step 2: Dynamically allocate 2D array (days x 3)
    double** temperatures = new double*[days];
    for (int i = 0; i < days; i++) 
	{
        temperatures[i] = new double[3]; // 3 columns: min, max, avg temp
    }

    // Step 3: Populate the array with user input
    cout << "Enter temperature data (Min, Max, Avg) for each day:\n";
    for (int i = 0; i < days; i++) 
	{
        cout << "Day " << i + 1 << " -> Min: ";
        cin >> temperatures[i][0];
        cout << "         Max: ";
        cin >> temperatures[i][1];
        cout << "         Avg: ";
        cin >> temperatures[i][2];
    }

    // Step 4: Analysis

    // Finding the hottest and coldest day
    int hottestDay = 0, coldestDay = 0;
    for (int i = 1; i < days; i++) 
	{
        if (temperatures[i][1] > temperatures[hottestDay][1]) 
            hottestDay = i;
        if (temperatures[i][0] < temperatures[coldestDay][0]) 
            coldestDay = i;
    }

    // Calculating monthly average temperature
    double totalAvgTemp = 0;
    for (int i = 0; i < days; i++) 
	{
        totalAvgTemp += temperatures[i][2];
    }
    double monthlyAvg = totalAvgTemp / days;

    // Identifying increasing max temperature trends
    cout << "\nDays with increasing max temperature:\n";
    for (int i = 1; i < days; i++)
	 {
        if (temperatures[i][1] > temperatures[i - 1][1]) 
		{
            cout << "Day " << i + 1 << " (Max: " << temperatures[i][1] << "°C)\n";
        }
    }

    // Display results
    cout << "\nAnalysis Results:\n";
    cout << "Hottest day: Day " << hottestDay + 1 << " (Max: " << temperatures[hottestDay][1] << "°C)\n";
    cout << "Coldest day: Day " << coldestDay + 1 << " (Min: " << temperatures[coldestDay][0] << "°C)\n";
    cout << "Monthly average temperature: " << monthlyAvg << "°C\n";

    // Step 5: Deallocate memory
    for (int i = 0; i < days; i++) 
	{
        delete[] temperatures[i]; // Delete each row
    }
    delete[] temperatures; // Delete the array pointer
    
    return 0;
}

