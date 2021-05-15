#include <iostream>

using namespace std;

double cosinus(double x)
{
    double sign = 1;
    double factorial = 1;
    double power = 1.f;
    double result = 0.f;

    for (int i = 1; i < 10; i++)
    {
        result += sign * power / factorial;

        sign = sign * -1;
        factorial = factorial * (2*i) * (2*i - 1);
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