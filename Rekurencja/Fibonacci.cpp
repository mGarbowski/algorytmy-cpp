#include <iostream>

using namespace std;

int fib(int n)
// Z³o¿onoœæ wyk³adnicza
{
	// Zwraca n-t¹ liczbê ci¹gu Fibonacciego

	// Przypadki bazowe
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;

	// Przypadek rekurencyjny
	return fib(n - 1) + fib(n - 2);
}


int fibIter(int n) 
// Z³o¿onoœæ O(n)
{
	int a = 1;
	int b = 1;
	int temp;

	for (int i = 3; i <= n; i++)
	{
		temp = b;
		b = a + b;
		a = temp;
	}

	return b;
}

int main()
{
	int n;
	cout << "Ktora liczba ciagu? ";
	cin >> n;
	cout << "Iteracyjnie: " << fibIter(n) << endl;
	cout << "Rekurencyjnie: " << fib(n) << endl;

	return 0;
}