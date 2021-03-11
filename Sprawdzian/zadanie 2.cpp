// Miko³aj Garbowski 2e
// zadanie 2

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <math.h>

using namespace std;

const int podstawa = 7;
const int n = 20;
const int nCyfr = 3;

void Losuj(int tablica[])
{
	for (int i = 0; i < n; i++)
	{
		int liczba = 0;
		// najbardziej znacz¹ca cyfra ró¿na od zera
		int cyfra = pow(10, nCyfr - 1) * (1 + (rand() % (podstawa - 1)));
		liczba += cyfra;

		int exp = nCyfr - 2;
		while (exp >= 0)
		{
			cyfra = pow(10, exp) * (rand() % podstawa);
			liczba += cyfra;
			exp--;
		}

		tablica[i] = liczba;
	}
}


void Wypisz(int tablica[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << tablica[i] << " ";
	}
	cout << endl;
}


void WypiszLiczniki(int liczniki[])
{
	for (int i = 0; i < podstawa; i++) 
	{
		cout << "Cyfr " << i << ": " << liczniki[i] << endl;
	}
}
void LiczCyfry(int tablica[], int liczniki[])
{
	for (int i = 0; i < n; i++)
	{
		int liczba = tablica[i];
		while (liczba > 0)
		{
			int cyfra = liczba % 10;
			liczniki[cyfra]++;
			liczba = liczba / 10;
		}
	}
}


void ZerujLiczniki(int liczniki[])
{
	for (int i = 0; i < podstawa; i++)
	{
		liczniki[i] = 0;
	}
}


int main()
{
	srand(time(NULL));
	int tablica[n];
	Losuj(tablica);
	cout << "Tablica: \n";
	Wypisz(tablica, n);

	int liczniki[podstawa];
	ZerujLiczniki(liczniki);

	LiczCyfry(tablica, liczniki);
	cout << "\nLiczniki: \n";
	WypiszLiczniki(liczniki);

	return 0;
}

