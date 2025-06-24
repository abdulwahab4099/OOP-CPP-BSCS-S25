//Define New Exceptions

#include <iostream>
#include <exception>
using namespace std;

struct MyException : public exception {
   const char * what () const throw () {
      return "attempted to divide by zero";
   }
};
 
int main() {
   try { 
       int x,y;
       cout<<"enter two numbers";
       cin>>x>>y;
       if (y==0){
	   
   		MyException z;
     	 throw z;}
     	else
     	{
     		cout<<"x/y="<<x/y<<endl;
		 }
      	
   } catch(exception& e) {
      //cout << "MyException caught" <<endl;
      cout << e.what() <<endl;//what() is a public method provided by exception class and it 
	  								//has been overridden by all the child exception classes. 
									//This returns the cause of an exception.
   } 
}
