#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 10;

void Losuj(int tablica[])
{
	for (size_t i = 0; i < N; i++)
	{
		tablica[i] = rand() % 100 - 50;
	}
	tablica[rand() % N] = rand() % 50; // conajmniej jeden element nieujemny
}

void Wypisz(int tablica[])
{
	for (size_t i = 0; i < N; i++)
	{
		cout << tablica[i] << " ";
	}
	cout << endl;
}

int naiwnyNajwiekszyPodciag(int tablica[])
{
	// sprawdzenie każdego możliwego podciągu
	// złożoność O(n^3)

	int sumaMax = 0;
	int sumaAktualna;

	for (int poczatek = 0; poczatek < N; poczatek++)
	{
		for (int koniec = poczatek; koniec < N; koniec++)
		{
			sumaAktualna = 0;
			for (int i = poczatek; i <= koniec; i++)
			{
				sumaAktualna += tablica[i];
				
			}
			if (sumaAktualna > sumaMax)
			{
				sumaMax = sumaAktualna;
			}
		}
	}
	return sumaMax;
}

int najwiekszyPodciag(int tablica[], int &poczatekMax, int &koniecMax)
{
	// złożoność liniowa O(n)
	// funkcja zwraca sumę największego podciągu
	// oraz aktualizuje parametry poczatekMax i koniecMax
	// oznaczające indeksy najwiekszego podciagu

	int sumaMax = 0;
	int sumaAktualna = 0;
	int poczatekAktualny = 0;

	for (int i = 0; i < N; i++)
	{
		if (sumaAktualna + tablica[i] > 0)
		{
			sumaAktualna += tablica[i];
			if (sumaAktualna > sumaMax)
			{
				sumaMax = sumaAktualna;
				poczatekMax = poczatekAktualny;
				koniecMax = i;
			}
		}
		else
		{
			sumaAktualna = 0;
			poczatekAktualny = i + 1;
		}
	}
	return sumaMax;
}

int main()
{
	// Wygenerowanie i wypisanie losowej tablicy liczb całkowitych
	int tablica[N];
	srand(time(NULL));
	Losuj(tablica);
	Wypisz(tablica);

	// Obliczenie i wypisanie
	int poczatek, koniec;
	cout << "Suma najwiekszego podciagu: " << najwiekszyPodciag(tablica, poczatek, koniec) << endl;

	cout << "Najwiekszy podciag: ";
	for (int i = poczatek; i <= koniec; i++)
	{
		cout << tablica[i] << " ";
	}
}