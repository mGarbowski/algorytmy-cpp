#include <iostream>

using namespace std;
const float EPSILON = 0.001;

float cube(float x)
{
    return x * x * x;
}

float cubeRoot(float x)
{
    float low = 0;
    float high = x;
    float mid = (low + high) / 2;

    while (abs(cube(mid) - x) > EPSILON
        && abs(high - low) > EPSILON)
    {
        if (cube(mid) > x)
            high = mid;
        else
            low = mid;

        mid = (low + high) / 2;
    }

    return mid;
}

int main()
{
    float x;
    cout << "x = ";
    cin >> x;
    cout << "Pierwiastek 3 stopnia z x wynosi: " << cubeRoot(x);
    
    return 0;
}