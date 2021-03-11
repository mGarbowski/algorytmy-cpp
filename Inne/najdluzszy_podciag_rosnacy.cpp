#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 20;

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


int najdluzszyPodciagRosnacy(int tablica[])
{
	// Funkcja znajduje najdluzszy podciag rosnacy
	// Wypisuje ten podciag
	// Zwraca jego dlugosc

	int dlugosc = 1;
	int dlugoscMax = 1;
	int poczatek = 0;
	int poczatekMax = 0;

	// Znalezienie podciągu
	for (int i = 0; i < N; i++)
	{
		if (tablica[i + 1] > tablica[i])
		{
			dlugosc++;
			if (dlugosc > dlugoscMax)
			{
				dlugoscMax = dlugosc;
				poczatekMax = poczatek;
			}
		}
		else
		{
			dlugosc = 1;
			poczatek = i + 1;
		}
	}

	// Wypisanie najdluzszego podciagu rosnacego
	for (int i = 0; i < dlugoscMax; i++)
	{
		cout << tablica[i + poczatekMax] << " ";
	}

	// Zwrócenie długości
	return dlugoscMax;
}

int main()
{
	// Wygenerowanie i wypisanie losowej tablicy liczb całkowitych
	int tablica[N];
	srand(time(NULL));
	Losuj(tablica);

	cout << "Ciag:\n";
	Wypisz(tablica);

	cout << "\nNajdluzszy podciag rosnacy\n";
	int dlugoscMax = najdluzszyPodciagRosnacy(tablica);
	cout << "\n\nDlugosc podciagu: " << dlugoscMax;

	return 0;
}