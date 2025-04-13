/*
 Task 4: Static Members with Simplification
 Create a C++ class Duration to represent time in hours and minutes.
 • Data Members: int hours, int minutes (private), static int
 totalDurations (tracks total objects).
 • Requirements:
 1. Default constructor: Sets hours and minutes to 0.
 2. Parameterized constructor: Takes hours and minutes, simplifies
 minutes (e.g., 75 minutes becomes 1 hour, 15 minutes).
 3. Private utility function: simplify() to keep minutes ¡ 60 (called
 in constructors).
*/

#include <iostream>
using namespace std;
class duration
{
	int hours,minutes;
	static int totDuration;
	public:
		duration()
		{
			hours=0;
			minutes=0;
		}
		
		duration(int h, int m)
		{
			if(m>=60)
			{
				hours=h;
				hours+=m/60;
				minutes=m%60;
				
			}
			else
			{
				hours=h;
				minutes=m;
			}
			
			totDuration++;
			int total = simplify();
			cout<<"Total di=uration in minutes:"<<total<<endl;
		}
	private:
		int simplify()
		{
			return minutes+(hours*60);
		}
	
	
	public:
		void display()
		{
			cout<<"Hours:"<<hours<<endl;
			cout<<"Minutes:"<<minutes<<endl;
		}
	void showTotDuration()
	{
		cout<<"Total duration is:"<<totDuration<<endl;
	}
	
	
};

int duration:: totDuration=0;

int main()
{
	duration d1(2,130);
	duration d2(1,230);
	d1.display();
	d2.display();
	
	d1.showTotDuration();
	
	
	return 0;
}