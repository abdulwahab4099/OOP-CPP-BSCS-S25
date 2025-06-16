#include <iostream>
using namespace std;
double divide(int a, int b)
{
    if (b == 0)
    {
        throw "Error: Division by zero!";
    }
    return static_cast<double>(a) / b;
}
int main()
{
    int a, b;
    cout << "Enter two integers (a b): ";
    cin >> a >> b;
    try
    {
        double result = divide(a, b);
        cout << "Result: " << result << endl;
    }
    catch (const char *e)
    {
        cout << e << endl;
        if ((b + 1) == 0)
        {
            cout << "Fallback failed: (b + 1) is zero. Cannot divide." << endl;
        }
        else
        {
            double fallbackResult = divide(a, b + 1);
            cout << "Fallback Result (using b + 1): " << fallbackResult << endl;
        }
    }
    return 0;
}