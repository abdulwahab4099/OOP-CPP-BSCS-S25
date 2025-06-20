#include<iostream>
using namespace std;
class think{
	private:
		int m,n;
	public:
		think(int u=1, int v=2): m(u), n(v) {}
	int getM() const {return m;}
	int getN() const {return n;}
};

class Point {
private:
	int x;
	int y;
public:
	Point(int i = 0, int j = 0):x(i), y(j) {}
	/* The above use of Initializer list is optional as the
		constructor can also be written as:
		Point(int i = 0, int j = 0) {
			x = i;
			y = j;
		}
	*/
	
	int getX() const {return x;}
	int getY() const {return y;}
};

int main() {
think t1(20,40);
Point t2(10, 15);

cout<<"m= "<<t1.getM()<<", ";
cout<<"n= "<<t1.getN()<<", ";
cout<<"x = "<<t2.getX()<<", ";
cout<<"y = "<<t2.getY();
return 0;
}

/* OUTPUT:
x = 10, y = 15
*/

