#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	//opening file
	ofstream fout;
	fout.open("zoom.txt"); //Create file if does not exist already
	fout<<"Hello Quaidians!";
	fout.close(); //releases the resources handling file
}
