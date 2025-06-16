#include <iostream>
#include <stdexcept>
#include <cstdlib>
using namespace std;

int safeSubtract(int a, int b)
{
    int result = a - b;
    if (result < 0)
    {
        throw std::underflow_error("Result is negative");
    }
    return result;
}

int main()
{
    int a, b;
    cout << "Enter two integers: ";
    cin >> a >> b;

    try
    {
        try
        {
            int result = safeSubtract(a, b);
            cout << "Result: " << result << endl;
        }
        catch (const std::underflow_error &e)
        {
            cout << "Underflow error: " << e.what() << endl;
            cout << "Returning |a - b| instead: " << abs(a - b) << endl;
        }
    }
    catch (const std::exception &e)
    {
        cout << "An unexpected error occurred: " << e.what() << endl;
    }

    return 0;
}