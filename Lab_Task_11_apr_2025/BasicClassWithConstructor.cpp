/*
Task 1: Basic Class with Constructors
 Design a C++ class Counter to represent a simple counter.
 • Data Member: int count (non-negative, public for simplicity).
 • Requirements:
 1. Default constructor: Initializes count to 0.
 2. Parameterized constructor: Takes an integer parameter to initial
ize count (set to 0 if negative).
 3. Constant memberfunction: display() to print the value of count.
 • Question: Implement the class and test it by creating two objects:
 one with the default constructor and one with the parameterized con
structor. Display their counts using display().
*/
#include <iostream>
using namespace std;
class Counter
{
	int count;
	public:
		
		Counter() //Constructor
		{
			count=0;
		}
		
		Counter(int a)//Parameterized Constructor
		{
			if(a<0)
			{
				a=0;
			}
			else
			{
				count=a;
			//	count++;
			}
			
		}
	void increment() 
	{
		count++;
	}
	void display() const
	{
		//count++;
		cout<<"Value of counter:"<<count<<endl;
	}

};

int main()
{
	Counter c1;
	Counter c(0);
	c.increment();
	c.display();
	c.increment();
	c.display();
	return 0;
}