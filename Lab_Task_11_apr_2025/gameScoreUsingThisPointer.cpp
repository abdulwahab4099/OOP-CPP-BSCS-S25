/*
Task 3: Using this Pointer
 Design a C++ class Score to manage a game score.
 • Data Member: int points (public for simplicity).
 • Requirements:
 1. Parameterized constructor: Takes an integer parameter points
 and uses the this pointer to initialize points (non-negative).
 2. Member function: addPoints( points) to add to the existing
 points using this (ensure non-negative).
 3. Constant member function: printScore() to display points.
 • Question: Implement the class and test it by creating an object,
 adding points using addPoints, and displaying the result with printScore().
 Explain how this is used.
*/

#include <iostream>
using namespace std;
class score
{
	public:
		int points;
	
	public:
		score()
		{
			points=0;
		}
		
		score(int a)
		{
			if(a=>0)
			{
				points=a;
			}
		}
};
