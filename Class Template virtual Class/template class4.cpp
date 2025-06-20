 #include <conio.h>
#include <iostream>
#include <string>
#include <cstring>

//using namespace std;
//
//template <typename T> 
//class Array {
//private:
//	T* ptr;
//	int size;
//
//public:
//	Array(T arr[], int s);
//	void print();
//};
//
//template <typename T> Array<T>::Array(T arr[], int s)
//{
//	ptr = new T[s];
//	size = s;
//	for (int i = 0; i < size; i++)
//		ptr[i] = arr[i];
//}
//
//template <typename T> void Array<T>::print()
//{
//	for (int i = 0; i < size; i++)
//		cout << " " << *(ptr + i);
//	cout << endl;
//}
//
//int main()
//{
//	int arr[5] = { 1, 2, 3, 4, 5 };
//	//float arr[5] = { 1, 2, 3, 4, 5 };
//	//char arr[5] = { 1, 2, 3, 4, 5 };
//	Array<int> a(arr, 5);
//	a.print();
//	return 0;
//}

#include <iostream>
#include <cstring>
using namespace std;

template <class T>
class SimpleArray {
private:
    T* data;
    int size;

public:
    SimpleArray(T arr[], int s) {
        size = s;
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = arr[i];
        }
    }

    void print() {
        cout << "Array elements: ";
        for (int i = 0; i < size; i++) {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    ~SimpleArray() {
        delete[] data;
    }
};

int main() {
    int intArr[] = {10, 20, 30, 40, 50};
    char charArr[] = "I'm preparing for my final exams.";

    SimpleArray<int> obj(intArr, 5);
    obj.print();

    SimpleArray<char> obj1(charArr, strlen(charArr));
    obj1.print();

    return 0;
}


