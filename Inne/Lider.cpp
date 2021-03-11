#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

const int N = 20;

void Losuj(int tablica[])
{
	int x = rand() % 100;
	for (size_t i = 0; i < N; i++)
	{
		if (rand() % 2 == 0)
		{
			tablica[i] = x;
		}
		else
		{
			tablica[i] = rand() % 100;
		}
	}
}

void Wypisz(int tablica[])
{
	for (size_t i = 0; i < N; i++)
	{
		cout << tablica[i] << " ";
	}
	cout << endl;
}

bool czyLider(int tablica[], int& lider)
{
	// Funkcja sprawdza czy jakaœ wartoœæ
	// wystêpuje w tablicy wiêcej ni¿ 50% razy
	// i aktualizuje zmienn¹ lider jej wartoœci¹

	// Definicja zmiennych
	int wartoscAktualna = tablica[0];
	int dlugoscAktualna = 1;
	int dlugoscMax = 1;

	// Sortowanie i szukanie d³ugoœci najd³u¿szego
	// podci¹gu sk³adaj¹cego siê z tych samych wartoœci
	sort(tablica, tablica + N);
	for (size_t i = 1; i < N; i++)
	{
		if (tablica[i] == tablica[i - 1])
		{
			dlugoscAktualna++;
		}
		else
		{
			if (dlugoscAktualna > dlugoscMax)
			{
				dlugoscMax = dlugoscAktualna;
				lider = tablica[i - 1];
			}
			dlugoscAktualna = 1;
		}
	}

	// Sprawdzenie ostatniej pozycji poza pêtl¹
	if (dlugoscAktualna > dlugoscMax)
	{
		dlugoscMax = dlugoscAktualna;
		lider = tablica[N - 1];
	}

	return dlugoscMax > N / 2;
}

bool czyLider2(int tablica[], int& lider)
{
	// Funkcja sprawdza czy jakaœ wartoœæ
	// wystêpuje w tablicy wiêcej ni¿ 50% razy
	// i aktualizuje zmienn¹ lider jej wartoœci¹
	// Z³o¿onoœæ O(n*log(n))

	// Jeœli ci¹g ma lidera, to po posortowaniu
	// bêdzie dok³adnie w po³owie ci¹gu

	sort(tablica, tablica + N);
	lider = tablica[N / 2]; // Potencjalny lider

	// Sprawdzenie czy liczba jest liderem
	int wystapienia = 0;
	for (int i = 0; i < N; i++)
	{
		if (tablica[i] == lider)
		{
			wystapienia++;
		}
	}
	if (wystapienia > N / 2) // Wystêpuje wiêcej ni¿ 50% razy
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	// Wygenerowanie tablicy
	int tablica[N];
	srand(time(NULL));
	Losuj(tablica);
	Wypisz(tablica);

	int lider;
	bool maLidera = czyLider2(tablica, lider);

	if (maLidera)
	{
		cout << "Lider: " << lider;
	}
	else
	{
		cout << "Nie ma lidera.";
	}

	return 0;
}