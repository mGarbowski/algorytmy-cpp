#include <iostream>
#include <string>

using namespace std;

void zadanie2()
{
	int najwieksza = 0;
	int liczba = 1;

	while (liczba != 0)
	{
		cout << "Podaj liczbe: ";
		cin >> liczba;
		cout << endl;
		if (liczba > najwieksza)
		{
			najwieksza = liczba;
		}
	}
	cout << "Najwieksza z podanych liczb: " << najwieksza;
}