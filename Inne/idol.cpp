#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 5;

void losuj(int tablica[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tablica[i][j] = rand() % 2; // losowanie wartoœci logicznych
		}
	}
	// uzupe³nienie przekatnej - kazdy zna samego siebie
	for (int i = 0; i < N; i++)
	{
		tablica[i][i] = 1;
	}

	// 50% szans na wygenerowanie tablicy z idolem
	if (rand() % 2 == 1)
	{
		int idol = rand() % N;
		for (int i = 0; i < N; i++)
		{
			tablica[idol][i] = 0;
		}
		for (int i = 0; i < N; i++)
		{
			tablica[i][idol] = 1;
		}
	}
}

void wypisz(int tablica[][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << tablica[i][j] << " ";
		}
		cout << endl;
	}
}

bool czyIdol(int znajomosci[][N])
{
	// zlozonosc O(N^2) ?
	// tablica zawiera informacje na temat znajomosci 
	// znajomosc[i][j] == true	osoba i zna osobê j
	// znajomosc[j][i] == true	osoba j zna osobê i
	// funkcja zwraca informacje czy zbior ma idola
	// osobe ktora zna kazdy i ktora nie zna nikogo

	// szukanie potencjalnego idola
	// osoby ktora nie zna nikogo
	int idol = -1;
	for (int i = 0; i < N; i++)
	{
		int suma = 0;
		for (int j = 0; j < N; j++)
		{
			suma += znajomosci[i][j];
		}
		if (suma == 1)
		{
			idol = i;
			break;
		}
	}

	// czy pierwsze sprawdzenie wskaza³o potencjalnego idola
	bool czyIdol = (idol != -1);
	
	// sprawdzanie czy potencjalny kandydat jest idolem
	// czy kazdy go zna
	for (int i = 0; i < N; i++)
	{
		if (znajomosci[i][idol] != 1)
		{
			czyIdol = false;
			break;
		}
	}

	if (czyIdol)
	{
		cout << "Idol: indeks " << idol << endl;
	}

	return czyIdol;
}

int idol(int znajomosci[][N])
{
	// znajduje idola w tablicy znajomosci
	// zlozonosc O(n)
	// funkcja zwraca -1 jeœli w tablicy nie ma idola
	// jeœli jest, funkcja zwraca indeks idola

	int kandydat = 0;
	int i = 1;

	// Ka¿da iteracja pêtli wyklucza jedn¹ osobê jako kandydata na lidera
	while (i < N)
	{
		if (znajomosci[kandydat][i])
			kandydat = i;
		i++;
	}

	// sprawdzenie 1
	znajomosci[kandydat][kandydat] = false;
	i = 0;
	while (i < N)
	{
		if (znajomosci[kandydat][i])
			return -1;
		else
			i++;
	}

	// sprawdzenie 2
	znajomosci[kandydat][kandydat] = true;
	i = 0;
	while (i < N)
	{
		if (!znajomosci[i][kandydat])
			return -1;
		else
			i++;
	}

	// jeœli funkcja do tej pory nie zwróci³a -1
	// to mamy pewnoœæ ¿e kandydat jest idolem
	return kandydat;
}

int main()
{
	srand(time(NULL));
	int znajomosci[N][N];
	losuj(znajomosci);
	wypisz(znajomosci);

	/*
	if (czyIdol(znajomosci))
	{
		cout << "Grupa posiada idola";
	}
	else
	{
		cout << "Grupa nie posiada idola";
	}
	*/

	cout << "Idol: " << idol(znajomosci);

	return 0;
}
