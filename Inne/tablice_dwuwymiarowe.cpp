#include <iostream>

using namespace std;

const int N_WIERSZY = 3;
const int N_KOLUMN = 4;

void losuj(int tablica[][N_KOLUMN])
{
	for (int i = 0; i < N_WIERSZY; i++)
	{
		for (int j = 0; j < N_KOLUMN; j++)
		{
			tablica[i][j] = 10 + rand() % 90; // losowanie liczb dwucyfrowych
		}
	}
}

void wypisz(int tablica[][N_KOLUMN])
{
	for (int i = 0; i < N_WIERSZY; i++)
	{
		for (int j = 0; j < N_KOLUMN; j++)
		{
			cout << tablica[i][j] << " ";
		}
		cout << endl;
	}
}

int max(int tablica[][N_KOLUMN])
{
	int maxWartosc = tablica[0][0];
	for (size_t i = 0; i < N_WIERSZY; i++)
	{
		for (size_t j = 0; j < N_KOLUMN; j++)
		{
			if (tablica[i][j] > maxWartosc)
			{
				maxWartosc = tablica[i][j];
			}
		}
	}
	return maxWartosc;
}

int min(int tablica[][N_KOLUMN])
{
	int minWartosc = tablica[0][0];
	for (size_t i = 0; i < N_WIERSZY; i++)
	{
		for (size_t j = 0; j < N_KOLUMN; j++)
		{
			if (tablica[i][j] < minWartosc)
			{
				minWartosc = tablica[i][j];
			}
		}
	}
	return minWartosc;
}

int main()
{
	srand(time(NULL));

	int tablica[N_WIERSZY][N_KOLUMN];
	losuj(tablica);
	wypisz(tablica);

	cout << endl << "Max: " << max(tablica);
	cout << endl << "Min: " << min(tablica);

	return 0;
}