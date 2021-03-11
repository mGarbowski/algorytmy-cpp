#include <iostream>
#include <string>

using namespace std;

void zadanie3()
{
	int wystapienia[10];
	int input = 1;
	int cyfra;
	int i;
	int liczba;

	//przypisanie wartosci poczatkowych 0
	for (i = 0; i < 10; i++)
	{
		wystapienia[i] = 0;
	}

	while (input != 0)
	{
		cout << "Podaj liczbe: ";
		cin >> input;
		liczba = input;
		while (liczba != 0)
		{
			cyfra = liczba % 10;
			wystapienia[cyfra]++;
			liczba = liczba / 10;
		}
	}

	//wypisanie wyniku
	for (i = 0; i < 10; i++)
	{
		if (wystapienia[i] != 0)
		{
			cout << i << ": " << wystapienia[i] << endl;
		}
	}
}