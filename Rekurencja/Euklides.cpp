// Euklides.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int NWDrek(int a, int b)
// Algorytm euklidesa na znajdywanie NWD dwóch liczb naturalnych rekurencyjnie
{
	if (a == b)
		return a;
	if (a > b)
		return NWDrek(a - b, b);
	else
		return NWDrek(a, b - a);
}

int NWDrek2(int a, int b)
// Algorytm euklidesa na znajdywanie NWD dwóch liczb naturalnych rekurencyjnie
// Dzielenie modulo zamiast odejmowania - mniej operacji
// Na koñcu wartoœæ jednej ze zmiennych wynosi 0 a druga NWD
{
	if (a * b == 0) // któraœ równa 0
		return a + b;
	if (a > b)
		return NWDrek2(a % b, b);
	else
		return NWDrek2(a, b % a);
}

int main()
{
	int a, b;
	cout << "a = ";
	cin >> a;

	cout << "b = ";
	cin >> b;

	cout << "NWD = " << NWDrek2(a, b);

	return 0;
}


