// Miko³aj Garbowski 2e
// zadanie 1

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int n = 20;


void Losuj(int tablica[])
{
	for (int i = 0; i < n; i++)
	{
		tablica[i] = rand();
	}
}


void Wypisz(int tablica[])
{
	for (int i = 0; i < n; i++)
	{
		cout << tablica[i] << " ";
	}
	cout << endl;
}


int LiczPodzielne(int tablica[], int dzielnik)
{
	int podzielne = 0;
	for (int i = 0; i < n; i++)
	{
		if (tablica[i] % dzielnik == 0)
		{
			podzielne++;
		}
	}
	return podzielne;
}

int main()
{
	int dzielnik = 5;

	srand(time(NULL));
	int tablica[n];
	Losuj(tablica);

	cout << "Tablica: \n";
	Wypisz(tablica);
	cout << "\nPodzielnych przez " << dzielnik << ": " << LiczPodzielne(tablica, dzielnik);

	return 0;
}
