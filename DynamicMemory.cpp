#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int* pNum = NULL;
	pNum= new int;
	*pNum= 21;
	cout<<"Address:" << pNum<<endl;
	cout<<"Value:" << *pNum<<endl;
	
	delete pNum;
	return 0;
}
