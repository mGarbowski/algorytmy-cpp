#include <iostream>

using namespace std;

double cosinus(double x)
{
    int sign = 1;
    int factorial = 1;
    double power = 1.f;
    double result = 0.f;

    for (int i = 0; i < 10; i++)
    {
        result += sign * power / factorial;

        sign = sign * -1;
        factorial = factorial * (2*i+1) * (2*i+2);
        power = power * x * x;
    }

    return result;
}

int main()
{
    double x;
    cout << "x = ";
    cin >> x;
    cout << x;
    cout << "cos(x) = " << cosinus(x) << endl;

    return 0;
}