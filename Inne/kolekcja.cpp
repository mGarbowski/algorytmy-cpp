// InfCollected.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "InfCollected.h"
using namespace std;


int NWD(int a, int b)
{
	int c;

	//algorytm na znajdowanie NWD
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}

	return a;
}

int NWW(int a, int b)
{
	return a * b / NWD(a, b);
}
/*
void NajwiekszaWCiagu()
{
	int a;
	int b;

	cout << "Podaj liczbe \n";
	cin >> a;
	if (a != 0)
	{
		do
		{
			cout << "Podaj liczbe \n";
			cin >> b;

			if (b > a)
			{
				a = b;
			}

		} while (b != 0);
	}

	cout << "Najwieksza liczba w ciagu: " << a;
}
*/


int main()
{
	int a;
	int b;

	cout << "Podaj liczbe \n";
	cin >> a;
	if (a != 0)
	{
		do
		{
			cout << "Podaj liczbe \n";
			cin >> b;

			if (b > a)
			{
				a = b;
			}

		} while (b != 0);
	}

	cout << "Najwieksza liczba w ciagu: " << a;

	return 0;
}



void NewFunction()
{
	cout << NWD(18, 24) << "\n";
	cout << NWW(18, 24);
}

void NajwiekszaWCiagu() 
{
	int a;
	int b;

	cout << "Podaj liczbe \n";
	cin >> a;
	if (a != 0)
	{
		do
		{
			cout << "Podaj liczbe \n";
			cin >> b;

			if (b > a)
			{
				a = b;
			}

		} while (b != 0);
	}

	cout << "Najwieksza liczba w ciagu: " << a;

	


}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
