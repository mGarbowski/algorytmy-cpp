#include <iostream>

using namespace std;

const float EPSILON = 0.0001;

float squareRoot(float num)
{
    float low = 0;
    float high = num;
    float mid = (low + high) / 2;

    while (abs(mid*mid - num) > EPSILON)
    {
        if (mid*mid > num)
        {
            high = mid;
        }
        else
        {
            low = mid;
        }

        mid = (low + high) / 2;
    }

    return mid;
}


int main()
{
    float num;
    cout << "Podaj liczbe: ";
    cin >> num;
    cout << "sqrt(" << num << ") = " << squareRoot(num) << endl;

    return 0;
}