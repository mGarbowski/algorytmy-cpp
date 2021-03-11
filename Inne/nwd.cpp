#include <iostream>

using namespace std;




int AlgorytmEuklidesa(int a, int b)
{
	while (a != b)
	{
		if (a > b)
		{
			a = a - b;
		}
		else if (b > a)
		{
			b = b - a;
		}
	}
	
	return a;
}

int Alogrytm2(int a, int b)
{
	while (a * b > 0)
	{
		if (a > b)
		{
			a = a % b;
		}
		else if (b > a)
		{
			b = b % a;
		}
	}
	
	return a + b;
}
