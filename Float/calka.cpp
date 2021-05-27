#include <iostream>
#include <cmath>

using namespace std;


float f(float x)
{
	return sin(x);
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

float integrate2(float low, float high, int howMany)
{
	// Pola trapezow
	float area = 0;
	float dx = (high - low) / howMany;
	float x = low;
	float vertex1 = f(x);
	float vertex2 = f(x + dx);
	
	for (int i = 0; i < howMany; i++)
	{
		x += dx;
		vertex2 = f(x);
		area += (f(vertex1) + f(vertex2)) * dx / 2;
		vertex1 = vertex2;	
	}
	
	return area;
}

int main()
{
	float low;
	float high;
	int howMany;
	
	cout << "Dolna granica: ";
	cin >> low;
	cout << "Gorna granica: ";
	cin >> high;
	cout << "Ile prostokatow: ";
	cin >> howMany;
	
	cout << "Pole pod sin(x) od " << low << " do " << high <<":" << endl;
	cout << "Metoda 1: " << integrate(low, high, howMany) << endl;
	cout << "Metoda 2: " << integrate2(low, high, howMany) << endl;
	
	return 0;
}
