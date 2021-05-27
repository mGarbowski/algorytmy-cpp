#include <iostream>
#include <cmath>

using namespace std;

float f(float x)
{
    // 2 * polkole nad osia x o promieniu 1
    return 2 * sqrt(1 - x*x);
}

float integrate(float low, float high, int howMany)
{
	// Pola prostokatow
	float area = 0;
	float dx = (high - low) / howMany;
	float x = low;
	
	for (int i = 0; i < howMany; i++)
	{
		area += f(x) * dx;
		x += dx;
	}
	
	return area;
}

int main()
{
    // Pole = pi * r^2
    // dla r = 1
    // Pole = pi

    float pi = integrate(-1, 1, 1000);
    cout << "Pi = " << pi;

    return 0;
}