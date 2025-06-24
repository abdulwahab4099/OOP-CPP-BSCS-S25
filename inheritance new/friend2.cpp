// Add members of two different classes using friend functions

#include <iostream>
//using namespace std;
//
//// forward declaration
//class ClassB;
//
//class ClassA {
//	private:
//        int numA;
//    
//    public:
//        // constructor to initialize numA to 12
//        ClassA() : numA(12) {}
//        
//    
//        
//         // friend function declaration
//         friend int add(ClassA, ClassB);
//};
//
//class ClassB {
//	private:
//        int numB;
//
//    public:
//        // constructor to initialize numB to 1
//        ClassB() : numB(1) {}
//    
//    
// 
//        // friend function declaration
//        friend int add(ClassA, ClassB);
//};
//
//// access members of both classes
//int add(ClassA objectA, ClassB objectB) {
//    return (objectA.numA + objectB.numB);
//}
//
//int main() {
//    ClassA objectA;
//    ClassB objectB;
//    cout << "Sum: " << add(objectA, objectB);
//    return 0;
//}


using namespace std;

class B;

class A{
	private:
		int numA;
		
	public:
		A(): numA(15) {
			
		}
		
	friend add(A, B);
};

class B{
	private:
		int numB;
		
	public:
		B(): numB(35) {
			
		}
		
	friend add(A, B);
};

add(A obj1, B obj2){
	return obj1.numA + obj2.numB;
}

int main()
{
	A a;
	B b;
	cout<<"Sum: "<<add(a,b);
	return 0;
}
