/*
Task 2: Class with Copy Constructor
 Create a C++ class Book to represent a book’s page count.
 • Data Member: int pages (public for simplicity).
 • Requirements:
 1. Default constructor: Sets pages to 100.
 2. Parameterized constructor: Takes an integer to initialize pages
 (minimum 1).
 3. Copy constructor: Creates a copy of another Book object.
 4. Constant member function: showPages() to print pages.
 • Question: Implement the class and test it by creating an object with
 the parameterized constructor, copying it using the copy constructor,
 and displaying the page counts using showPages().
*/

#include <iostream>
using namespace std;
class book
{
	public:
	int pages;
	public:
		book()
		{
			pages=100;
		}
		book(int a)
		{
		 	pages=a;
		}
		
	void showPages() const
	{
		cout<<"Number of pages are:"<<pages<<endl;
	}
	
};

int main()
{
	book b1(250);
	book b2(b1);
	b1.showPages();
	b2.showPages();
}