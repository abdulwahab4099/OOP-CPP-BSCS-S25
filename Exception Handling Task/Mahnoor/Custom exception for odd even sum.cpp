#include <iostream>
#include <cmath>
#include <stdexcept>
using namespace std;
class OddNumberException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Odd numbers not allowed!";
    }
};
int sumEvenNumbers(int a, int b)
{
    if (a % 2 != 0 || b % 2 != 0)
    {
        throw OddNumberException();
    }
    return a + b;
}

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    try
    {
        int sum = sumEvenNumbers(a, b);
        cout << "Sum of even numbers: " << sum << endl;
    }
    catch (const OddNumberException &e)
    {
        cout << "Exception caught: " << e.what() << endl;
        cout << "Sum of absolute values: " << abs(a) + abs(b) << endl;
    }

    return 0;
}