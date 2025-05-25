#include <string>
#include <iostream>
using namespace std;

const int Max_courses=6;
/*8. Virtual Base Class (Advanced)
• Create a base class Person and inherit it virtually into the
 User class to prevent ambiguity in multiple inheritance.*/
class Person
{
	protected:
		string name;
	public:
		Person(string n):name(n){}
};
/*1. User Class Hierarchy
• Create a base class User with the attributes: name, id, and a pure virtual
function displayInfo().
• Create derived classes Student and Professor with their specific attributes.
• Override the displayInfo() function in both derived classes.*/
class User:virtual public Person
{
	protected:
		int id;
		static int totalUsers; /*3. Static Members and Functions
		• Use static variables to keep count 
		of total users and implement getTotalUsers().*/
	public:
		User(string n,int i):Person(n),id(i)
		{
			totalUsers++;
		}
		virtual void displayInfo() const=0;
		virtual void calculatePerformance() const=0;/*7. Virtual and Abstract Functions
• Declare a pure virtual function calculatePerformance() in the User class.
• Implement it in Student and Professor classes differently.*/
		static int getTotalUsers()
		{
			return totalUsers;
		}
};
int User::totalUsers=0;

/*5. Course Class with Operator Overloading
• Define a Course class and overload the == and << operators.*/
class Course
{
	private:
		string courseName;
	public:
		Course(string n=""):courseName(n){}
		string getName() const
		{
			return courseName;
		}
		bool operator==(const Course& other) const
		{
			return courseName==other.courseName;
		}
		friend ostream& operator<<(ostream& os,const Course& c)
		{
			os<<"\nCourse: "<<c.courseName;
			return os;
		}
		friend class Student;
};

class Student:public User
{
	private:
		string Department;
		int Semester;
		double GPA;
		Course courses[Max_courses];
		int courseCount;
	public:
		Student(string n,int i,string d,int s,double g):Person(n),User(n,i),Department(d),Semester(s),GPA(g),courseCount(0){}
		void displayInfo() const
		{
			cout<<"\nStudent Name: "<<name; 
			cout<<"\nID: "<<id;
			cout<<"\nDepartment: "<<Department;
			cout<<"\nSemester: "<<Semester;
			cout<<"\nGPA: "<<GPA;
            for (int i=0;i<courseCount;i++) 
		    {
                cout<<courses[i];
            }
		}
		void calculatePerformance() const
		{
			cout<<"\nStudent Performance: "<<(GPA>3.0?"Excellent":"Average");
		}
		friend void assignCourse(Student&,Course&);
};

/*2. Friend Function Usage
• Implement a friend function assignCourse(Student&, Course&) that as-
signs a course to a student and accesses private members.*/
void assignCourse(Student& s,Course& c)
{
	if(s.courseCount<Max_courses)
	{
		s.courses[s.courseCount++]=c;
		cout<<"Assigned "<<c.getName()<<" course to: "<<s.name<<endl;
	}
	else
	{
		cout<<"\nCourse limit reached for student: "<<s.name;
	}
}

class Professor:public User
{
	private:
		string Department;
	public:
		Professor(string n,int i,string d):Person(n),User(n,i),Department(d){}
		void displayInfo() const
		{
			cout<<"\nProfessor Name: "<<name; 
			cout<<"\nID: "<<id;
			cout<<"\nDepartment: "<<Department;
		}
		void calculatePerformance() const
		{
			cout<<"\nProfessor ranking: Based on publications";
		}
};

/*4. Template-Based GPA Calculator
• Create a template class Calculator<T> that overloads arithmetic operators
and includes a recursive GPA calculation method.*/
template <typename T>
class Calculator
{
	private:
		T grades[Max_courses];
		int count;
	public:
		Calculator():count(0){}
		void addGrade(T grade)
		{
			if(count<Max_courses)
			{
				grades[count++]=grade;
			}
		}
		T recursiveGPA(int index=0)
		{
			if (index==count)
			{
				return T();
			}
			else
			{
				return grades[index]+recursiveGPA(index+1);
		    }
		}
		T calculateGPA()
		{
			if (count==0)
			{
				return 0;
			}
			else
			{
			    return recursiveGPA()/count;
			}
		}
		Calculator& operator+(T value) 
		{
            addGrade(value);
            return *this;
        }
};

/*6. Recursive Functions
• Write a recursive function sumOfDigits(int) to calculate the digit sum of a
number.
• Write a recursive function power(float base, int exp) to calculate ex-
ponential values using divide and conquer strategy.*/
int sumOfDigits(int n)
{
	if (n<10)
	{
		return n;
	}
	else
	{
		return n%10 + sumOfDigits(n/10);
	}
} 

float power(float base,int exp)
{
	if (exp==0)
	{
		return 1;
	}
	else if(exp%2==0)
	{
		return power(base,exp/2)*power(base,exp/2) ;
	}
	else
	{
		return base*power(base,exp-1);
	}
} 

/*Bonus Task (Optional)
Develop a professor ranking system using recursive sorting and template functions for nu-
meric score types.*/
template <typename T>
void recursiveSort(T arr[],int n)
{
	if (n<=1)
	{
		return;
	}
	else
	{
		for(int i=0;i<n-1;i++)
		{
			if (arr[i]<arr[i+1])
			{
				swap(arr[i],arr[i+1]);
			}
		}
		recursiveSort(arr,n-1);
	}
}

//Main function
int main()
{
	Student s1("Ali",32,"CS",2,3.3);
	Professor p1("Ahmed",57,"CS");
	Course c1("OOP"),c2("Maths"),c3("Physics");
	assignCourse(s1,c1);
	assignCourse(s1,c2);
	assignCourse(s1,c3);
	// Display info
    cout<<"\n--- Display Info ---";
    s1.displayInfo();  cout<<endl;
    p1.displayInfo();

    // Performance calculation
    cout<<"\n\n--- Performance ---";
    s1.calculatePerformance();
    p1.calculatePerformance();

    // GPA Calculator
    cout<<"\n\n--- GPA Calculator ---\n";
    Calculator<float> calc;
    calc + 3.0 + 3.3 + 3.6;
    cout<<"Calculated GPA: "<<calc.calculateGPA()<<endl;

    // Static user count
    cout<<"\nTotal Users: "<<User::getTotalUsers()<<endl;

    // Recursive functions
    cout<<"\n--- Recursive Functions ---\n";
    cout<<"Sum of digits (1234): "<<sumOfDigits(1234)<<endl;
    cout<<"Power (2, 5): "<<power(2,5)<<endl;

    // Bonus: Professor ranking (descending sort of scores)
    cout<<"\n--- Professor Ranking ---";
    float scores[5]={88.5, 92.0, 79.5, 85.0, 90.0};
    recursiveSort(scores,5);
    for (int i=0;i<5;i++) 
	{
        cout<<"\nScore "<<i+1<<": "<<scores[i];
    }
    return 0;
}
