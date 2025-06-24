//Define New Exceptions

#include <iostream>
#include <exception>
using namespace std;

struct MyException : public exception {
   const char * what () const throw () {
      return "C++ Exception";
   }
};
 
int main() {
   try {
      throw MyException();
   } catch(MyException& e) {
      cout << "MyException caught" <<endl;
      cout << e.what() <<endl;//what() is a public method provided by exception class and it 
	  								//has been overridden by all the child exception classes. 
									//This returns the cause of an exception.
   } catch(exception& e) {
      //Other errors
      //cout<<"\nokey";
   }
}
