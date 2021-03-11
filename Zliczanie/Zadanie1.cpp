#include <iostream>
#include <string>

using namespace std;

void zadanie1()
{
	int i;

	int input;
	cout << "Podaj liczbe: ";
	cin >> input;

	//przypisanie wartosci poczatkowych 0
	int wystapienia[10];
	for (i = 0; i < 10; i++)
	{
		wystapienia[i] = 0;
	}

	//zliczenie wystapien poszczegolnych cyfr
	int cyfra;
	while (input != 0)
	{
		cyfra = input % 10;
		wystapienia[cyfra]++;
		input = input / 10;
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